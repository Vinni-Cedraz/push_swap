#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void *execute_push_swap(void *arg);

int main(void) {
  pthread_t threads[120];
  int count = 0;
  int arr[] = {1, 2, 3, 4, 5};
  int i, j, k, l, m;

  for (i = 0; i < 5; i++) {
    for (j = 0; j < 5; j++) {
      if (j == i)
        continue;
      for (k = 0; k < 5; k++) {
        if (k == i || k == j)
          continue;
        for (l = 0; l < 5; l++) {
          if (l == i || l == j || l == k)
            continue;
          for (m = 0; m < 5; m++) {
            if (m == i || m == j || m == k || m == l)
              continue;
            int *arg = malloc(5 * sizeof(int));
            arg[0] = arr[i];
            arg[1] = arr[j];
            arg[2] = arr[k];
            arg[3] = arr[l];
            arg[4] = arr[m];
            pthread_create(&threads[count], NULL, execute_push_swap,
                           (void *)arg);
            count++;
          }
        }
      }
    }
  }

  for (i = 0; i < count; i++) {
    pthread_join(threads[i], NULL);
  }

  return 0;
}

void *execute_push_swap(void *arg) {
  int *arr = (int *)arg;
  char command[100];
  sprintf(command, "./push_swap %d %d %d %d %d | wc -l", arr[0], arr[1], arr[2],
          arr[3], arr[4]);

  FILE *output = popen(command, "r");
  char buffer[10];
  fgets(buffer, 10, output);
  printf("%s", buffer);
  pclose(output);

  free(arg);

  return NULL;
}
