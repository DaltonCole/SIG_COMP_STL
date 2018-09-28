// put_money manipulator example
#include <iostream>     // std::cout
#include <iomanip>      // std::put_money

int main ()
{
  std::cout << "Price:" << std::put_money(10.50L) << '\n';
  return 0;
}