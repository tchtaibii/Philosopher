NAME = philo
FLAGS = -Wall -Wextra -Werror
src = main.c tools.c stock_in.c link.c func.c \
		norm_routine.c norm_death.c
CC = cc 

all : philo $(src) 

$(NAME) : $(src)	
	@$(CC) $(FLAGS) $(src) -o $(NAME) -lpthread
	@tput setaf 2; echo "PHILOSOPHER IS READY"

clean :
	@rm -f philo
	@tput setaf 1; echo "CLEAN COMPLET"

fclean : clean 

re: fclean all