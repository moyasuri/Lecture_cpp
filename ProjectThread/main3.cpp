#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;
int a = 0;

void someFunction() {
    mtx.lock();
    // 공유 데이터에 대한 안전한 작업 수행
    for (int i = 0; i < 10; i++)
        std::cout << "a " << a++ << std::endl;
    a *= 2;
    mtx.unlock();
}

int main() {
    std::thread t1(someFunction);
    std::thread t2(someFunction);
    std::thread t3(someFunction);
    std::thread t4(someFunction);
    //for (int i = 0; i < 1500000; i++) {

    //}
    mtx.lock();
    std::cout << "abcdfadf" << "aefasdf" << std::endl;
    mtx.unlock();
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    return 0;
}