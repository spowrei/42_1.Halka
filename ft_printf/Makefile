NAME = ft_printf.a

SRCS = ft_printf.c \
	   ft_printf_utils.c 
	   
OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: clean re fclean all