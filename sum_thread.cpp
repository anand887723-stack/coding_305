#include <iostream>
#include <thread>
#include <mutex>
mutex mymutex;
using namespace std;
// Function to calculate the sum of even numbers

long long int findeven(long long start, long long end)
{

    unique_lock<mutex> lock1(mymutex)
    long long localSum = 0;
    for (long long i = start; i <= end; i += 2)
    {
        cout << "even" << endl;
        localSum += i;
    }
   

    // Lock the mutex before updating the shared sum variable
    // std::lock_guard<std::mutex> lock(mtx);
    return localSum;
}

// Function to calculate the sum of odd numbers
long long int findodd(long long start, long long end)
{
    long long localSum = 0;
    for (long long i = start + 1; i <= end; i += 2)
    {
        cout << "odd" << endl;
        localSum += i;
    }

    // Lock the mutex before updating the shared sum variable
    // std::lock_guard<std::mutex> lock(mtx);
    return localSum;
}

int main()
{
    const long long N = 1e4;

    long long sum = 0; // Shared sum variable

    // Create two threads for even and odd calculations

    // so in the thread, we have to pass the functions 
    // and those threads will run those functions 
    thread evenThread(findeven, 2, N);
    thread oddThread(findodd, 1, N);

    // so this is to join two threads, so that it is joined with the main function 

    evenThread.join();
    oddThread.join();

    // Join the threads to wait for their completion
    long long int oddsum = findodd(1, N);
    long long int evensum = findeven(1, N);

    // Output the final sum
    std::cout << "Sum of all numbers from 1 to 1e18: " << oddsum + evensum << std::endl;

    return 0;
}

// g++ - std = c++ 11 - o sum_threaded sum_thread.cpp - lpthread
