NAME = ft_printf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRCS = ft_printf.c ft_convert.c \
	ft_putchar.c ft_putstr.c ft_putnbr.c ft_unsint.c ft_putbase.c \
	ft_strlen.c ft_pointer.c
OBJS = $(SRCS:.c=.o)
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	ar vrcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all