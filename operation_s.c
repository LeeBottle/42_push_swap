/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byeolee <byeolee@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:07:44 by byeolee           #+#    #+#             */
/*   Updated: 2025/06/17 16:07:44 by byeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node *a, int print_checker)
{
	int	value1;
	int	value2;

	if (a->next == NULL || a->next->next == NULL)
		return ;
	value1 = a->next->data;
	pop(a);
	value2 = a->next->data;
	pop(a);
	push(a, value1);
	push(a, value2);
	if (print_checker == 1)
		ft_printf("sa\n");
}

void	sb(t_node *b, int print_checker)
{
	int	value1;
	int	value2;

	if (b->next == NULL || b->next->next == NULL)
		return ;
	value1 = b->next->data;
	pop(b);
	value2 = b->next->data;
	pop(b);
	push(b, value1);
	push(b, value2);
	if (print_checker == 1)
		ft_printf("sb\n");
}

void	ss(t_node *a, t_node *b)
{
	sa(a, 0);
	sb(b, 0);
	ft_printf("ss\n");
}
