#include <iostream>

// Write a C++ program which takes a number as a command line input
// parameter and writes ”Hello world < input number >” in standard output.

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cout << "Usage: " << argv[0] << " <number>" << std::endl;
    return 1;
  }

  int number = std::stoi(argv[1]);
  std::cout << "Hello world " << number << std::endl;
  return 0;
}