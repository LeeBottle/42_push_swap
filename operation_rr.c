/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byeolee <byeolee@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:08:20 by byeolee           #+#    #+#             */
/*   Updated: 2025/06/17 16:08:21 by byeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_node *a, int print_checker)
{
	t_node	*curr;
	int		value1;
	int		value2;

	curr = a->next;
	while (curr->next)
		curr = curr->next;
	value1 = curr->data;
	while (a->next)
	{
		value2 = a->next->data;
		a->next->data = value1;
		value1 = value2;
		a = a->next;
	}
	if (print_checker == 1)
		ft_printf("rra\n");
}

void	rrb(t_node *b, int print_checker)
{
	t_node	*curr;
	int		value1;
	int		value2;

	curr = b->next;
	while (curr->next)
		curr = curr->next;
	value1 = curr->data;
	while (b->next)
	{
		value2 = b->next->data;
		b->next->data = value1;
		value1 = value2;
		b = b->next;
	}
	if (print_checker == 1)
		ft_printf("rrb\n");
}

void	rrr(t_node *a, t_node *b)
{
	rra(a, 0);
	rrb(b, 0);
	ft_printf("rrr\n");
}
