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
ALT_NAME = push_swap_debug.a
LIBFT_PATH = libs/
INC = -Iincludes/ -I$(LIBFT_PATH)
EXECUTABLE = push_swap
ALT_EXECUTABLE = push_swap_debug
CFLAGS = -Wall -Wextra -Werror -O3 $(INC)

SRCS = \
	  main \
	  push \
	  rotate \
	  reverse_rotate \
	  execute_operations \
	  small_size_sort \
	  big_size_sort \
	  sort_three \
	  utils \
	  get_push_cost \
	  is_lowest_three \
	  get_current_total_cost \
	  swap

ALT_SRCS = \
		   main_debug \
		   tests \
		   execute_operations_debug \
		   print_stack \
		   push \
		   swap \
		   rotate \
		   reverse_rotate \
		   small_size_sort \
		   big_size_sort \
		   sort_three \
		   utils \
		   get_push_cost \
		   is_lowest_three \
		   get_current_total_cost \

SRCS_PATH = src/
OBJS_PATH = objs/
ALT_SRCS_PATH = src/
ALT_OBJS_PATH = alt_objs/
LIBFT_OBJS_PATH = $(LIBFT_PATH)objs/

OBJS = $(patsubst %, $(OBJS_PATH)%.o, $(SRCS))
ALT_OBJS = $(patsubst %, $(ALT_OBJS_PATH)%.o, $(ALT_SRCS))
MOD_OBJ = $(shell find $(OBJS_PATH)*.o -newer $(NAME))
ALT_MOD_OBJ = $(shell find $(ALT_OBJS_PATH)*.o -newer $(ALT_NAME))
LIBFT_OBJS = $(patsubst %, $(LIBFT_OBJS_PATH)%.o, $(LIBFT_SRCS))

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
	@printf "$(CYAN)Creating $(EXECUTABLE)$(DEF_COLOR)                                                       \n";\
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
	@rm -rf $(OBJS_PATH)
	@rm -rf $(ALT_OBJS_PATH)

clean_nolib:
	@rm -rf $(OBJS_PATH)
	@rm -rf $(ALT_OBJS_PATH)

fclean_nolib: clean_nolib
	@rm -f $(EXECUTABLE)
	@rm -f $(ALT_EXECUTABLE)
	@rm -f $(NAME)
	@rm -f $(ALT_NAME)

fclean: fclean_nolib
	@make -C $(LIBFT_PATH) fclean --no-print-directory

re: fclean all

re_nolib: fclean_nolib all

### ALTERNATIVE COMPILATION THAT PRINTS THE OPERATIONS AS THEY HAPPEN ###

debug: make_libft $(ALT_OBJS)
	@printf "\n$(YELLOW)Linking FDF Objects to Library...$(DEF_COLOR)\n";
	@for file in $(ALT_MOD_OBJ); do \
		printf "$(CYAN)Linking $(WHITE)$$file $(GRAY)to $(RED)$(ALT_NAME)$(DEF_COLOR)                       \r"; \
		ar -rsc $(ALT_NAME) $$file; \
	done
	@for file in $(ALT_SRCS); do \
		if [[ -z "$$(nm $(ALT_NAME) | grep $${file}.o:)" ]]; then \
		ar -rsc $(ALT_NAME) $(ALT_OBJS_PATH)$$file.o; \
		printf "$(CYAN)Linking $(WHITE)$$file $(GRAY)to $(RED)$(ALT_NAME)$(DEF_COLOR)                        \r"; \
	fi; \
	done
	@printf "$(CYAN)Creating $(ALT_EXECUTABLE)$(DEF_COLOR)                                                       \n";\
	$(CC) $(CFLAGS) $(ALT_NAME) $(LIBFT_PATH)libft.a $(MLXFLAGS) -o $(ALT_EXECUTABLE);
	@printf "$(WHITE)Created Library $(RED)$(ALT_NAME)$(DEF_COLOR)                                             \n";
	@printf "\njust execute $(GREEN)./$(ALT_EXECUTABLE) $(GRAY)to run the program\n$(DEF_COLOR)                  \n";

$(ALT_OBJS_PATH)%.o: $(ALT_SRCS_PATH)%.c
	@mkdir -p $(ALT_OBJS_PATH)
	@make ALT_LOOP --no-print-directory

ALT_LOOP: 
	@for file in $(ALT_SRCS); do \
		if [ $(ALT_SRCS_PATH)$$file.c -nt $(ALT_OBJS_PATH)$$file.o ]; then \
			printf "$(GREEN)[push_swap_debug]$(CYAN) Compiling $(WHITE)$$file.c$(DEF_COLOR)\n"; \
			printf "$(CC) $(CFLAGS) -c $(ALT_SRCS_PATH)$$file.c -o $(ALT_OBJS_PATH)$$file.o\n"; \
			$(CC) $(CFLAGS) -c $(ALT_SRCS_PATH)$$file.c -o $(ALT_OBJS_PATH)$$file.o; \
			printf "$(WHITE)$$file.c$(GREEN) OK$(DEF_COLOR)\n\n"; \
		fi; \
	done
