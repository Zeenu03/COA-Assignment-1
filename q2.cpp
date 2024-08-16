#include <iostream>
#include <vector>
#include <ctime>
#include <random>

using namespace std;

// Function to multiply two matrices
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

// Function to generate a matrix with random integers
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

// Function to calculate the time difference in nanoseconds
long long calculate_elapsed_time_ns(timespec start, timespec end) {
    long long start_ns = start.tv_sec * 1000000000LL + start.tv_nsec;
    long long end_ns = end.tv_sec * 1000000000LL + end.tv_nsec;
    return end_ns - start_ns;
}

int main() {
    vector<int> sizes = {64, 128, 256, 512, 1024};
    
    
        // Generate two NxN matrices
        auto A = generate_matrix(1024);
        auto B = generate_matrix(1024);

        // Measure time taken for multiplication
        timespec start, end;
        clock_gettime(CLOCK_MONOTONIC, &start);
        vector<vector<int>> result = matrix_multiply(A, B);
        clock_gettime(CLOCK_MONOTONIC, &end);

        // Calculate elapsed time
        long long elapsed_time_ns = calculate_elapsed_time_ns(start, end);
        long double elapsed_time_s = elapsed_time_ns / 1e9;

        // // Print results
        // cout << "Size " << 512 << "x" << 512 << ":" << endl;
        // cout << "  Time taken = " << fixed << elapsed_time_ns << " nanoseconds" << endl;
        cout << elapsed_time_s<< endl;
        // cout << endl;
    

    return 0;
}

/*
Size 64x64:
  Time taken = 2830809 nanoseconds
  Time taken = 0.002831 seconds

Size 128x128:
  Time taken = 39973344 nanoseconds
  Time taken = 0.039973 seconds

Size 256x256:
  Time taken = 263375848 nanoseconds
  Time taken = 0.263376 seconds

Size 512x512:
  Time taken = 1661189520 nanoseconds
  Time taken = 1.661190 seconds

Size 1024x1024:
  Time taken = 20418670837 nanoseconds
  Time taken = 20.418671 seconds


Size 64x64:
  Time taken = 4732609 nanoseconds
  Time taken = 0.004733 seconds

Size 128x128:
  Time taken = 57146503 nanoseconds
  Time taken = 0.057147 seconds

Size 256x256:
  Time taken = 523779528 nanoseconds
  Time taken = 0.523780 seconds

Size 512x512:
  Time taken = 4089445731 nanoseconds
  Time taken = 4.089446 seconds

Size 1024x1024:
  Time taken = 16686725166 nanoseconds
  Time taken = 16.686725 seconds


Size 64x64:
  Time taken = 4916620 nanoseconds
  Time taken = 0.004917 seconds

Size 128x128:
  Time taken = 32785836 nanoseconds
  Time taken = 0.032786 seconds

Size 256x256:
  Time taken = 236895113 nanoseconds
  Time taken = 0.236895 seconds

Size 512x512:
  Time taken = 2289794932 nanoseconds
  Time taken = 2.289795 seconds

Size 1024x1024:
  Time taken = 16036046443 nanoseconds
  Time taken = 16.036046 seconds

*/

/*

*/

