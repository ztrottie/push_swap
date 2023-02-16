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
	   src/init_push_swap.c \
	   src/pile_functions.c \
	   src/utils.c \
	   src/xs_algo.c \
	   src/argv_converter.c

OBJS = $(patsubst $(SRCDIR)/%.c, $(BINDIR)/%.o, $(SRCS))


CC		=	gcc

CFLAGS	=	-Wextra -Werror -Wall

RM		= rm -f

all: libft $(BINDIR) $(NAME)

$(BINDIR):
	mkdir bin

$(BINDIR)/%.o: $(SRCDIR)/%.c
	$(CC) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDIR)$(LIBFT) -o $(NAME)

libft:
	$(MAKE) -C $(LDIR)

clean:
	$(RM) $(OBJS)
	$(RM)r $(BINDIR)
	$(MAKE) -C $(LDIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LDIR) fclean

re: fclean all

visu:
	./push_swap_visualizer/build/bin/visualizer

val:
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./push_swap 4 3 2 1

.PHONY: all libft
