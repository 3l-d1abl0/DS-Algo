using namespace std;
#include <iostream>
#include <string>
#include <thread>
#include <mutex>

std::mutex mtx;

void oddAndEven(int n, int end);

int main()
{
std::thread odd(oddAndEven, 1, 10);
std::thread Even(oddAndEven, 2, 10);

odd.join();
Even.join();

return 0;
}



void oddAndEven(int n, int end){
int x = n;
for (; x < end;){
    mtx.lock();
    std::cout << n << " - " << x << endl;
    x += 2;
    mtx.unlock();
    std::this_thread::yield();
    continue;
 }
}
