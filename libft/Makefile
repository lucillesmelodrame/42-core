NAME = libft.a

FLAGS = -Wall -Wextra -Werror

CC = cc

OBJECTS = $(SRCS:.c=.o)

SRCS = $(wildcard ft_*.c)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
