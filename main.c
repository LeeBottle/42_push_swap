/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byeolee <byeolee@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:14:23 by byeolee           #+#    #+#             */
/*   Updated: 2025/06/25 11:43:50 by byeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_node	a;
	t_node	b;
	char	**new_av;

	data_reset(&a, &b, &new_av);
	process_args(&ac, av, &new_av);
	if (!process_pre(&ac, &new_av))
	{
		clear_all(&a, &b, new_av);
		return (0);
	}
	data_insert(&a, ac, new_av);
	if (!line_up_check(&a))
	{
		clear_all(&a, &b, new_av);
		return (0);
	}
	if (ac <= 5)
		short_sort(&a, &b, ac);
	else
		long_sort(&a, &b, ac);
	clear_all(&a, &b, new_av);
	return (0);
}
