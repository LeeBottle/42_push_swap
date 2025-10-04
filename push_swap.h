/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byeolee <byeolee@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:14:33 by byeolee           #+#    #+#             */
/*   Updated: 2025/06/20 18:16:22 by byeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H	

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_node {
	int				data;
	struct s_node	*next;
}	t_node;

typedef struct s_sort_data {
	int	pivot1;
	int	pivot2;
	int	ra_count;
	int	rb_count;
	int	pa_count;
	int	pb_count;
	int	size;
}	t_sort_data;

int		main(int ac, char **av);
void	data_reset(t_node *a, t_node *b, char ***new_av);
void	process_args(int *ac, char **av, char ***new_av);
int		arg_checker(int ac, char **av);
int		process_pre(int *ac, char ***av);
int		exception_case(int ac, char **av);
int		line_up_check(t_node *a);
int		count_nodes(t_node *a);
void	data_insert(t_node *a, int ac, char **av);
void	clear_av(char **arr);
void	clear_list(t_node *head);
void	clear_all(t_node *a, t_node *b, char **av);
void	push(t_node *head, int value);
void	pop(t_node *head);
void	pa(t_node *a, t_node *b);
void	pb(t_node *a, t_node *b);
void	sa(t_node *a, int print_checker);
void	sb(t_node *b, int print_checker);
void	ss(t_node *a, t_node *b);
void	ra(t_node *a, int print_checker);
void	rb(t_node *a, int print_checker);
void	rr(t_node *a, t_node *b);
void	rra(t_node *a, int print_checker);
void	rrb(t_node *b, int print_checker);
void	rrr(t_node *a, t_node *b);
void	short_sort(t_node *a, t_node *b, int size);
void	long_sort(t_node *a, t_node *b, int ac);
void	long_sort_b(t_node *b, t_node *a, int size);
void	short_sort_4_long(t_node *s, int size, char name);
void	sort_two_a(t_node *a);
void	sort_two_b(t_node *b);
void	sort_three_a(t_node *a);
void	sort_three_b(t_node *b);

#endif