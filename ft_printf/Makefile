NAME	= libftprintf.a
ARFLAGS	= rc
CFLAGS	= -Wall -Wextra -Werror
INCDIR	= ./ft_printf/
SRCDIR	= ./ft_printf/
SRCS	= $(SRCDIR)ft_printf.c $(SRCDIR)print_ft_printf.c $(SRCDIR)print_diu.c
OBJS	= $(SRCS:.c=.o)
RM		= rm -f
all : $(NAME)

$(NAME) : $(OBJS)
	ar $(ARFLAGS) $(NAME) $(OBJS)

.c.o :
	gcc  $(CFLAGS) -I $(INCDIR) -c $< -o $(<:.c=.o)

.PHONY : all clean fclean re

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all 