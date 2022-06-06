src = main.c tools.c errors.c stock_in.c link.c
FLAGS = -Wall -Wextra -Werror
CC = cc
philosopher = philosopher

all : philosopher
	
$(philosopher): $(src)	
	@$(CC) $(FLAGS) $(src) -o philo -lpthread
	@tput setaf 2; echo "PHILOSOPHER IS READY"

clean :
	@rm -f philo
	@tput setaf 1; echo "CLEAN COMPLET"

fclean : clean

re: fclean all
