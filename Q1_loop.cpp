#include <iostream>
#include <vector>
#include <time.h>

using namespace std;


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



int main() {
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    long long elapsed_time_ns;
    double elapsed_time_s;
    int n = 50;


    //Loop
    
    for(int i = 1; i <=50; i++){
        fibonacci_loop(i);
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed_time_ns = (end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec);
    elapsed_time_s = elapsed_time_ns / 1e9;
    std::cout << "Time taken (loop): " << elapsed_time_s << " seconds and "
              << elapsed_time_ns << " nanoseconds." << std::endl;


    return 0;
}
