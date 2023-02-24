NAME	=	push_swap
BNAME	=	checker

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
	   src/argv_converter.c \
	   src/ultimate_sort.c \
	   src/block_manipulation.c

BSRCS = src/checker.c \
		src/input_error.c \
		src/init_push_swap.c \
		src/pile_functions.c \
		src/utils.c \
		src/rotation_functions.c \
		src/reverse_rotation_functions.c \
		src/push_functions.c \
		src/swap_functions.c \
		src/argv_converter.c \
		src/get_next_line.c \
		src/get_next_line_utils.c

BOBJS = $(patsubst $(SRCDIR)/%.c, $(BINDIR)/%.o, $(BSRCS))

OBJS = $(patsubst $(SRCDIR)/%.c, $(BINDIR)/%.o, $(SRCS))


CC		=	gcc

CFLAGS	=	-Wextra -Werror -Wall

RM		= rm -f

all: libft $(BINDIR) $(NAME)

$(BINDIR):
	@mkdir bin

$(BINDIR)/%.o: $(SRCDIR)/%.c
	@$(CC) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LDIR)$(LIBFT) -o $(NAME)

libft:
	@$(MAKE) -C $(LDIR)

clean:
	@$(RM) $(OBJS)
	@$(RM)r $(BINDIR)
	@$(MAKE) -C $(LDIR) clean

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LDIR) fclean

re: fclean all

bonus: $(BINDIR) $(BOBJS) libft 
	$(CC) $(CFLAGS) $(BOBJS) $(LDIR)$(LIBFT) -o $(BNAME)

visu:
	@./push_swap_visualizer/build/bin/visualizer

val:
	@valgrind  --leak-check=full --track-origins=yes --show-leak-kinds=all ./checker "3 2 1"

.PHONY: all libft
