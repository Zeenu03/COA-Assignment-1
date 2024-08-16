#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

vector<long long> fibonacci_tabulation(int n) {
    vector<long long> fib(n + 1);
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    return fib;
}

int main() {
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    long long elapsed_time_ns;
    double elapsed_time_s;
    int n = 50;
    // Loop with Tabulation
    
    vector<long long> fib_tab = fibonacci_tabulation(n);
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed_time_ns = (end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec);
    elapsed_time_s = elapsed_time_ns / 1e9;
    cout << "Time taken (loop with tabulation): " << elapsed_time_s << " seconds and "
              << elapsed_time_ns << " nanoseconds." << endl;
    return 0;
}
