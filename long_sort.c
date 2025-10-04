/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byeolee <byeolee@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:00:05 by byeolee           #+#    #+#             */
/*   Updated: 2025/06/17 16:00:05 by byeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	get_pivots(t_node *a, t_sort_data *data)
{
	int	val1;
	int	val2;
	int	i;

	val1 = a->next->data;
	i = 0;
	a = a->next;
	while (i < (data->size / 2))
	{
		a = a->next;
		i++;
	}
	val2 = a->data;
	if (val1 > val2)
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

static void	recursion_process(t_node *a, t_node *b, t_sort_data *data)
{
	int	i;

	i = 0;
	while (i++ < data->ra_count)
		rra(a, 1);
	long_sort(a, b, data->ra_count);
	long_sort_b(a, b, data->pb_count);
	i = 0;
	while (i++ < data->rb_count)
		rrb(b, 1);
	long_sort_b(a, b, data->rb_count);
}

static void	partition_to_b(t_node *a, t_node *b, t_sort_data *data)
{
	int	count;
	int	value;

	count = 0;
	while (count < data->size)
	{
		value = a->next->data;
		if (value >= data->pivot1)
		{
			ra(a, 1);
			data->ra_count++;
		}
		else if (value >= data->pivot2)
		{
			pb(a, b);
			data->pb_count++;
		}
		else
		{
			pb(a, b);
			rb(b, 1);
			data->rb_count++;
		}
		count++;
	}
}

void	long_sort(t_node *a, t_node *b, int size)
{
	t_sort_data	data;

	if (size <= 3)
	{
		short_sort_4_long(a, size, 'a');
		return ;
	}
	data.ra_count = 0;
	data.pb_count = 0;
	data.rb_count = 0;
	data.size = size;
	get_pivots(a, &data);
	partition_to_b(a, b, &data);
	recursion_process(a, b, &data);
}
