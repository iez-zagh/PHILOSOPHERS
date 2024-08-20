RED_TEXT = \033[1;31m
GREEN_TEXT = \033[1;32m
YELLOW_TEXT = \033[1;33m
RESET_TEXT = \033[0m

NAME = philo
BONUS = philo_bonusB
R=-fsanitize=thread
# CFLAGS = -Wall -Werror -Wextra

M_SOURCES = philos.c philo.c parser1.c threads1.c threads2.c threads3.c ft_free.c

M_OBJECTS = $(M_SOURCES:.c=.o)

%.o : %.c philo.h
	@$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)
$(NAME) : $(M_OBJECTS)
	@$(CC) $(CFLAGS) $(M_OBJECTS) -o $(NAME)
	@echo "$(GREEN_TEXT)[the executable created successfully]$(RESET_TEXT)"

clean :
	@rm -rf $(M_OBJECTS)
	@echo "$(RED_TEXT)object files removed successfully$(RESET_TEXT)"

fclean : clean
	@rm -rf $(NAME)
	@echo "$(RED_TEXT)the executable files removed successfully$(RESET_TEXT)"

re : fclean all

.PHONY : clean