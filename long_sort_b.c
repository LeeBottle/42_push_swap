/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_sort_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byeolee <byeolee@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:11:31 by byeolee           #+#    #+#             */
/*   Updated: 2025/06/18 18:00:26 by byeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	get_pivots_b(t_node *b, t_sort_data *data)
{
	int	val1;
	int	val2;
	int	i;

	val1 = b->next->data;
	i = 0;
	b = b->next;
	while (i < (data->size / 2))
	{
		b = b->next;
		i++;
	}
	val2 = b->data;
	if (val1 < val2)
	{
		data->pivot1 = val1;
		data->pivot2 = val2;
	}
	else
	{
		data->pivot1 = val2;
		data->pivot2 = val1;
	}
}

static void	recursion_process_b(t_node *a, t_node *b, t_sort_data *data)
{
	int	i;
	int	rrr_count;

	long_sort(a, b, data->pa_count);
	if (data->ra_count < data->rb_count)
		rrr_count = data->ra_count;
	else
		rrr_count = data->rb_count;
	i = 0;
	while (i++ < rrr_count)
		rrr(a, b);
	i = 0;
	while (i++ < data->ra_count - rrr_count)
		rra(a, 1);
	i = 0;
	while (i++ < data->rb_count - rrr_count)
		rrb(b, 1);
	long_sort(a, b, data->ra_count);
	long_sort_b(a, b, data->rb_count);
}

static void	partition_to_a(t_node *a, t_node *b, t_sort_data *data)
{
	int	count;
	int	value;

	count = 0;
	while (count < data->size)
	{
		value = b->next->data;
		if (value <= data->pivot1)
		{
			rb(b, 1);
			data->rb_count++;
		}
		else if (value > data->pivot2)
		{
			pa(a, b);
			data->pa_count++;
		}
		else
		{
			pa(a, b);
			ra(a, 1);
			data->ra_count++;
		}
		count++;
	}
}

void	long_sort_b(t_node *a, t_node *b, int size)
{
	t_sort_data	data;

	if (size <= 3)
	{
		short_sort_4_long(b, size, 'b');
		while (size-- > 0)
			pa(a, b);
		return ;
	}
	data.ra_count = 0;
	data.pa_count = 0;
	data.rb_count = 0;
	data.size = size;
	get_pivots_b(b, &data);
	partition_to_a(a, b, &data);
	recursion_process_b(a, b, &data);
}
