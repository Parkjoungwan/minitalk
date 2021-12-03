SERVER = server
CLIENT = client
CC = gcc
LIBS = -L./libft -lft
LIBFT = libft.a
FLAGS = -Wall -Werror -Wextra

all: $(LIBFT) $(SERVER) $(CLIENT)

$(LIBFT):
	@make -C libft

$(SERVER): server.o error.o minitalk.h
	@ $(CC) server.o error.o $(LIBS) -o $(SERVER)

$(CLIENT): client.o error.o minitalk.h
	@ $(CC) client.o error.o $(LIBS) -o $(CLIENT)

%.o: %.c
	@ $(CC) $(FLAGS) $< -c -I ./minitalk.h

clean:
	@ make clean -C libft
	@ rm -f *.o

fclean: clean
	@ make fclean -C libft
	@ rm -f  $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all re clean fclean
