#include <chrono>
#include <iostream>
#include <thread>
int main()
{
   auto before = std::chrono::steady_clock::now();
   std::this_thread::sleep_for(std::chrono::seconds(1));
   auto after = std::chrono::steady_clock::now();

   std::cout << after.time_since_epoch().count() << std::endl;

   std::chrono::steady_clock::duration d = after - before;
   std::cout << d.count() << std::endl;

   std::chrono::duration<double, std::milli> d1 = after - before;
   std::cout << d1.count() << std::endl;
   
   
   //std::cout << std::chrono::system_clock::now().time_since_epoch().count() << std::endl;
}