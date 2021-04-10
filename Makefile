NAME		= libcLibrary.a
TESTNAME	= program.out

SRCS		= \
			  t_class/class.c \
			  t_class/utils.c \
			  t_class/primitiveList.c \
			  t_class/t_class.c \
			  t_class/t_null.c \
			  t_list.c \
OBJS		= $(SRCS:.c=.o)

TESTSRCS	= program.c
TESTOBJS	= $(TESTSRCS:.c=.o)

CC			= clang
INCLUDE		= -I t_class
COMPILE		= $(CC) $(INCLUDE)



.PHONY:		all debug setdebug
all:		$(NAME)
debug:		setdebug $(NAME)
setdebug:
			$(eval OPTION = -g)

test.out:	setdebug $(TESTOBJS)
			$(COMPILE) $(OPTION) -L. -lcLibrary -o $(TESTNAME) $(TESTOBJS)

$(NAME):	$(OBJS)
			ar -rc $@ $^

%.o:		%.c
			$(COMPILE) $(OPTION) -o $@ -c $<

.PHONY:		clean fclean re
clean:
			rm -f $(OBJS) $(TESTOBJS)
fclean:		clean
			rm -f $(NAME) $(TESTNAME)
re:			fclean all
