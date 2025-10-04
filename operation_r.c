/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byeolee <byeolee@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:09:33 by byeolee           #+#    #+#             */
/*   Updated: 2025/06/17 16:09:34 by byeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_node *a, int print_checker)
{
	int	value;

	if (a->next == NULL || a->next->next == NULL)
		return ;
	value = a->next->data;
	while (a->next)
	{
		a->data = a->next->data;
		a = a->next;
	}
	a->data = value;
	if (print_checker == 1)
		ft_printf("ra\n");
}

void	rb(t_node *b, int print_checker)
{
	int	value;

	if (b->next == NULL || b->next->next == NULL)
		return ;
	value = b->next->data;
	while (b->next)
	{
		b->data = b->next->data;
		b = b->next;
	}
	b->data = value;
	if (print_checker == 1)
		ft_printf("rb\n");
}

void	rr(t_node *a, t_node *b)
{
	ra(a, 0);
	rb(b, 0);
	ft_printf("rr\n");
}
