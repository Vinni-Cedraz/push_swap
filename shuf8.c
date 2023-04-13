#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "libs/libft.h"

typedef struct s_worst_cases {
    int _1;
    int _2;
    int _3;
    int _4;
    int _5;
    int _6;
    int _7;
    int _8;
    int _9;
} t_worst_cases;

t_worst_cases WORST_CASE = (t_worst_cases){1, 1, 1, 1, 1, 1, 1, 1, 1};

typedef struct s_args {
    int **table;
} t_args;

int is_reverse_sorted(int *arr, int last_index) {
    for (int i = 0; i < last_index; i++)
        if (arr[i] < arr[i + 1]) return 0;
    return 1;
}

void print_arr(int *arr, int last_index) {
    for (int i = 0; i <= last_index; i++) printf("%d ", arr[i]);
    printf("\n");
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

int **init_permutation_table(void) {
    int count = 0;
    int *arr = malloc(sizeof(int) * 8);
    int **table = calloc(sizeof(int *), 40321);
    int *is_still_going_on;
    for (int i = 0; i < 8; i++) arr[i] = i + 1;

    do {
        if ((is_still_going_on = next_permutation(arr, 7))) {
            table[count] = malloc(sizeof(int) * 8);
            for (int i = 0; i < 8; i++) table[count][i] = arr[i];
            count++;
        }
    } while (is_still_going_on);

    free(arr);
    return table;
}

void *execute_push_swap_t1(void *args_void) {
    t_args *args = (t_args *)args_void;
    int **table = args->table;
    char command[100];
    char buffer[10];
    int i = 0;
    FILE *output;

    while (table[i][0] != 1) i++;
    while (table[i][0] == 1) {
        sprintf(command, "./push_swap %d %d %d %d %d %d %d %d | wc -l",
                table[i][0], table[i][1], table[i][2], table[i][3], table[i][4],
                table[i][5], table[i][6], table[i][7]);
        output = popen(command, "r");
        char *ignore_return = fgets(buffer, 10, output);
        (void)ignore_return;
        if (atoi(buffer) > WORST_CASE._1) WORST_CASE._1 = atoi(buffer);
        if (WORST_CASE._1 == 27) {
            print_arr(table[i], 7);
            exit(1);
        };
        pclose(output);
        i++;
    }
    pthread_exit(NULL);
    return NULL;
}

void *execute_push_swap_t2(void *args_void) {
    t_args *args = (t_args *)args_void;
    int **table = args->table;
    char command[100];
    char buffer[10];
    FILE *output;
    int i = 0;

    while (table[i][0] != 2) i++;
    while (table[i][0] == 2) {
        sprintf(command, "./push_swap %d %d %d %d %d %d %d %d | wc -l",
                table[i][0], table[i][1], table[i][2], table[i][3], table[i][4],
                table[i][5], table[i][6], table[i][7]);
        output = popen(command, "r");
        char *ignore_return = fgets(buffer, 10, output);
        (void)ignore_return;
        if (atoi(buffer) > WORST_CASE._2) WORST_CASE._2 = atoi(buffer);
        if (WORST_CASE._2 == 27) {
            print_arr(table[i], 7);
            exit(1);
        };
        pclose(output);
        i++;
    }
    pthread_exit(NULL);
    return NULL;
}

void *execute_push_swap_t3(void *args_void) {
    t_args *args = (t_args *)args_void;
    int **table = args->table;
    char command[100];
    char buffer[10];
    FILE *output;
    int i = 0;

    while (table[i][0] != 3) i++;
    while (table[i][0] == 3) {
        sprintf(command, "./push_swap %d %d %d %d %d %d %d %d | wc -l",
                table[i][0], table[i][1], table[i][2], table[i][3], table[i][4],
                table[i][5], table[i][6], table[i][7]);
        output = popen(command, "r");
        char *ignore_return = fgets(buffer, 10, output);
        (void)ignore_return;
        if (atoi(buffer) > WORST_CASE._3) WORST_CASE._3 = atoi(buffer);
        if (WORST_CASE._3 == 27) {
            print_arr(table[i], 7);
            exit(1);
        };
        pclose(output);
        i++;
    }
    pthread_exit(NULL);
    return NULL;
}

void *execute_push_swap_t4(void *args_void) {
    t_args *args = (t_args *)args_void;
    int **table = args->table;
    char command[100];
    char buffer[10];
    FILE *output;
    int i = 0;

    while (table[i][0] != 4) i++;
    while (table[i][0] == 4) {
        sprintf(command, "./push_swap %d %d %d %d %d %d %d %d | wc -l",
                table[i][0], table[i][1], table[i][2], table[i][3], table[i][4],
                table[i][5], table[i][6], table[i][7]);
        output = popen(command, "r");
        char *ignore_return = fgets(buffer, 10, output);
        (void)ignore_return;
        if (atoi(buffer) > WORST_CASE._4) WORST_CASE._4 = atoi(buffer);
        if (WORST_CASE._4 == 27) {
            print_arr(table[i], 7);
            exit(1);
        };
        pclose(output);
        i++;
    }
    pthread_exit(NULL);
    return NULL;
}

void *execute_push_swap_t5(void *args_void) {
    t_args *args = (t_args *)args_void;
    int **table = args->table;
    char command[100];
    char buffer[10];
    int i = 0;
    FILE *output;

    while (table[i][0] != 5) i++;
    while (table[i][0] == 5) {
        sprintf(command, "./push_swap %d %d %d %d %d %d %d %d | wc -l",
                table[i][0], table[i][1], table[i][2], table[i][3], table[i][4],
                table[i][5], table[i][6], table[i][7]);
        output = popen(command, "r");
        char *ignore_return = fgets(buffer, 10, output);
        (void)ignore_return;
        if (atoi(buffer) > WORST_CASE._5) WORST_CASE._5 = atoi(buffer);
        if (WORST_CASE._5 == 27) {
            print_arr(table[i], 7);
            exit(1);
        };
        pclose(output);
        i++;
    }
    pthread_exit(NULL);
    return NULL;
}

void *execute_push_swap_t6(void *args_void) {
    t_args *args = (t_args *)args_void;
    int **table = args->table;
    char command[100];
    char buffer[10];
    FILE *output;
    int i = 0;
    while (table[i][0] != 6) i++;
    while (table[i][0] == 6) {
        sprintf(command, "./push_swap %d %d %d %d %d %d %d %d | wc -l",
                table[i][0], table[i][1], table[i][2], table[i][3], table[i][4],
                table[i][5], table[i][6], table[i][7]);
        output = popen(command, "r");
        char *ignore_return = fgets(buffer, 10, output);
        (void)ignore_return;
        if (atoi(buffer) > WORST_CASE._6) WORST_CASE._6 = atoi(buffer);
        if (WORST_CASE._6 == 27) {
            print_arr(table[i], 7);
            exit(1);
        };
        pclose(output);
        i++;
    }
    pthread_exit(NULL);
    return NULL;
}

void *execute_push_swap_t7(void *args_void) {
    t_args *args = (t_args *)args_void;
    int **table = args->table;
    char command[100];
    char buffer[10];
    FILE *output;
    int i = 0;
    while (table[i][0] != 7) i++;
    while (table[i][0] == 7) {
        sprintf(command, "./push_swap %d %d %d %d %d %d %d %d | wc -l",
                table[i][0], table[i][1], table[i][2], table[i][3], table[i][4],
                table[i][5], table[i][6], table[i][7]);
        output = popen(command, "r");
        char *ignore_return = fgets(buffer, 10, output);
        (void)ignore_return;
        if (atoi(buffer) > WORST_CASE._7) WORST_CASE._7 = atoi(buffer);
        if (WORST_CASE._7 == 27) {
            print_arr(table[i], 7);
            exit(1);
        };
        pclose(output);
        i++;
    }
    pthread_exit(NULL);
    return NULL;
}

void *execute_push_swap_t8(void *args_void) {
    t_args *args = (t_args *)args_void;
    int **table = args->table;
    char command[100];
    char buffer[10];
    FILE *output;
    while (**table != 8) table++;
    while (*table != NULL) {
        sprintf(command, "./push_swap %d %d %d %d %d %d %d %d | wc -l",
                table[0][0], table[0][1], table[0][2], table[0][3], table[0][4],
                table[0][5], table[0][6], table[0][7]);
        output = popen(command, "r");
        char *ignore_return = fgets(buffer, 10, output);
        (void)ignore_return;
        if (atoi(buffer) > WORST_CASE._8) WORST_CASE._8 = atoi(buffer);
        if (WORST_CASE._8 == 27) {
            print_arr(*table, 7);
    		pthread_exit(NULL);
        };
        pclose(output);
        table++;
    }
    pthread_exit(NULL);
    return NULL;
}

int get_worst_case(t_worst_cases WORST_CASE) {
    int worst_case = 0;
    if (WORST_CASE._1 > worst_case) worst_case = WORST_CASE._1;
    if (WORST_CASE._3 > worst_case) worst_case = WORST_CASE._3;
    if (WORST_CASE._4 > worst_case) worst_case = WORST_CASE._4;
    if (WORST_CASE._5 > worst_case) worst_case = WORST_CASE._5;
    if (WORST_CASE._6 > worst_case) worst_case = WORST_CASE._6;
    if (WORST_CASE._7 > worst_case) worst_case = WORST_CASE._7;
    if (WORST_CASE._8 > worst_case) worst_case = WORST_CASE._8;
    return worst_case;
}

int main(void) {
    t_args *args = malloc(sizeof(t_args));
    pthread_t pthread[8];
    args->table = init_permutation_table();
    pthread_create(&pthread[0], NULL, execute_push_swap_t1, (void *)args);
    pthread_create(&pthread[1], NULL, execute_push_swap_t2, (void *)args);
    pthread_create(&pthread[2], NULL, execute_push_swap_t3, (void *)args);
    pthread_create(&pthread[3], NULL, execute_push_swap_t4, (void *)args);
    pthread_create(&pthread[4], NULL, execute_push_swap_t5, (void *)args);
    pthread_create(&pthread[5], NULL, execute_push_swap_t6, (void *)args);
    pthread_create(&pthread[6], NULL, execute_push_swap_t7, (void *)args);
    pthread_create(&pthread[7], NULL, execute_push_swap_t8, (void *)args);
    int count = 0;
    while (count < 8) {
        pthread_join(pthread[count], NULL);
        count++;
    }
    printf("numbers of threads joined: %d\n", count);
    printf("worst case: %d\n", get_worst_case(WORST_CASE));
    ft_free_arr((char **)args->table, (void **)args->table);
    free(args);
}
