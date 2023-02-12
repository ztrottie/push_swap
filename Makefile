NAME	=	push_swap

SRCDIR	=	src
BINDIR	=	bin
LDIR	=	libft/
LIBFT	=	libft.a
SRCS = src/push_swap.c \
	   src/rotation_functions.c \
	   src/swap_functions.c \
	   src/reverse_rotation_functions.c \
	   src/push_functions.c \
	   src/input_error.c \
	   src/ft_li_atoi.c

OBJS = $(patsubst $(SRCDIR)/%.c, $(BINDIR)/%.o, $(SRCS))


CC		=	gcc

CFLAGS	=	-Wextra -Werror -Wall

RM		= rm -f

all: $(NAME)

$(BINDIR):
	mkdir bin

$(BINDIR)/%.o: $(SRCDIR)/%.c $(BINDIR)
	$(CC) -c $< -o $@

$(NAME): $(OBJS) $(LDIR)$(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LDIR)$(LIBFT) -o $(NAME)

$(LDIR)$(LIBFT):
	$(MAKE) -C $(LDIR)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
