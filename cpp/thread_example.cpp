//
//  main.cpp
//  test
//
//  Created by Hari Prabhakaran on 2/20/13.
//  Copyright (c) 2013 Hari Prabhakaran. All rights reserved.
//

#include <iostream>
#include <utility>
#include <thread>
#include <chrono>
#include <functional>
#include <atomic>
#include <vector>
#include <mutex>
#include <time.h>

std::mutex mutx;
static int num=0;

void f1(int n)
{
    for(int i=0; i<1; ++i) {
        mutx.lock();
        std::cout << "Thread " << n << " Entering\n";
        mutx.unlock();
        
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        
        mutx.lock();
        num++;
        std::cout << "Thread " << n << " Exiting\n";
        mutx.unlock();
    }
}

void f2(int& n)
{
    for(int i=0; i<5; ++i) {
        std::cout << "Thread 2 executing\n";
        ++n;
        std::this_thread::sleep_for(std::chrono::milliseconds(4000));
    }
}

int main()
{
    unsigned long int startTime,endTime;
    startTime=clock();
    std::vector<std::thread *> threadLoop;
    //std::thread t1; // t1 is not a thread
    //std::thread t2(f1, n+1); // pass by value
    //std::thread t3(f2, std::ref(n)); // pass by reference
    //std::thread t4(std::move(t3)); // t4 is now running f2(). t3 is no longer a thread
    //t2.join();
    //t4.join();
    for(int i=0;i<100;i++){
        threadLoop.push_back(new std::thread(f1,i));
        //threadLoop[i]->joinable();
    }
    for(int i=0;i<100;i++){
        threadLoop[i]->join();
    }
    for(int i=0;i<100;i++){
        delete threadLoop[i];
    }
     
    endTime=clock();
    std::cout <<"Final value of num is: "<< num <<" TimeTaken:"<<double(endTime-startTime)/CLOCKS_PER_SEC<<'\n';
}
