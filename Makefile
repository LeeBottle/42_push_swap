NAME = push_swap
CC = cc
CFLAGS =  -Wall -Wextra -Werror

SRCS = main.c\
	processing_pre.c\
	processing_value.c\
	processing_execption.c\
	processing_post.c\
	operation_basic.c\
	operation_p.c\
	operation_s.c\
	operation_r.c\
	operation_rr.c\
	short_sort.c\
	long_sort.c\
	long_sort_b.c\
	short_sort_for_long.c\
	short_sort_for_long_b.c

LIBFTDIR = ./libft
LIBFTFILE = libft.a
LIBFT = $(LIBFTDIR)/$(LIBFTFILE)

PRTFTDIR = ./ft_printf
PRTFTFILE = libftprintf.a
PRTFT = $(PRTFTDIR)/$(PRTFTFILE)


OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFTDIR)
	make -C $(PRTFTDIR)
	$(CC) $(CFLAGS) $(OBJS) $(PRTFT) $(LIBFT) -o $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C $(LIBFTDIR) clean
	make -C $(PRTFTDIR) clean
	rm -rf $(OBJS)

fclean: clean
	make -C $(LIBFTDIR) fclean
	make -C $(PRTFTDIR) fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re