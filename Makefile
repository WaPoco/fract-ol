NAME=fractol
NAME_BONUS=fractol_bonus
CC=cc
CFLAGS=-Wall -Wextra -Werror
LFLAGS=-L. -lmlx -lX11 -lXext -lm  -L./ft_printf -lftprintf -L./Libft -lft
HEADER=fractol.h
SRCS=complex.c fractol.c events.c imag.c
SRCS_BONUS=complex.c fractol_bonus.c events_bonus.c imag.c
OBJS=$(SRCS:.c=.o)
OBJS_BONUS=$(SRCS_BONUS:.c=.o)

all: Libmlx Libft ft_printf $(NAME)

Libmlx:
	make -C ./minilibx-linux

Libft:
	make -C ./Libft

ft_printf:
	make -C ./ft_printf

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LFLAGS) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

bonus: Libmlx Libft ft_printf $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) $(OBJS_BONUS) $(LFLAGS) -o $(NAME_BONUS)

clean:
	rm -f $(OBJS)
	rm -f $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME) libmlx.a $(NAME_BONUS)
	make -C ./Libft fclean
	make -C ./ft_printf fclean

re: fclean all

.PHONY: clean fclean all re Libft ft_printf Libmlx bonus
