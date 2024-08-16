#include <iostream>
#include <vector>
#include <ctime>
#include <random>

using namespace std;

// Function to multiply two matrices
vector<vector<double>> matrix_multiply(const vector<vector<double>>& A, const vector<vector<double>>& B) {
    int N = A.size();
    vector<vector<double>> result(N, vector<double>(N, 0.0));
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return result;
}

// Function to generate a matrix with random floating-point numbers
vector<vector<double>> generate_matrix(int N) {
    vector<vector<double>> matrix(N, vector<double>(N));
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0.0, 10.0);

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
  
        struct timespec start, end;
        vector<int> sizes = {64, 128, 256, 512, 1024};
        for(int N : sizes){
          clock_gettime(CLOCK_MONOTONIC, &start);
          auto A = generate_matrix(N);
          auto B = generate_matrix(N);

          auto result = matrix_multiply(A, B);

          clock_gettime(CLOCK_MONOTONIC, &end);

          long long elapsed_time_ns = calculate_elapsed_time_ns(start, end);
          long double elapsed_time_s = elapsed_time_ns / 1e9;

          cout << "Size " << N << "x" << N << ":" << endl;
          cout << "  Time taken = " << elapsed_time_ns << " nanoseconds" << endl;
          cout << endl;
   
    }
    return 0;
}
