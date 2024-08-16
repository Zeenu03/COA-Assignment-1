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
  
    

        // Generate two NxN matrices
        auto A = generate_matrix(1024);
        auto B = generate_matrix(1024);

        // Measure time taken for multiplication
        timespec start, end;
        clock_gettime(CLOCK_MONOTONIC, &start);

        auto result = matrix_multiply(A, B);

        clock_gettime(CLOCK_MONOTONIC, &end);

        // Calculate elapsed time
        long long elapsed_time_ns = calculate_elapsed_time_ns(start, end);
        long double elapsed_time_s = elapsed_time_ns / 1e9;

        // Print results
        // cout << "Size " << 1024 << "x" << 1024 << ":" << endl;
        // cout << "  Time taken = " << elapsed_time_ns << " nanoseconds" << endl;
        cout <<elapsed_time_s<< endl;
        // cout << endl;
   

    return 0;
}
/*
Size 64x64:
  Time taken = 3479460 nanoseconds
  Time taken = 0.00347946 seconds

Size 128x128:
  Time taken = 27893698 nanoseconds
  Time taken = 0.0278937 seconds

Size 256x256:
  Time taken = 248471434 nanoseconds
  Time taken = 0.248471 seconds

Size 512x512:
  Time taken = 2538954512 nanoseconds
  Time taken = 2.53895 seconds

Size 1024x1024:
  Time taken = 22380539108 nanoseconds
  Time taken = 22.3805 seconds


Size 64x64:
  Time taken = 3488710 nanoseconds
  Time taken = 0.00348871 seconds

Size 128x128:
  Time taken = 32668488 nanoseconds
  Time taken = 0.0326685 seconds

Size 256x256:
  Time taken = 304887671 nanoseconds
  Time taken = 0.304888 seconds

Size 512x512:
  Time taken = 3313693244 nanoseconds
  Time taken = 3.31369 seconds

Size 1024x1024:
  Time taken = 21567400369 nanoseconds
  Time taken = 21.5674 seconds

Size 64x64:
  Time taken = 3712570 nanoseconds
  Time taken = 0.00371257 seconds

Size 128x128:
  Time taken = 27597928 nanoseconds
  Time taken = 0.0275979 seconds

Size 256x256:
  Time taken = 229279646 nanoseconds
  Time taken = 0.22928 seconds

Size 512x512:
  Time taken = 2165607926 nanoseconds
  Time taken = 2.16561 seconds

Size 1024x1024:
  Time taken = 18317831911 nanoseconds
  Time taken = 18.3178 seconds

*/