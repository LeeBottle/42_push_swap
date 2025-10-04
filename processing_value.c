/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byeolee <byeolee@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:40:59 by byeolee           #+#    #+#             */
/*   Updated: 2025/06/19 12:45:47 by byeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_digits(char *av)
{
	int	i;

	if (!av)
		return (0);
	i = 0;
	if (av[0] == '-' || av[0] == '+')
		i++;
	while (av[i] != '\0')
	{
		if (ft_isdigit(av[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

void	data_insert(t_node *a, int ac, char **av)
{
	int		i;
	int		value;

	i = ac - 1;
	if (is_digits(av[0]))
	{
		while (i >= 0)
		{
			value = ft_atoi(av[i]);
			push(a, value);
			i--;
		}
	}
	else
	{
		while (i > 0)
		{
			if (!av[i] || !is_digits(av[i]))
				return ;
			value = ft_atoi(av[i]);
			push(a, value);
			i--;
		}
	}
}

int	line_up_check(t_node *a)
{
	while (a->next && a->next->next)
	{
		if (a->next->data > a->next->next->data)
			return (1);
		a = a->next;
	}
	return (0);
}

int	count_nodes(t_node *a)
{
	int		count;
	t_node	*current;

	count = 0;
	current = a->next;
	while (current)
	{
		count++;
		current = current->next;
	}
	return (count);
}
