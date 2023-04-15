#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "libs/libft.h"

#define WORST 11500
#define IGNORE_AVERAGE 0

typedef struct s_worst_cases {
    int _1;
    int _2;
    int _3;
    int _4;
    int _5;
    int _6;
    int _7;
    int _8;
} t_worst_cases;

typedef struct s_best_cases {
    int _1;
    int _2;
    int _3;
    int _4;
    int _5;
    int _6;
    int _7;
    int _8;
} t_best_cases;

t_worst_cases WORST_CASE = (t_worst_cases){1, 1, 1, 1, 1, 1, 1, 1};
t_best_cases BEST_CASE =
    (t_best_cases){__INT_MAX__, __INT_MAX__, __INT_MAX__, __INT_MAX__,
                   __INT_MAX__, __INT_MAX__, __INT_MAX__, __INT_MAX__};

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

int **init_permutation_table(void) {
    int count = 0;
    int *arr = malloc(sizeof(int) * 8);
    int **table = calloc(sizeof(int *), 40321);
    int is_still_going_on;
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
        if (atoi(buffer) < BEST_CASE._1) BEST_CASE._1 = atoi(buffer);
        if (WORST_CASE._1 == WORST) {
            printf("this is one of the worst case combinations: ");
            print_arr(table[i], 7);
            pthread_exit(NULL);
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
        if (atoi(buffer) < BEST_CASE._2) BEST_CASE._2 = atoi(buffer);
        if (WORST_CASE._2 == WORST) {
            printf("this is one of the worst case combinations: ");
            print_arr(table[i], 7);
            pthread_exit(NULL);
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
        if (atoi(buffer) < BEST_CASE._3) BEST_CASE._3 = atoi(buffer);
        if (WORST_CASE._3 == WORST) {
            printf("this is one of the worst case combinations: ");
            print_arr(table[i], 7);
            pthread_exit(NULL);
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
        if (atoi(buffer) < BEST_CASE._4) BEST_CASE._4 = atoi(buffer);
        if (WORST_CASE._4 == WORST) {
            printf("this is one of the worst case combinations: ");
            print_arr(table[i], 7);
            pthread_exit(NULL);
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
        if (atoi(buffer) < BEST_CASE._5) BEST_CASE._5 = atoi(buffer);
        if (WORST_CASE._5 == WORST) {
            printf("this is one of the worst case combinations: ");
            print_arr(table[i], 7);
            pthread_exit(NULL);
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
        if (atoi(buffer) < BEST_CASE._6) BEST_CASE._6 = atoi(buffer);
        if (WORST_CASE._6 == WORST) {
            printf("this is one of the worst case combinations: ");
            print_arr(table[i], 7);
            pthread_exit(NULL);
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
        if (atoi(buffer) < BEST_CASE._7) BEST_CASE._7 = atoi(buffer);
        if (WORST_CASE._7 == WORST) {
            printf("this is one of the worst case combinations: ");
            print_arr(table[i], 7);
            pthread_exit(NULL);
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
        if (atoi(buffer) < BEST_CASE._8) BEST_CASE._8 = atoi(buffer);
        if (WORST_CASE._8 == WORST) {
            printf("this is one of the worst case combinations: ");
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

int get_best_case(t_best_cases BEST_CASE) {
    int best_case = BEST_CASE._1;
    if (BEST_CASE._3 < best_case) best_case = BEST_CASE._3;
    if (BEST_CASE._4 < best_case) best_case = BEST_CASE._4;
    if (BEST_CASE._5 < best_case) best_case = BEST_CASE._5;
    if (BEST_CASE._6 < best_case) best_case = BEST_CASE._6;
    if (BEST_CASE._7 < best_case) best_case = BEST_CASE._7;
    if (BEST_CASE._8 < best_case) best_case = BEST_CASE._8;
    return best_case;
}

int main(void) {
    t_args *args = malloc(sizeof(t_args));
    pthread_t pthread[8];
	printf("Initializing permutation table...\n\n");
    args->table = init_permutation_table();
	printf("Running push_swap in 8 different threads. This will test all the 40320 cases for 8 elements.\n");
	printf("This shouldn't take much more than 25 seconds.\n");
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
    int worst = get_worst_case(WORST_CASE);
    printf("Number of operations in the worst cases: %d\n", worst);
    int best = get_best_case(BEST_CASE);
    if (IGNORE_AVERAGE == 0) {
        printf("And in the the average case: %d\n", (worst + best) / 2);
        printf(
            "\n%s\n",
            "To find out some of the worst case combinations, define WORST to "
			"the worst case and define IGNORE_AVERAGE to 1");
    }
    ft_free_arr((char **)args->table, (void **)args->table);
    free(args);
}
