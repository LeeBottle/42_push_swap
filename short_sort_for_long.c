/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort_for_long.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byeolee <byeolee@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:58:43 by byeolee           #+#    #+#             */
/*   Updated: 2025/06/18 16:58:52 by byeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_tree_a_extend1(t_node *a, int num1, int num2, int num3)
{
	if (num2 < num3 && num1 < num3)
		sa(a, 1);
	else if (num2 < num3 && num1 > num3)
	{
		sa(a, 1);
		ra(a, 1);
		sa(a, 1);
		rra(a, 1);
	}
	else if (num2 > num3)
	{
		sa(a, 1);
		ra(a, 1);
		sa(a, 1);
		rra(a, 1);
		sa(a, 1);
	}
}

static void	sort_tree_a_extend2(t_node *a, int num1, int num2, int num3)
{
	if (num2 > num3 && num1 < num3)
	{
		ra(a, 1);
		sa(a, 1);
		rra(a, 1);
	}
	else if (num2 > num3 && num1 > num3)
	{
		ra(a, 1);
		sa(a, 1);
		rra(a, 1);
		sa(a, 1);
	}
}

void	sort_three_a(t_node *a)
{
	int	num1;
	int	num2;
	int	num3;

	num1 = a->next->data;
	num2 = a->next->next->data;
	num3 = a->next->next->next->data;
	if (num1 > num2)
		sort_tree_a_extend1(a, num1, num2, num3);
	else
		sort_tree_a_extend2(a, num1, num2, num3);
}

void	sort_two_a(t_node *a)
{
	int	num1;
	int	num2;

	num1 = a->next->data;
	num2 = a->next->next->data;
	if (num1 > num2)
		sa(a, 1);
}

void	short_sort_4_long(t_node *s, int size, char name)
{
	if (size == 2 && name == 'a')
		sort_two_a(s);
	else if (size == 2 && name == 'b')
		sort_two_b(s);
	else if (size == 3 && name == 'a')
		sort_three_a(s);
	else if (size == 3 && name == 'b')
		sort_three_b(s);
}
