##
## EPITECH PROJECT, 2024
## makefile
## File description:
## No file there, just an epitech header example.
## You can even have multiple lines if you want!
##

SRC_FILES =	./src/utils.c \
			./src/main.c \
			./src/user_verification.c \
			./src/find_user.c \
			./src/print_usage.c \
			./src/find_password.c \
			./src/password_verification.c \
			./src/user_authentication.c \

OBJ_FILES = $(SRC_FILES:.c=.o)

CFLAGS = -Wall -g -I./include

LDFLAGS = -lcrypt

CC = gcc

NAME = my_sudo

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ_FILES) $(LDFLAGS)

clean:
	rm -f $(OBJ_FILES)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

set_perm:
	sudo chown root $(NAME)
	sudo chmod u+s $(NAME)

.PHONY: all clean fclean re set_perm
