#include <fcntl.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "libs/libft.h"

#define WORST 999999
#define IGNORE_AVERAGE 1

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

void print_arr(int *arr, int last_index) {
    for (int i = 0; i <= last_index; i++) printf("%d ", arr[i]);
    printf("\n");
}

int *seq_except(int exclude) {
    int j = 0;
    int i = 0;
    int *arr = (int *)malloc(99 * sizeof(int));
    for (; ++i != 101;)
        if (i != exclude) arr[j++] = i;
    return arr;
}

int **init_permutation_table(void) {
    int count = 0;
    int j = 1;
    int *tmp_arr = calloc(sizeof(int), 99);
    int **table = calloc(sizeof(int *), 160000);

    for (int i = 1; i <= 100; i++) {
        tmp_arr = seq_except(i);
        for (int k = 1; k <= 1600; k++) {
            table[count] = malloc(sizeof(int) * 100);
            table[count][0] = i;
            ft_randomize_array(tmp_arr, 99);
            int k = 0;
            for (j = 1; j < 100; j++) {
                table[count][j] = tmp_arr[k];
                k++;
            }
            count++;
        }
    }

    free(tmp_arr);
    return table;
}

void *execute_push_swap_t1(void *args_void) {
    t_args *args = (t_args *)args_void;
    int **table = args->table;
    char command[500];
    // char buffer[10];
    int i = 0;
    // FILE *output;

    while (table[i][0] != 1) i++;
    while (table[i][0] >= 1 && table[i][0] <= 12) {
        sprintf(
            command,
            "./push_swap %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
            "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
            "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
            "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
            "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d | wc -l",
            table[0][0], table[0][1], table[0][2], table[0][3], table[0][4],
            table[0][5], table[0][6], table[0][7], table[0][8], table[0][9],
            table[0][10], table[0][11], table[0][12], table[0][13],
            table[0][14], table[0][15], table[0][16], table[0][17],
            table[0][18], table[0][19], table[0][20], table[0][21],
            table[0][22], table[0][23], table[0][24], table[0][25],
            table[0][26], table[0][27], table[0][28], table[0][29],
            table[0][30], table[0][31], table[0][32], table[0][33],
            table[0][34], table[0][35], table[0][36], table[0][37],
            table[0][38], table[0][39], table[0][40], table[0][41],
            table[0][42], table[0][43], table[0][44], table[0][45],
            table[0][46], table[0][47], table[0][48], table[0][49],
            table[0][50], table[0][51], table[0][52], table[0][53],
            table[0][54], table[0][55], table[0][56], table[0][57],
            table[0][58], table[0][59], table[0][60], table[0][61],
            table[0][62], table[0][63], table[0][64], table[0][65],
            table[0][66], table[0][67], table[0][68], table[0][69],
            table[0][70], table[0][71], table[0][72], table[0][73],
            table[0][74], table[0][75], table[0][76], table[0][77],
            table[0][78], table[0][79], table[0][80], table[0][81],
            table[0][82], table[0][83], table[0][84], table[0][85],
            table[0][86], table[0][87], table[0][88], table[0][89],
            table[0][90], table[0][91], table[0][92], table[0][93],
            table[0][94], table[0][95], table[0][96], table[0][97],
            table[0][98], table[0][99]);
        // output = popen(command, "r");
        i++;
    }
    pthread_exit(NULL);
    return NULL;
}

