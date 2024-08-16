#include <iostream>
#include <vector>
#include <ctime>
#include <random>

using namespace std;

vector<vector<int>> matrix_multiply(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int N = A.size();
    vector<vector<int>> result(N, vector<int>(N, 0));
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return result;
}

vector<vector<int>> generate_matrix(int N) {
    vector<vector<int>> matrix(N, vector<int>(N));
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 9);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            matrix[i][j] = dis(gen);
        }
    }
    return matrix;
}

long long calculate_elapsed_time_ns(timespec start, timespec end) {
    long long start_ns = start.tv_sec * 1000000000LL + start.tv_nsec;
    long long end_ns = end.tv_sec * 1000000000LL + end.tv_nsec;
    return end_ns - start_ns;
}

int main() {
    vector<int> sizes = {64, 128, 256, 512, 1024};

    for (int N : sizes) {
        // Generate two NxN matrices
        struct timespec start, end;
        clock_gettime(CLOCK_MONOTONIC, &start);
        auto A = generate_matrix(N);
        auto B = generate_matrix(N);
        
        vector<vector<int>> result = matrix_multiply(A, B);
        clock_gettime(CLOCK_MONOTONIC, &end);

        long long elapsed_time_ns = calculate_elapsed_time_ns(start, end);
        long double elapsed_time_s = elapsed_time_ns / 1e9;

        cout << "Size " << 512 << "x" << 512 << ":" << endl;
        cout << "  Time taken = " << elapsed_time_ns << " nanoseconds" << endl;
        cout << endl;
    }

    return 0;
}
