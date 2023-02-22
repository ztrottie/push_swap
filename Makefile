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

BSRCS = src/bonus.c \
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
	@$(CC) $(CFLAGS) $(BOBJS) $(LDIR)$(LIBFT) -o $(BNAME)

visu:
	@./push_swap_visualizer/build/bin/visualizer

val:
	@valgrind  -s --leak-check=full --track-origins=yes --show-leak-kinds=all ./push_swap 75 59 94 70 1 46 48 24 47 19 90 20 81 72 12 43 55 50 60 41 49 32 69 7 85 83 39 52 5 96 99 98 71 42 65 91 54 56 82 95 73 97 28 11 62 87 17 25 2 67 77 4 36 14 30 80 34 88 76 79 22 45 89 13 33 86 29 18 74 66 51 3 57 58 61 35 100 16 92 53 27 21 26 93 68 44 78 31 6 64 10 9 37 84 23 40 15 63 8 38

.PHONY: all libft
