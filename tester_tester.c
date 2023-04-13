#include <stdio.h>
#include <string.h>

#include "fcntl.h"
#include "libs/libft.h"

int main(int argc, char **argv) {
    if (argc != 2) exit(EXIT_FAILURE);
    int fd = open(argv[1], O_RDONLY);
    char **arr = calloc(sizeof(int *), 10333);
    int i = 0;

    do arr[i] = ft_gnl(fd);
    while (i++ < 10332);

    i = 0;
    char **args = calloc(sizeof(int *), 10333);
    char command[100];
    while (i < 10332) {
        args = ft_split(arr[i], ' ')->str_arr;
        sprintf(command, "./push_swap %s %s %s %s %s %s %s %s | wc -l", args[0],
                args[1], args[2], args[3], args[4], args[5], args[6], args[7]);
        FILE *output = popen(command, "r");
		char buffer[10];
        fgets(buffer, 10, output);
        printf("%s", buffer);
        pclose(output);
        i++;
    }
}