void *execute_push_swap_t2(void *args_void) {
    t_args *args = (t_args *)args_void;
    int **table = args->table;
    char command[500];
    char buffer[10];
    FILE *output;
    int i = 0;

    FILE *fp = fopen("log.txt", "a");
    while (table[i][0] != 13) i++;
    while (table[i][0] >= 13 && table[i][0] <= 24) {
        sprintf(
            command,
            "./push_swap %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
            "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
            "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
            "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
            "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d | wc -l",
            table[i][0], table[i][1], table[i][2], table[i][3], table[i][4],
            table[i][5], table[i][6], table[i][7], table[i][8], table[i][9],
            table[i][10], table[i][11], table[i][12], table[i][13],
            table[i][14], table[i][15], table[i][16], table[i][17],
            table[i][18], table[i][19], table[i][20], table[i][21],
            table[i][22], table[i][23], table[i][24], table[i][25],
            table[i][26], table[i][27], table[i][28], table[i][29],
            table[i][30], table[i][31], table[i][32], table[i][33],
            table[i][34], table[i][35], table[i][36], table[i][37],
            table[i][38], table[i][39], table[i][40], table[i][41],
            table[i][42], table[i][43], table[i][44], table[i][45],
            table[i][46], table[i][47], table[i][48], table[i][49],
            table[i][50], table[i][51], table[i][52], table[i][53],
            table[i][54], table[i][55], table[i][56], table[i][57],
            table[i][58], table[i][59], table[i][60], table[i][61],
            table[i][62], table[i][63], table[i][64], table[i][65],
            table[i][66], table[i][67], table[i][68], table[i][69],
            table[i][70], table[i][71], table[i][72], table[i][73],
            table[i][74], table[i][75], table[i][76], table[i][77],
            table[i][78], table[i][79], table[i][80], table[i][81],
            table[i][82], table[i][83], table[i][84], table[i][85],
            table[i][86], table[i][87], table[i][88], table[i][89],
            table[i][90], table[i][91], table[i][92], table[i][93],
            table[i][94], table[i][95], table[i][96], table[i][97],
            table[i][98], table[i][99]);

        output = popen(command, "r");
        char *out_str = fgets(buffer, 10, output);
        fprintf(fp, "arr[%d]: {", i);
        for (int j = 0; j < 100; j++) fprintf(fp, "%d ", table[i][j]);
        fprintf(fp, "} number of operations: %s", out_str);
        i++;
    }
    fclose(fp);
    pthread_exit(NULL);
    return NULL;
}

