/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_basic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byeolee <byeolee@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:40:04 by byeolee           #+#    #+#             */
/*   Updated: 2025/06/20 17:29:53 by byeolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_node *head, int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->data = value;
	new_node->next = head->next;
	head->next = new_node;
}

void	pop(t_node *head)
{
	t_node	*first;
	int		temp;

	if (head->next == NULL)
		exit(1);
	first = head->next;
	temp = first->data;
	head->next = first->next;
	free(first);
}
