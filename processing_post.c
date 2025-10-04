/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing_post.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byeolee <byeolee@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:41:22 by byeolee           #+#    #+#             */
/*   Updated: 2025/06/20 15:48:28 by byeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear_av(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	clear_list(t_node *head)
{
	t_node	*curr;
	t_node	*tmp;

	curr = head->next;
	while (curr)
	{
		tmp = curr;
		curr = curr->next;
		free(tmp);
	}
	head->next = NULL;
}

void	clear_all(t_node *a, t_node *b, char **av)
{
	clear_list(a);
	clear_list(b);
	clear_av(av);
}
