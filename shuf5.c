#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "libs/libft.h"

void *execute_push_swap(void **arg);

int is_reverse_sorted(int *arr, int last_index) {
    for (int i = 0; i < last_index; i++)
        if (arr[i] < arr[i + 1]) return 0;
    return 1;
}

int *next_permutation(int *arr, int last_index) {
    if (is_reverse_sorted(arr, last_index)) return NULL;
    int i = last_index;
    while (arr[i - 1] >= arr[i]) i--;
    int j = last_index;
    while (arr[j] <= arr[i - 1]) j--;

    int temp = arr[i - 1];
    arr[i - 1] = arr[j];
    arr[j] = temp;

    j = last_index;
    while (i < j) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++, j--;
    }
    return arr;
}

int **init_permutation_table() {
    int count = 0;
    int *temp = malloc(sizeof(int) * 5);
    int **table = calloc(sizeof(int *), 121);

    temp[0] = 1, temp[1] = 2, temp[2] = 3, temp[3] = 4, temp[4] = 5;
    while (temp) {
        table[count] = malloc(sizeof(int) * 5);
        for (int i = 0; i < 5; i++) table[count][i] = temp[i];
        temp = next_permutation(temp, 4);
        count++;
    }
    return table;
}

void print_arr(int *arr) {
    for (int i = 0; i < 5; i++) printf("%d ", arr[i]);
    printf("\n");
}

void *execute_push_swap_t1(void **table) {
    int **args = (int **)table;
    char command[100];
    char buffer[10];
    FILE *output;
    int i = 0;

    while (args[i][0] != 1) i++;
    while (args[i][0] == 1) {
        sprintf(command, "./push_swap %d %d %d %d %d | wc -l", args[i][0],
                args[i][1], args[i][2], args[i][3], args[i][4]);
        output = popen(command, "r");
        fgets(buffer, 10, output);
        printf("%s", buffer);
        pclose(output);
        i++;
    }
    return NULL;
}

void *execute_push_swap_t2(void **table) {
    int **args = (int **)table;
    char command[100];
    char buffer[10];
    FILE *output;
    int i = 0;

    while (args[i][0] != 2) i++;
    while (args[i][0] == 2) {
        sprintf(command, "./push_swap %d %d %d %d %d | wc -l", args[i][0],
                args[i][1], args[i][2], args[i][3], args[i][4]);
        output = popen(command, "r");
        fgets(buffer, 10, output);
        printf("%s", buffer);
        pclose(output);
        i++;
    }
    return NULL;
}

void *execute_push_swap_t3(void **table) {
    int **args = (int **)table;
    char command[100];
    char buffer[10];
    FILE *output;
    int i = 0;

    while (args[i][0] != 3) i++;
    while (args[i][0] == 3) {
        sprintf(command, "./push_swap %d %d %d %d %d | wc -l", args[i][0],
                args[i][1], args[i][2], args[i][3], args[i][4]);
        output = popen(command, "r");
        fgets(buffer, 10, output);
        printf("%s", buffer);
        pclose(output);
        i++;
    }
    return NULL;
}

void *execute_push_swap_t4(void **table) {
    int **args = (int **)table;
    char command[100];
    char buffer[10];
    FILE *output;
    int i = 0;

    while (args[i][0] != 4) i++;
    while (args[i][0] == 4) {
        sprintf(command, "./push_swap %d %d %d %d %d | wc -l", args[i][0],
                args[i][1], args[i][2], args[i][3], args[i][4]);
        output = popen(command, "r");
        fgets(buffer, 10, output);
        printf("%s", buffer);
        pclose(output);
        i++;
    }
    return NULL;
}

void *execute_push_swap_t5(void **table) {
    int **args = (int **)table;
    char command[100];
    char buffer[10];
    FILE *output;

    while (**args != 5) args++;
    while (*args != NULL) {
        sprintf(command, "./push_swap %d %d %d %d %d | wc -l", args[0][0],
                args[0][1], args[0][2], args[0][3], args[0][4]);
        output = popen(command, "r");
        fgets(buffer, 10, output);
        printf("%s", buffer);
        pclose(output);
        args++;
    }
    return NULL;
}

int main(void) {
    // int count = 0;
    // pthread_t threads[120];
    int **table;
    table = init_permutation_table();
    execute_push_swap_t1((void **)table);
    execute_push_swap_t2((void **)table);
    execute_push_swap_t3((void **)table);
    execute_push_swap_t4((void **)table);
    execute_push_swap_t5((void **)table);
    // printf("threads joined: %d\n", count);
    ft_free_arr((char **)table, (void **)table);
}
