#include <string.h>
#include <random>
#include <algorithm>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <iostream>
#include <vector>
#include <string>

#define TESTS 10

void execute_push_swap(const std::vector<int>& argv) {
  // Convert vector<int> to char* const* for execve
  char** c_argv = new char*[argv.size() + 1];
  for (std::vector<int>::size_type i = 0; i < argv.size(); ++i) {
    c_argv[i] = new char[std::to_string(argv[i]).length() + 1];
    strcpy(c_argv[i], std::to_string(argv[i]).c_str());
  }
  c_argv[argv.size()] = nullptr;

  // Create a pipe for inter-process communication
  int pipefd[2];
  pipe(pipefd);

  // Create a child process
  pid_t pid = fork();
  if (pid == 0) {
    // Child process: redirect stdout to the pipe and execute push_swap
    close(pipefd[0]);
    dup2(pipefd[1], STDOUT_FILENO);
    execve("./push_swap", c_argv, nullptr);
    _exit(1);
  } else if (pid > 0) {
    // Parent process: read from the pipe and print to stdout
    close(pipefd[1]);
    char buffer[4096];
    ssize_t nread;
    while ((nread = read(pipefd[0], buffer, sizeof(buffer))) > 0) {
      write(STDOUT_FILENO, buffer, nread);
    }
    close(pipefd[0]);

    // Wait for the child process to finish and print its exit status
    int status;
    waitpid(pid, &status, 0);
    if (WIFEXITED(status)) {
      std::cout << "Exit status: " << WEXITSTATUS(status) << std::endl;
    }
  } else {
    // Error creating child process
    std::cerr << "Failed to execute push_swap" << std::endl;
  }

  // Cleanup
  for (std::vector<int>::size_type i = 0; i < argv.size(); ++i) {
    delete[] c_argv[i];
  }
  delete[] c_argv;
}

int main() {
  for (int i = 0; i < TESTS; i++) {
    std::vector<int> arr(100);
    std::iota(arr.begin(), arr.end(), 1);
    std::mt19937 gen(std::random_device{}());
    std::shuffle(arr.begin(), arr.end(), gen);
    for (std::vector<int>::size_type i = 0; i < 100; i += 10) {
      std::vector<int> args(arr.begin() + i, arr.begin() + i + 10);
      execute_push_swap(args);
    }
  }
  return 0;
}
