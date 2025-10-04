/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing_pre.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byeolee <byeolee@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:12:24 by byeolee           #+#    #+#             */
/*   Updated: 2025/06/20 18:20:41 by byeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	data_reset(t_node *a, t_node *b, char ***new_av)
{
	*new_av = NULL;
	a->next = NULL;
	b->next = NULL;
}

static int	count_args(char **av)
{
	int	count;

	count = 0;
	while (av[count])
		count++;
	return (count);
}

void	process_args(int *ac, char **av, char ***new_av)
{
	char	*temp;
	char	*joined;
	int		i;

	temp = ft_strdup("");
	i = 1;
	while (i < *ac)
	{
		joined = ft_strjoin(temp, " ");
		free(temp);
		temp = ft_strjoin(joined, av[i]);
		free(joined);
		i++;
	}
	*new_av = ft_split(temp, ' ');
	*ac = count_args(*new_av);
	free(temp);
}

int	process_pre(int *ac, char ***av)
{
	if (exception_case(*ac, *av) == 0)
	{
		ft_printf("Error\n");
		return (0);
	}
	if (*ac <= 1)
		return (0);
	return (1);
}
