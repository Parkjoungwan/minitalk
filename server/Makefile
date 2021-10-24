NAME = server

SRCS =  src/main.c\
		src/itoa.c

CC = gcc

FLAGS = -o $(NAME) -Wall -Wextra -Werror

INCLUDES = -I./includes

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(INCLUDES) $(SRCS)

all : $(NAME)

clean :
ifeq (exist, $(shell [ -e $(NAME) ] && echo exist))
	rm $(NAME)
else
	@printf "No file to remove\n"
endif

re : clean all

.PHONY : clean
