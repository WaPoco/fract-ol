NAME=fractol
MLX_DIC=/home/vasili/Documents/minilibx-linux/.
CC=cc
CFLAGS=-Wall -Wextra -Werror -I$(MLX_DIC)
LFLAGS=-L$(MLX_DIC) -lmlx -lX11 -lXext -lm
SRCS=t.c
OBJS=$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
