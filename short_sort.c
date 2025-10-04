/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byeolee <byeolee@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:13:56 by byeolee           #+#    #+#             */
/*   Updated: 2025/06/18 18:10:17 by byeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_two(t_node *a)
{
	int	num1;
	int	num2;

	num1 = a -> next -> data;
	num2 = a -> next -> next -> data;
	if (num1 > num2)
		sa(a, 1);
}

static void	sort_three(t_node *a)
{
	int	num1;
	int	num2;
	int	num3;

	num1 = a -> next -> data;
	num2 = a -> next -> next -> data;
	num3 = a -> next -> next -> next -> data;
	if (num1 < num3 && num3 < num2)
	{
		sa(a, 1);
		ra(a, 1);
	}
	else if (num2 < num1 && num1 < num3)
		sa(a, 1);
	else if (num2 < num3 && num3 < num1)
		ra(a, 1);
	else if (num3 < num1 && num1 < num2)
		rra(a, 1);
	else if (num3 < num2 && num2 < num1)
	{
		sa(a, 1);
		rra(a, 1);
	}
}

static void	find_values(t_node *a, int *min1, int *min2)
{
	int	first;
	int	second;

	first = a->next->data;
	second = a->next->data;
	a = a->next->next;
	while (a)
	{
		if (a->data < first)
		{
			second = first;
			first = a->data;
		}
		else if ((a->data < second && a->data != first) || first == second)
			second = a->data;
		a = a->next;
	}
	*min1 = first;
	*min2 = second;
}

static void	sort_else(t_node *a, t_node *b, int size)
{
	int	min1;
	int	min2;
	int	count;
	int	first;
	int	second;

	find_values(a, &min1, &min2);
	count = 0;
	while (count < size)
	{
		if (a->next->data == min1)
			pb(a, b);
		else if (a->next->data == min2)
			pb(a, b);
		else
			ra(a, 1);
		count++;
	}
	short_sort(a, b, size - 2);
	first = b -> next -> data;
	second = b -> next -> next -> data;
	if (first < second)
		sb(b, 1);
	pa(a, b);
	pa(a, b);
}

void	short_sort(t_node *a, t_node *b, int size)
{
	if (size == 2)
		sort_two(a);
	else if (size == 3)
		sort_three(a);
	else if (size <= 5)
		sort_else(a, b, size);
}
