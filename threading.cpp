#include <iostream>
#include <thread>
#include <mutex>

using namespace std;
// Function to calculate the sum of even numbers
void findeven(long long start, long long end) {
    long long localSum = 0;
    for (long long i = start; i <= end; i += 2) {
        localSum += i;
    }

    // Lock the mutex before updating the shared sum variable
    // std::lock_guard<std::mutex> lock(mtx);
    sum += localSum;
}

// Function to calculate the sum of odd numbers
void findodd(long long start, long long end) {
    long long localSum = 0;
    for (long long i = start + 1; i <= end; i += 2) {
        localSum += i;
    }

    // Lock the mutex before updating the shared sum variable
    // std::lock_guard<std::mutex> lock(mtx);
    sum += localSum;
}

int main() {
    const long long N = 1e18;

    long long sum = 0; // Shared sum variable


    // Create two threads for even and odd calculations
    thread evenThread(findeven, 2, N);
    thread oddThread(findodd, 1, N);


    evenThread.join();
    oddThread.join();

    // Join the threads to wait for their completion
    long long int oddsum = findodd( 1,N);
    long long int evensum = findeven ( 1,N);


    // Output the final sum
    std::cout << "Sum of all numbers from 1 to 1e18: " << oddsum+ evensum << std::endl;

    return 0;
}

g++ - std = c++ 11 - o sum_threaded threaded.cpp - lpthread
