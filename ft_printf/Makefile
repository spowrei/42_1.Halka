NAME = libftprintf.a

SRCS = ft_printf.c \
	   ft_printf_utils.c 
	   
OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra

RM = rm -rf

LIBFT_MAKE = make -C libft

all: $(NAME)

$(NAME): $(OBJS)
	$(LIBFT_MAKE)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)
	$(LIBFT_MAKE) clean

fclean:	clean
	$(RM) $(NAME)
	$(LIBFT_MAKE) fclean

re:	fclean all

.PHONY: clean re fclean all