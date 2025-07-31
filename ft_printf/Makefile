CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = ./srcs/ft_hexa_low.c \
	./srcs/ft_hexa_upp.c ./srcs/ft_printf.c  \
	./srcs/ft_put_unsigned.c ./srcs/ft_putchar.c \
	./srcs/ft_putnbr.c ./srcs/ft_putstr.c \
	./srcs/ft_atoi.c ./srcs/ft_putptr.c \
	./srcs/ft_hexa_low_ptr.c

OBJS = $(SRCS:.c=.o)

AR = ar rcs

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: fclean clean re all
