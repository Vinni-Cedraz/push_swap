#include <random>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <string>
#include <algorithm>
#include <thread>
#include <vector>
#include <iostream>

void execute_push_swap(std::vector<int> argv) {
  // Convert vector<int> to char* const* for execve
  char** c_argv = new char*[argv.size() + 1];
  for (std::vector<int>::size_type i = 0; i < argv.size(); ++i) {
    c_argv[i] = new char[std::to_string(argv[i]).length() + 1];
    strcpy(c_argv[i], std::to_string(argv[i]).c_str());
  }
  c_argv[argv.size()] = nullptr;

  execve("./push_swap", c_argv, nullptr);

  for (std::vector<int>::size_type i = 0; i < argv.size(); ++i) {
    delete[] c_argv[i];
  }
  delete[] c_argv;
}

int main() {
  std::vector<int> arr(100);
  std::iota(arr.begin(), arr.end(), 1);
  std::mt19937 gen(std::random_device{}());
  std::shuffle(arr.begin(), arr.end(), gen);
  std::vector<std::thread> threads;
  for (std::vector<int>::size_type i = 0; i < 100; i += 10) {
    std::vector<int> args(arr.begin() + i, arr.begin() + i + 10);
    threads.emplace_back(execute_push_swap, args);
  }
  for (auto& thread : threads) {
    thread.join();
  }
  return 0;
}
