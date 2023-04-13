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
NAME_BONUS = checker_bonus.a
LIBFT_PATH = libs/
INC = -Iincludes/ -I$(LIBFT_PATH)
EXECUTABLE = push_swap
ALT_EXECUTABLE = push_swap_debug
BONUS_EXECUTABLE = checker_bonus
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
	  print_stack \
	  get_current_total_cost \
	  parsing_utils \
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
		   parsing_utils

BSRCS = \
		push_bonus \
		rotate_bonus \
		reverse_rotate_bonus \
		swap_bonus \
		checker_bonus \
		utils_bonus \
		has_duplicates_bonus

SRCS_PATH = src/
BSRCS_PATH = src/bonus/
OBJS_PATH = objs/
BOBJS_PATH = objs/bobjs/
ALT_SRCS_PATH = src/
ALT_OBJS_PATH = alt_objs/
LIBFT_OBJS_PATH = $(LIBFT_PATH)objs/

OBJS = $(patsubst %, $(OBJS_PATH)%.o, $(SRCS))
ALT_OBJS = $(patsubst %, $(ALT_OBJS_PATH)%.o, $(ALT_SRCS))
BOBJS = $(patsubst %, $(BOBJS_PATH)%.o, $(BSRCS))
MOD_OBJ = $(shell find $(OBJS_PATH)*.o -newer $(NAME))
ALT_MOD_OBJ = $(shell find $(ALT_OBJS_PATH)*.o -newer $(ALT_NAME))
BONUS_MOD_OBJS = $(shell find $(BOBJS_PATH)*.o -newer $(NAME_BONUS))
LIBFT_OBJS = $(patsubst %, $(LIBFT_OBJS_PATH)%.o, $(LIBFT_SRCS))

all: $(NAME)

make_libft:
	@make -C $(LIBFT_PATH) --no-print-directory

test5: all
	@if [[ -z "$$(ls -A shuf5)" ]]; then \
		cc -O3 shuf5.c libs/ft_free_arr.c -o shuf5; \
		./shuf5; \
	else \
		./shuf5; \
	fi

test8: all
	@if [[ -z "$$(ls -A shuf8)" ]]; then \
		cc -O3 shuf8.c libs/ft_free_arr.c -o shuf8; \
		./shuf8; \
	else \
		./shuf8; \
	fi


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
	$(CC) $(CFLAGS) $(NAME) $(LIBFT_PATH)libft.a -o $(EXECUTABLE);
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
	@rm -rf $(BOBJS_PATH)
	@rm -rf $(ALT_OBJS_PATH)

clean_nolib:
	@rm -rf $(OBJS_PATH)
	@rm -rf $(BOBJS_PATH)
	@rm -rf $(ALT_OBJS_PATH)

fclean_nolib: clean_nolib
	@rm -f $(EXECUTABLE)
	@rm -f $(ALT_EXECUTABLE)
	@rm -f $(BONUS_EXECUTABLE)
	@rm -f $(NAME)
	@rm -f $(ALT_NAME)
	@rm -f $(NAME_BONUS)
	@rm -f shuf100
	@rm -f shuf5
	@rm -f shuf8

fclean: fclean_nolib
	@make -C $(LIBFT_PATH) fclean --no-print-directory

re: fclean all

re_nolib: fclean_nolib all

re_debug: fclean_nolib debug
	

### ALTERNATIVE COMPILATION THAT PRINTS THE OPERATIONS AS THEY HAPPEN ###

debug: make_libft $(ALT_OBJS)
	@printf "\n$(YELLOW)Linking FDF Objects to Library...$(DEF_COLOR)\n";
	@for file in $(ALT_MOD_OBJ); do \
		printf "$(CYAN)Linking $(WHITE)$$file $(GRAY)to $(RED)$(ALT_NAME)$(DEF_COLOR)                        \r"; \
		ar -rsc $(ALT_NAME) $$file; \
	done
	@for file in $(ALT_SRCS); do \
		if [[ -z "$$(nm $(ALT_NAME) | grep $${file}.o:)" ]]; then \
		ar -rsc $(ALT_NAME) $(ALT_OBJS_PATH)$$file.o; \
		printf "$(CYAN)Linking $(WHITE)$$file $(GRAY)to $(RED)$(ALT_NAME)$(DEF_COLOR)                        \r"; \
	fi; \
	done
	@printf "$(CYAN)Creating $(ALT_EXECUTABLE)$(DEF_COLOR)                                                    \n";\
	$(CC) $(CFLAGS) $(ALT_NAME) $(LIBFT_PATH)libft.a -o $(ALT_EXECUTABLE);
	@printf "$(WHITE)Created Library $(RED)$(ALT_NAME)$(DEF_COLOR)                                            \n";
	@printf "\njust execute $(GREEN)./$(ALT_EXECUTABLE) $(GRAY)to run the program\n$(DEF_COLOR)               \n";

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

#################################### BONUS PROJECT #############################################

bonus: make_libft $(NAME_BONUS)

$(NAME_BONUS): $(BOBJS) make_libft
	@printf "\n$(YELLOW)Linking FDF Objects to Library...$(DEF_COLOR)\n";
	@for file in $(BONUS_MOD_OBJS); do \
		printf "$(CYAN)Linking $(WHITE)$$file $(GRAY)to $(RED)$(NAME_BONUS)$(DEF_COLOR)                        \r"; \
		ar -rsc $(NAME_BONUS) $$file; \
	done
	@for file in $(BSRCS); do \
		if [[ -z "$$(nm $(NAME_BONUS) | grep $${file}.o:)" ]]; then \
		ar -rsc $(NAME_BONUS) $(BOBJS_PATH)$$file.o; \
		printf "$(CYAN)Linking $(WHITE)$$file $(GRAY)to $(RED)$(NAME_BONUS)$(DEF_COLOR)                        \r"; \
	fi; \
	done
	@printf "$(CYAN)Creating $(BONUS_EXECUTABLE)$(DEF_COLOR)                                                    \n";\
	$(CC) $(CFLAGS) $(NAME_BONUS) $(LIBFT_PATH)libft.a -o $(BONUS_EXECUTABLE);
	@printf "$(WHITE)Created Library $(RED)$(NAME_BONUS)$(DEF_COLOR)                                            \n";
	@printf "\njust execute $(GREEN)./$(BONUS_EXECUTABLE) $(GRAY)to run the program\n$(DEF_COLOR)               \n";

$(BOBJS_PATH)%.o: $(BSRCS_PATH)%.c
	@mkdir -p $(BOBJS_PATH)
	@make BONUS_LOOP --no-print-directory

BONUS_LOOP: 
	@for file in $(BSRCS); do \
		if [ $(BSRCS_PATH)$$file.c -nt $(BOBJS_PATH)$$file.o ]; then \
			printf "$(GREEN)[checker_bonus]$(CYAN) Compiling $(WHITE)$$file.c$(DEF_COLOR)\n"; \
			printf "$(CC) $(CFLAGS) -c $(BONUS_SRCS_PATH)$$file.c -o $(BOBJS_PATH)$$file.o\n"; \
			$(CC) $(CFLAGS) -c $(BSRCS_PATH)$$file.c -o $(BOBJS_PATH)$$file.o; \
			printf "$(WHITE)$$file.c$(GREEN) OK$(DEF_COLOR)\n\n"; \
		fi; \
	done
