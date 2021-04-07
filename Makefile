NAME		= libcLibrary.a

SRCS		= \
			  t_primitiveList.c \
			  t_primitivePair.c \
			  t_classTable.c \
			  t_list.c \
			  t_pair.c \
			  t_dictionary.c
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
