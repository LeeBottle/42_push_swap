/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byeolee <byeolee@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:08:49 by byeolee           #+#    #+#             */
/*   Updated: 2025/06/17 16:09:01 by byeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_node *a, t_node *b)
{
	int	value;

	if (b->next == NULL)
		return ;
	value = b->next->data;
	pop(b);
	push(a, value);
	ft_printf("pa\n");
}

void	pb(t_node *a, t_node *b)
{
	int	value;

	if (a->next == NULL)
		return ;
	value = a->next->data;
	pop(a);
	push(b, value);
	ft_printf("pb\n");
}
