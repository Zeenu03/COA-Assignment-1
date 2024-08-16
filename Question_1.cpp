#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

long long fibonacci_recursive(int n) {
    if (n <= 1) return n;
    long long prev1 = fibonacci_recursive(n - 1);
    long long prev2 = fibonacci_recursive(n - 2);
    return prev1 + prev2;
}

long long fibonacci_loop(int n) {
    if (n <= 1) return n;

    long long curr = 1, prev = 0, temp;

    for (int i = 2; i <= n; i++) {
        temp = curr;
        curr = curr + prev;
        prev = temp;
    }

    return curr;
}

long long fibonacci_memoization(int n, std::vector<long long>& dp) {
    if (n <= 1) return n;
    if (dp[n] != -1) return dp[n];

    dp[n] = fibonacci_memoization(n - 1, dp) + fibonacci_memoization(n - 2, dp);
    return dp[n];
}

std::vector<long long> fibonacci_tabulation(int n) {
    std::vector<long long> fib(n + 1);
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    return fib;
}

int main() {
    struct timespec start, end;
    long long elapsed_time_ns;
    double elapsed_time_s;
    int n = 50;

    // Recursion
    clock_gettime(CLOCK_REALTIME, &start);
    for(int i = 1; i <=50; i++){
        fibonacci_recursive(i);
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed_time_ns = (end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec);
    elapsed_time_s = elapsed_time_ns / 1e9;
    std::cout << "Time taken (recursion): " << elapsed_time_s << " seconds and "
              << elapsed_time_ns << " nanoseconds." << std::endl;
    //Loop
    clock_gettime(CLOCK_MONOTONIC, &start);
    fibonacci_loop(n);
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed_time_ns = (end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec);
    elapsed_time_s = elapsed_time_ns / 1e9;
    std::cout << "Time taken (loop): " << elapsed_time_s << " seconds and "
              << elapsed_time_ns << " nanoseconds." << std::endl;

    // Recursion with Memoization
    std::vector<long long> dp(n + 1, -1);
    clock_gettime(CLOCK_MONOTONIC, &start);
    fibonacci_memoization(n, dp);
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed_time_ns = (end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec);
    elapsed_time_s = elapsed_time_ns / 1e9;
    std::cout << "Time taken (recursion with memoization): " << elapsed_time_s << " seconds and "
              << elapsed_time_ns << " nanoseconds." << std::endl;

    // Loop with Tabulation
    clock_gettime(CLOCK_MONOTONIC, &start);
    std::vector<long long> fib_tab = fibonacci_tabulation(n);
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed_time_ns = (end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec);
    elapsed_time_s = elapsed_time_ns / 1e9;
    std::cout << "Time taken (loop with tabulation): " << elapsed_time_s << " seconds and "
              << elapsed_time_ns << " nanoseconds." << std::endl;
    return 0;
}
