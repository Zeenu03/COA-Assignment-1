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



int main() {
    struct timespec start, end;
    clock_gettime(CLOCK_REALTIME, &start);
    long long elapsed_time_ns;
    double elapsed_time_s;
    int n = 50;

    // Recursion
    
    for(int i = 1; i <=50; i++){
        fibonacci_recursive(i);
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed_time_ns = (end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec);
    elapsed_time_s = elapsed_time_ns / 1e9;
    std::cout << "Time taken (recursion): " << elapsed_time_s << " seconds and "
              << elapsed_time_ns << " nanoseconds." << std::endl;
    return 0;
}
