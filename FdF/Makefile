NAME = fdf.a

SRSCS = utils.c \
		matrix_filler.c \

OBJS = $(SRCS:.c=.o)

CFLAGS = Wall Wextra Werror

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re