SRC = src/*.c
INC = includes
LIBS = libft/libft.a
EXE = push_swap
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address -I$(INC)

all:
	$(CC) $(CFLAGS) $(LIBS) $(SRC) -o $(EXE)

clean:
	@rm -f $(EXE)
