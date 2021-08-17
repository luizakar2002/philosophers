NAME	= philo

SRCS	= $(wildcard *.c)
# SRCS = lex.c \
# 		utils.c \
# 		execution.c

OBJS	= $(SRCS:%.c=%.o)

GCC		= gcc -Wall -Werror -Wextra 
RM		= rm -rf

all:	$(NAME)

$(NAME):	$(OBJS)
			$(GCC) $(OBJS) -o $(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
