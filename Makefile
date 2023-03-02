NAME			=	push_swap
NAME2			=	checker

INCDIR			=	includes

PUSH_DIR		=	src/push_swap/
COMMON_DIR		=	src/common/
CHECKER_DIR		=	src/checker/
BINDIR			=	bin/

LDIR			=	libft/
LIBFT			=	libft.a

PUSH_SRCS		=	push_swap.c \
					xs_algo.c \
					ultimate_sort.c \
					block_manipulation.c \

COMMON_SRCS		=	argv_converter.c \
					init_push_swap.c \
					input_error.c \
					pile_functions.c \
					push_functions.c \
					reverse_rotation_functions.c \
					rotation_functions.c \
					swap_functions.c \
					utils.c

CHECKER_SRCS	=	checker.c \
					get_next_line_utils.c \
					get_next_line.c \
					operations.c

PUSH_OBJS		=	$(addprefix ${BINDIR}, ${PUSH_SRCS:.c=.o})

COMMON_OBJS		=	$(addprefix ${BINDIR}, ${COMMON_SRCS:.c=.o})

CHECKER_OBJS	=	$(addprefix ${BINDIR}, ${CHECKER_SRCS:.c=.o})

CC				=	gcc
CFLAGS			=	-Wextra -Werror -Wall

all: libft $(BINDIR) $(NAME)

$(BINDIR):
	mkdir -p bin

${BINDIR}%.o: ${PUSH_DIR}%.c
	${CC} ${CFLAGS} -I${INCDIR} -I. -c $< -o $@

${BINDIR}%.o: ${COMMON_DIR}%.c
	${CC} ${CFLAGS} -I${INCDIR} -I. -c $< -o $@

${BINDIR}%.o: ${CHECKER_DIR}%.c
	${CC} ${CFLAGS} -I${INCDIR} -I. -c $< -o $@

$(NAME): $(PUSH_OBJS) $(COMMON_OBJS)
	$(CC) $(CFLAGS) $(PUSH_OBJS) $(COMMON_OBJS) $(LDIR)$(LIBFT) -o $(NAME)

libft:
	@$(MAKE) -C $(LDIR)

clean:
	rm -fr $(BINDIR)
	@$(MAKE) -C $(LDIR) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME2)
	@$(MAKE) -C $(LDIR) fclean

re: fclean all

bonus: libft $(BINDIR) $(NAME2)

$(NAME2): $(CHECKER_OBJS) $(COMMON_OBJS)
	$(CC) $(CFLAGS) -g $(CHECKER_OBJS) $(COMMON_OBJS) $(LDIR)$(LIBFT) -o $(NAME2)

.PHONY: all libft bonus visu