void *execute_push_swap_t3(void *args_void) {
    t_args *args = (t_args *)args_void;
    int **table = args->table;
    char command[500];
    char buffer[10];
    FILE *output;
    int i = 0;

    while (table[i][0] != 25) i++;
    while (table[i][0] >= 25 && table[i][0] <= 36) {
        sprintf(
            command,
            "./push_swap %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
            "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
            "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
            "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
            "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d | wc -l",
            table[i][0], table[i][1], table[i][2], table[i][3], table[i][4],
            table[i][5], table[i][6], table[i][7], table[i][8], table[i][9],
            table[i][10], table[i][11], table[i][12], table[i][13],
            table[i][14], table[i][15], table[i][16], table[i][17],
            table[i][18], table[i][19], table[i][20], table[i][21],
            table[i][22], table[i][23], table[i][24], table[i][25],
            table[i][26], table[i][27], table[i][28], table[i][29],
            table[i][30], table[i][31], table[i][32], table[i][33],
            table[i][34], table[i][35], table[i][36], table[i][37],
            table[i][38], table[i][39], table[i][40], table[i][41],
            table[i][42], table[i][43], table[i][44], table[i][45],
            table[i][46], table[i][47], table[i][48], table[i][49],
            table[i][50], table[i][51], table[i][52], table[i][53],
            table[i][54], table[i][55], table[i][56], table[i][57],
            table[i][58], table[i][59], table[i][60], table[i][61],
            table[i][62], table[i][63], table[i][64], table[i][65],
            table[i][66], table[i][67], table[i][68], table[i][69],
            table[i][70], table[i][71], table[i][72], table[i][73],
            table[i][74], table[i][75], table[i][76], table[i][77],
            table[i][78], table[i][79], table[i][80], table[i][81],
            table[i][82], table[i][83], table[i][84], table[i][85],
            table[i][86], table[i][87], table[i][88], table[i][89],
            table[i][90], table[i][91], table[i][92], table[i][93],
            table[i][94], table[i][95], table[i][96], table[i][97],
            table[i][98], table[i][99]);

        output = popen(command, "r");
        char *ignore_return = fgets(buffer, 10, output);
        (void)ignore_return;
        if (atoi(buffer) > WORST_CASE._3) WORST_CASE._3 = atoi(buffer);
        if (atoi(buffer) < BEST_CASE._3) BEST_CASE._3 = atoi(buffer);
        if (WORST_CASE._3 >= WORST) {
            printf("this is one of the worst case combinations: ");
            print_arr(table[i], 99);
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
    char command[500];
    char buffer[10];
    FILE *output;
    int i = 0;

    while (table[i][0] != 37) i++;
    while (table[i][0] >= 37 && table[i][0] <= 48) {
        sprintf(
            command,
            "./push_swap %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
            "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
            "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
            "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
            "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d | wc -l",
            table[i][0], table[i][1], table[i][2], table[i][3], table[i][4],
            table[i][5], table[i][6], table[i][7], table[i][8], table[i][9],
            table[i][10], table[i][11], table[i][12], table[i][13],
            table[i][14], table[i][15], table[i][16], table[i][17],
            table[i][18], table[i][19], table[i][20], table[i][21],
            table[i][22], table[i][23], table[i][24], table[i][25],
            table[i][26], table[i][27], table[i][28], table[i][29],
            table[i][30], table[i][31], table[i][32], table[i][33],
            table[i][34], table[i][35], table[i][36], table[i][37],
            table[i][38], table[i][39], table[i][40], table[i][41],
            table[i][42], table[i][43], table[i][44], table[i][45],
            table[i][46], table[i][47], table[i][48], table[i][49],
            table[i][50], table[i][51], table[i][52], table[i][53],
            table[i][54], table[i][55], table[i][56], table[i][57],
            table[i][58], table[i][59], table[i][60], table[i][61],
            table[i][62], table[i][63], table[i][64], table[i][65],
            table[i][66], table[i][67], table[i][68], table[i][69],
            table[i][70], table[i][71], table[i][72], table[i][73],
            table[i][74], table[i][75], table[i][76], table[i][77],
            table[i][78], table[i][79], table[i][80], table[i][81],
            table[i][82], table[i][83], table[i][84], table[i][85],
            table[i][86], table[i][87], table[i][88], table[i][89],
            table[i][90], table[i][91], table[i][92], table[i][93],
            table[i][94], table[i][95], table[i][96], table[i][97],
            table[i][98], table[i][99]);

        output = popen(command, "r");
        char *ignore_return = fgets(buffer, 10, output);
        (void)ignore_return;
        if (atoi(buffer) > WORST_CASE._4) WORST_CASE._4 = atoi(buffer);
        if (atoi(buffer) < BEST_CASE._4) BEST_CASE._4 = atoi(buffer);
        if (WORST_CASE._4 >= WORST) {
            printf("this is one of the worst case combinations: ");
            print_arr(table[i], 99);
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
    char command[500];
    char buffer[10];
    int i = 0;
    FILE *output;

    while (table[i][0] != 49) i++;
    while (table[i][0] >= 49 && table[i][0] <= 61) {
        sprintf(
            command,
            "./push_swap %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
            "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
            "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
            "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
            "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d | wc -l",
            table[i][0], table[i][1], table[i][2], table[i][3], table[i][4],
            table[i][5], table[i][6], table[i][7], table[i][8], table[i][9],
            table[i][10], table[i][11], table[i][12], table[i][13],
            table[i][14], table[i][15], table[i][16], table[i][17],
            table[i][18], table[i][19], table[i][20], table[i][21],
            table[i][22], table[i][23], table[i][24], table[i][25],
            table[i][26], table[i][27], table[i][28], table[i][29],
            table[i][30], table[i][31], table[i][32], table[i][33],
            table[i][34], table[i][35], table[i][36], table[i][37],
            table[i][38], table[i][39], table[i][40], table[i][41],
            table[i][42], table[i][43], table[i][44], table[i][45],
            table[i][46], table[i][47], table[i][48], table[i][49],
            table[i][50], table[i][51], table[i][52], table[i][53],
            table[i][54], table[i][55], table[i][56], table[i][57],
            table[i][58], table[i][59], table[i][60], table[i][61],
            table[i][62], table[i][63], table[i][64], table[i][65],
            table[i][66], table[i][67], table[i][68], table[i][69],
            table[i][70], table[i][71], table[i][72], table[i][73],
            table[i][74], table[i][75], table[i][76], table[i][77],
            table[i][78], table[i][79], table[i][80], table[i][81],
            table[i][82], table[i][83], table[i][84], table[i][85],
            table[i][86], table[i][87], table[i][88], table[i][89],
            table[i][90], table[i][91], table[i][92], table[i][93],
            table[i][94], table[i][95], table[i][96], table[i][97],
            table[i][98], table[i][99]);

        output = popen(command, "r");
        char *ignore_return = fgets(buffer, 10, output);
        (void)ignore_return;
        if (atoi(buffer) > WORST_CASE._5) WORST_CASE._5 = atoi(buffer);
        if (atoi(buffer) < BEST_CASE._5) BEST_CASE._5 = atoi(buffer);
        if (WORST_CASE._5 >= WORST) {
            printf("this is one of the worst case combinations: ");
            print_arr(table[i], 99);
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
    char command[500];
    char buffer[10];
    FILE *output;
    int i = 0;
    while (table[i][0] != 62) i++;
    while (table[i][0] >= 62 && table[i][0] <= 74) {
        sprintf(
            command,
            "./push_swap %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
            "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
            "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
            "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
            "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d | wc -l",
            table[i][0], table[i][1], table[i][2], table[i][3], table[i][4],
            table[i][5], table[i][6], table[i][7], table[i][8], table[i][9],
            table[i][10], table[i][11], table[i][12], table[i][13],
            table[i][14], table[i][15], table[i][16], table[i][17],
            table[i][18], table[i][19], table[i][20], table[i][21],
            table[i][22], table[i][23], table[i][24], table[i][25],
            table[i][26], table[i][27], table[i][28], table[i][29],
            table[i][30], table[i][31], table[i][32], table[i][33],
            table[i][34], table[i][35], table[i][36], table[i][37],
            table[i][38], table[i][39], table[i][40], table[i][41],
            table[i][42], table[i][43], table[i][44], table[i][45],
            table[i][46], table[i][47], table[i][48], table[i][49],
            table[i][50], table[i][51], table[i][52], table[i][53],
            table[i][54], table[i][55], table[i][56], table[i][57],
            table[i][58], table[i][59], table[i][60], table[i][61],
            table[i][62], table[i][63], table[i][64], table[i][65],
            table[i][66], table[i][67], table[i][68], table[i][69],
            table[i][70], table[i][71], table[i][72], table[i][73],
            table[i][74], table[i][75], table[i][76], table[i][77],
            table[i][78], table[i][79], table[i][80], table[i][81],
            table[i][82], table[i][83], table[i][84], table[i][85],
            table[i][86], table[i][87], table[i][88], table[i][89],
            table[i][90], table[i][91], table[i][92], table[i][93],
            table[i][94], table[i][95], table[i][96], table[i][97],
            table[i][98], table[i][99]);

        output = popen(command, "r");
        char *ignore_return = fgets(buffer, 10, output);
        (void)ignore_return;
        if (atoi(buffer) > WORST_CASE._6) WORST_CASE._6 = atoi(buffer);
        if (atoi(buffer) < BEST_CASE._6) BEST_CASE._6 = atoi(buffer);
        if (WORST_CASE._6 >= WORST) {
            printf("this is one of the worst case combinations: ");
            print_arr(table[i], 99);
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
    char command[500];
    char buffer[10];
    FILE *output;
    int i = 0;
    while (table[i][0] != 75) i++;
    while (table[i][0] >= 75 && table[i][0] <= 87) {
        sprintf(
            command,
            "./push_swap %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
            "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
            "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
            "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
            "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d | wc -l",
            table[i][0], table[i][1], table[i][2], table[i][3], table[i][4],
            table[i][5], table[i][6], table[i][7], table[i][8], table[i][9],
            table[i][10], table[i][11], table[i][12], table[i][13],
            table[i][14], table[i][15], table[i][16], table[i][17],
            table[i][18], table[i][19], table[i][20], table[i][21],
            table[i][22], table[i][23], table[i][24], table[i][25],
            table[i][26], table[i][27], table[i][28], table[i][29],
            table[i][30], table[i][31], table[i][32], table[i][33],
            table[i][34], table[i][35], table[i][36], table[i][37],
            table[i][38], table[i][39], table[i][40], table[i][41],
            table[i][42], table[i][43], table[i][44], table[i][45],
            table[i][46], table[i][47], table[i][48], table[i][49],
            table[i][50], table[i][51], table[i][52], table[i][53],
            table[i][54], table[i][55], table[i][56], table[i][57],
            table[i][58], table[i][59], table[i][60], table[i][61],
            table[i][62], table[i][63], table[i][64], table[i][65],
            table[i][66], table[i][67], table[i][68], table[i][69],
            table[i][70], table[i][71], table[i][72], table[i][73],
            table[i][74], table[i][75], table[i][76], table[i][77],
            table[i][78], table[i][79], table[i][80], table[i][81],
            table[i][82], table[i][83], table[i][84], table[i][85],
            table[i][86], table[i][87], table[i][88], table[i][89],
            table[i][90], table[i][91], table[i][92], table[i][93],
            table[i][94], table[i][95], table[i][96], table[i][97],
            table[i][98], table[i][99]);

        output = popen(command, "r");
        char *ignore_return = fgets(buffer, 10, output);
        (void)ignore_return;
        if (atoi(buffer) > WORST_CASE._7) WORST_CASE._7 = atoi(buffer);
        if (atoi(buffer) < BEST_CASE._7) BEST_CASE._7 = atoi(buffer);
        if (WORST_CASE._7 >= WORST) {
            printf("this is one of the worst case combinations: ");
            print_arr(table[i], 99);
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
    char command[500];
    char buffer[10];
    FILE *output;
    while (**table != 88) table++;
    while (*table != NULL) {
        sprintf(
            command,
            "./push_swap %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
            "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
            "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
            "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
            "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d | wc -l",
            table[0][0], table[0][1], table[0][2], table[0][3], table[0][4],
            table[0][5], table[0][6], table[0][7], table[0][8], table[0][9],
            table[0][10], table[0][11], table[0][12], table[0][13],
            table[0][14], table[0][15], table[0][16], table[0][17],
            table[0][18], table[0][19], table[0][20], table[0][21],
            table[0][22], table[0][23], table[0][24], table[0][25],
            table[0][26], table[0][27], table[0][28], table[0][29],
            table[0][30], table[0][31], table[0][32], table[0][33],
            table[0][34], table[0][35], table[0][36], table[0][37],
            table[0][38], table[0][39], table[0][40], table[0][41],
            table[0][42], table[0][43], table[0][44], table[0][45],
            table[0][46], table[0][47], table[0][48], table[0][49],
            table[0][50], table[0][51], table[0][52], table[0][53],
            table[0][54], table[0][55], table[0][56], table[0][57],
            table[0][58], table[0][59], table[0][60], table[0][61],
            table[0][62], table[0][63], table[0][64], table[0][65],
            table[0][66], table[0][67], table[0][68], table[0][69],
            table[0][70], table[0][71], table[0][72], table[0][73],
            table[0][74], table[0][75], table[0][76], table[0][77],
            table[0][78], table[0][79], table[0][80], table[0][81],
            table[0][82], table[0][83], table[0][84], table[0][85],
            table[0][86], table[0][87], table[0][88], table[0][89],
            table[0][90], table[0][91], table[0][92], table[0][93],
            table[0][94], table[0][95], table[0][96], table[0][97],
            table[0][98], table[0][99]);

        output = popen(command, "r");
        char *ignore_return = fgets(buffer, 10, output);
        (void)ignore_return;
        if (atoi(buffer) > WORST_CASE._8) WORST_CASE._8 = atoi(buffer);
        if (atoi(buffer) < BEST_CASE._8) BEST_CASE._8 = atoi(buffer);
        if (WORST_CASE._8 >= WORST) {
            printf("this is one of the worst case combinations: ");
            print_arr(*table, 99);
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
    if (WORST_CASE._2 > worst_case) worst_case = WORST_CASE._2;
    if (WORST_CASE._3 > worst_case) worst_case = WORST_CASE._3;
    if (WORST_CASE._4 > worst_case) worst_case = WORST_CASE._4;
    if (WORST_CASE._5 > worst_case) worst_case = WORST_CASE._5;
    if (WORST_CASE._6 > worst_case) worst_case = WORST_CASE._6;
    if (WORST_CASE._7 > worst_case) worst_case = WORST_CASE._7;
    if (WORST_CASE._8 > worst_case) worst_case = WORST_CASE._8;
    return worst_case;
}

int get_best_case(t_best_cases BEST_CASE) {
    int best_case = __INT_MAX__;
    if (BEST_CASE._1 < best_case) best_case = BEST_CASE._1;
    if (BEST_CASE._2 < best_case) best_case = BEST_CASE._2;
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
    printf(
        "Get ready to witness the ultimate push_swap breaker.\nWe'll have 8 "
        "threads pushing your push_swap to the limits at the same time.\n"
        "It will be a total of 80000 different args tested.\n"
        "Don't worry, these permutations are very well distributed...\n"
        "Unlike your life choices.\n\n");
    printf("This shouldn't take much more than 5 minutes.\n");
    pthread_create(&pthread[0], NULL, execute_push_swap_t1, (void *)args);
    pthread_create(&pthread[1], NULL, execute_push_swap_t2, (void *)args);
    pthread_create(&pthread[2], NULL, execute_push_swap_t3, (void *)args);
    pthread_create(&pthread[3], NULL, execute_push_swap_t4, (void *)args);
    pthread_create(&pthread[4], NULL, execute_push_swap_t5, (void *)args);
    pthread_create(&pthread[5], NULL, execute_push_swap_t6, (void *)args);
    pthread_create(&pthread[6], NULL, execute_push_swap_t7, (void *)args);
    pthread_create(&pthread[7], NULL, execute_push_swap_t8, (void *)args);
    int count = -1;
    while (++count < 8) pthread_join(pthread[count], NULL);
    int worst = get_worst_case(WORST_CASE);
    printf("worst case: %d\n", worst);
    if (IGNORE_AVERAGE == 0) {
        int best = get_best_case(BEST_CASE);
        printf("best case: %d\n", best);
        printf(
            "\n\n\n%s\n",
            "To find out some of the worst case combinations, define WORST to "
            "the worst case and define IGNORE_AVERAGE to 1\n"
            "Then you recompile and run again.\n"
            "You might not find a combination with the same worst case again "
            "on the first try");
    }
    ft_free_arr((char **)args->table, (void **)args->table);
    free(args);
}
