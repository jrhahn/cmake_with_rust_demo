#include <iostream>

#ifndef CMAKE_MACRO_EXAMPLE
  #define CMAKE_MACRO_EXAMPLE "No System Name"
#endif

#include "rust_lib.h"


auto sum(int a, int b) {
  return a + b;
}

int main() {
  std::cout << "hello world -> " << sum(40, 2) << std::endl;
  std::cout << CMAKE_MACRO_EXAMPLE << std::endl;
  export_fun();
  return 0;
}
