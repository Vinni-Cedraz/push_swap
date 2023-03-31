SHELL := /bin/bash
# Colors
RED    	  	=  \033[0;91m
GRAY      	=  \033[0;37m
CYAN      	=  \033[0;96m
WHITE     	=  \033[0;97m
GREEN     	=  \033[0;92m
YELLOW          =  \033[0;93m
MAGENTA         =  \033[0;95m
DEF_COLOR       =  \033[0;39m

NAME = push_swap.a
LIBFT_PATH = libft/
INC = -Iincludes/ -I$(LIBFT_PATH)
EXECUTABLE = push_swap
CFLAGS = -Wall -Wextra -Werror -g $(INC)

SRCS = \
	  main \
	  print_stack \
	  push \
	  rotate \
	  reverse_rotate \
	  tests \
	  small_size_sort \
	  big_size_sort \
	  sort_three \
	  utils \
	  cost_to_make_it_top \
	  swap

SRCS_PATH = src/
OBJS_PATH = objs/
LIBFT_OBJS_PATH = $(LIBFT_PATH)objs/
OBJS = $(patsubst %, $(OBJS_PATH)%.o, $(SRCS))
LIBFT_OBJS = $(patsubst %, $(LIBFT_OBJS_PATH)%.o, $(LIBFT_SRCS))
MOD_OBJ = $(shell find $(OBJS_PATH)*.o -newer $(NAME))

all: $(NAME)

make_libft:
	@make -C $(LIBFT_PATH) --no-print-directory

$(NAME): $(OBJS) make_libft
	@printf "\n$(YELLOW)Linking FDF Objects to Library...$(DEF_COLOR)\n";
	@for file in $(MOD_OBJ); do \
		printf "$(CYAN)Linking $(WHITE)$$file $(GRAY)to $(RED)$(NAME)$(DEF_COLOR)                       \r"; \
		ar -rsc $(NAME) $$file; \
	done
	@for file in $(SRCS); do \
		if [[ -z "$$(nm $(NAME) | grep $${file}.o:)" ]]; then \
		ar -rsc $(NAME) $(OBJS_PATH)$$file.o; \
		printf "$(CYAN)Linking $(WHITE)$$file $(GRAY)to $(RED)$(NAME)$(DEF_COLOR)                        \r"; \
	fi; \
	done
	@printf "$(CYAN)Creating $(EXECUTABLE)$(DEF_COLOR)\n"; \
	$(CC) $(CFLAGS) $(NAME) $(LIBFT_PATH)libft.a $(MLXFLAGS) -o $(EXECUTABLE);
	@printf "$(WHITE)Created Library $(RED)$(NAME)$(DEF_COLOR)                                             \n";
	@printf "\njust execute $(GREEN)./$(EXECUTABLE) $(GRAY)to run the program\n$(DEF_COLOR)                  \n";

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p $(OBJS_PATH)
	@make LOOP --no-print-directory

LOOP: 
	@for file in $(SRCS); do \
		if [ $(SRCS_PATH)$$file.c -nt $(OBJS_PATH)$$file.o ]; then \
			printf "$(GREEN)[push_swap]$(CYAN) Compiling $(WHITE)$$file.c$(DEF_COLOR)\n"; \
			printf "$(CC) $(CFLAGS) -c $(SRCS_PATH)$$file.c -o $(OBJS_PATH)$$file.o\n"; \
			$(CC) $(CFLAGS) -c $(SRCS_PATH)$$file.c -o $(OBJS_PATH)$$file.o; \
			printf "$(WHITE)$$file.c$(GREEN) OK$(DEF_COLOR)\n\n"; \
		fi; \
	done


clean:
	@make -C $(LIBFT_PATH) clean --no-print-directory
	@rm -f $(EXECUTABLE)
	@rm -rf $(OBJS_PATH)
	@rm -f $(NAME)

