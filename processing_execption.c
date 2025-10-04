/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing_execption.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byeolee <byeolee@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:06:10 by byeolee           #+#    #+#             */
/*   Updated: 2025/06/24 12:14:53 by byeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_int(char *av)
{
	int	i;

	i = 0;
	while (av[i] == '0' || av[i] == '-')
		i++;
	if (ft_strlen(av) > (size_t)(i + 11))
		return (0);
	else if (ft_strlen(av) == (size_t)(i + 10) && av[0] == '-')
	{
		if (av[0] != '-')
			return (0);
		if (av[i + 1] - '0' >= 3)
			return (0);
		if (ft_atoi(av) > 0)
			return (0);
	}
	else if (ft_strlen(av) == (size_t)(i + 10))
	{
		if (av[i] - '0' >= 3)
			return (0);
		if (ft_atoi(av) < 0)
			return (0);
	}
	return (1);
}

static int	is_digits(char *av)
{
	int	i;

	i = 0;
	if (av[0] == '-' || av[0] == '+')
		i++;
	if (av[i] == '\0')
		return (0);
	while (av[i] != '\0')
	{
		if (ft_isdigit(av[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	exception_case(int ac, char **av)
{
	int	i;
	int	j;
	int	temp1;
	int	temp2;

	i = 0;
	while (i < ac)
	{
		if (is_int(av[i]) == 0 || is_digits(av[i]) == 0)
			return (0);
		temp1 = ft_atoi(av[i]);
		j = i + 1;
		while (j < ac)
		{
			temp2 = ft_atoi(av[j]);
			if (temp1 == temp2)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
