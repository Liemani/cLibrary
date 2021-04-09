NAME		= libcLibrary.a

SRCS		= \
			  utils.c \
			  t_instanceList.c \
			  t_class.c \
			  t_classList.c \
OBJS		= $(SRCS:.c=.o)

CC			= clang



.PHONY:		all debug setdebug
all:		$(NAME)
debug:		setdebug $(NAME)
setdebug:
			$(eval OPTION = -g)

$(NAME):	$(OBJS)
			ar -rc $@ $^

%.o:		%.c
			$(CC) $(OPTION) -o $@ -c $<

.PHONY:		clean fclean re
clean:
			rm -f $(OBJS)
fclean:		clean
			rm -f $(NAME)
re:			fclean all
