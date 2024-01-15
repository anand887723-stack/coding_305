#include <iostream>
#include <thread>
#include <mutex>
#include <string>
using namespace std;


mutex carlock;

void drivecar(string name)
{
    unique_lock<mutex>  carlocked (carlock);
    cout << name << " is driving " << endl;
    this_thread::sleep_for(chrono::seconds(2));
    cout << name << " has completed driving" << endl;
    carlocked.unlock();
}

int main()
{

    thread ananddrive(drivecar, "Anand ");
    thread prakashdrive(drivecar, "Prakash ");

    // so this is to join two threads, so that it is joined with the main function

    ananddrive.join();
    prakashdrive.join();

    return 0;
}

// this is to run the code in ubuntu terminal

// g++ - std = c++ 11 - o sum_threaded sum_thread.cpp - lpthread


// now see both the functions are calling the mutex lock, but once
//  one function is called, it completes till end then after any 
//  thread starts touching that function
