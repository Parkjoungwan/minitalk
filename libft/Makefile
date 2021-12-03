CC = gcc
OBJ = atoi.o bzero.o itoa.o strlen.o
NAME = libft.a
INCLUDES = ./libft.h
CFLAGS = -Wall -Werror -Wextra

%.o: %.c $(INCLUDES)
	@$(CC) $(CFLAGS) -c $< -I $(INCLUDES)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
clean:
	@rm -f $(OBJ)
fclean: clean
	@rm -f $(NAME)
re: fclean all

