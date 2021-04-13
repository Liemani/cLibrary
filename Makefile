NAME		= libcLibrary.a
TESTNAME	= program.out

SRCS		= \
			  kernelClass/class.c \
			  kernelClass/utils.c \
			  kernelClass/kernelList.c \
			  kernelClass/pointer.c \
			  kernelClass/string.c \
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
test:		fclean setdebug $(NAME) $(TESTNAME)
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
