#include <iostream>
#include <vector>
#include <time.h>

using namespace std;



long long fibonacci_memoization(int n, vector<long long>& dp) {
    if (n <= 1) return n;
    if (dp[n] != -1) return dp[n];

    dp[n] = fibonacci_memoization(n - 1, dp) + fibonacci_memoization(n - 2, dp);
    return dp[n];
}


int main() {
    struct timespec start, end;
     clock_gettime(CLOCK_MONOTONIC, &start);
    long long elapsed_time_ns;
    double elapsed_time_s;
    int n = 50;
    // Recursion with Memoization
    
   
    vector<long long> dp(n + 1, -1);
    fibonacci_memoization(n, dp);
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed_time_ns = (end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec);
    elapsed_time_s = elapsed_time_ns / 1e9;
    cout << "Time taken (recursion with memoization): " << elapsed_time_s << " seconds and "
              << elapsed_time_ns << " nanoseconds." << endl;

    return 0;
}
