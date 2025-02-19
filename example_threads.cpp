#include <iostream>
#include <thread>
#include <chrono>

void thread_function1() {
    for (int i = 0; i < 5; ++i) {
        std::cout << "Thread 1: " << i << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

void thread_function2() {
    for (int i = 0; i < 5; ++i) {
        std::cout << "Thread 2: " << i << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(750));
    }
}

extern "C" {
    void run_threads() {
        std::thread t1(thread_function1);
        std::thread t2(thread_function2);

        t1.join();
        t2.join();
    }
}