src = main.c tools.c errors.c
FLAGS = -Wall -Wextra -Werror
CC = cc
philosopher = philosopher

all : philosopher
	
$(philosopher): $(src)	
	@$(CC) $(FLAGS) $(src) -o philo
	@tput setaf 2; echo "PHILOSOPHER IS READY"

clean :
	@rm -f push_swap
	@tput setaf 1; echo "CLEAN COMPLET"

fclean : clean

re: fclean all

fclean : clean 

re: fclean all