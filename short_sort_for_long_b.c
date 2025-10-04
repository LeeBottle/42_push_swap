/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort_for_long_b.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byeolee <byeolee@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:10:40 by byeolee           #+#    #+#             */
/*   Updated: 2025/06/17 16:10:41 by byeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_tree_b_extend1(t_node *b, int num1, int num2, int num3)
{
	if (num2 > num3 && num1 > num3)
		sb(b, 1);
	else if (num2 > num3 && num1 < num3)
	{
		sb(b, 1);
		rb(b, 1);
		sb(b, 1);
		rrb(b, 1);
	}
	else if (num2 < num3)
	{
		sb(b, 1);
		rb(b, 1);
		sb(b, 1);
		rrb(b, 1);
		sb(b, 1);
	}
}

static void	sort_tree_b_extend2(t_node *b, int num1, int num2, int num3)
{	
	if (num2 < num3 && num1 > num3)
	{
		rb(b, 1);
		sb(b, 1);
		rrb(b, 1);
	}
	else if (num2 < num3 && num1 < num3)
	{
		rb(b, 1);
		sb(b, 1);
		rrb(b, 1);
		sb(b, 1);
	}
}

void	sort_three_b(t_node *b)
{
	int	num1;
	int	num2;
	int	num3;

	num1 = b->next->data;
	num2 = b->next->next->data;
	num3 = b->next->next->next->data;
	if (num1 < num2)
		sort_tree_b_extend1(b, num1, num2, num3);
	else
		sort_tree_b_extend2(b, num1, num2, num3);
}

void	sort_two_b(t_node *b)
{
	int	num1;
	int	num2;

	num1 = b->next->data;
	num2 = b->next->next->data;
	if (num1 < num2)
		sb(b, 1);
}
