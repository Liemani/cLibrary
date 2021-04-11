NAME		= libcLibrary.a
TESTNAME	= program.out

SRCS		= \
			  t_class/class.c \
			  t_class/utils.c \
			  t_class/t_primitiveList.c \
			  t_class/t_class.c \
			  t_class/t_null.c \
			  class/list.c \
			  class/pair.c \
			  class/dictionary.c
OBJS		= $(SRCS:.c=.o)

TESTSRCS	= program.c
TESTOBJS	= $(TESTSRCS:.c=.o)

CC			= clang
INCLUDE		= -I .
COMPILE		= $(CC) $(INCLUDE)



.PHONY:		all debug test setdebug
all:		$(NAME)
debug:		setdebug $(NAME)
test:		$(NAME) $(TESTNAME)
setdebug:
			$(eval OPTION = -g)

$(NAME):	$(OBJS)
			ar -rc $@ $^

$(TESTNAME):	setdebug $(TESTOBJS)
			$(COMPILE) $(OPTION) -L. -lcLibrary -o $(TESTNAME) $(TESTOBJS)

%.o:		%.c
			$(COMPILE) $(OPTION) -o $@ -c $<

.PHONY:		clean fclean re
clean:
			rm -f $(OBJS) $(TESTOBJS)
fclean:		clean
			rm -f $(NAME) $(TESTNAME)
re:			fclean all
