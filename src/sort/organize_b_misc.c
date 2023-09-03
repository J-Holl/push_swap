/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organize_b_misc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholl <jholl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 17:22:38 by jholl             #+#    #+#             */
/*   Updated: 2021/09/21 17:23:49 by jholl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	j_add_actual_max(t_data *data)
{
	t_node	*node;
	int		i;
	int		tail;
	int		temp;

	i = 0;
	node = data->pile_b->tail;
	temp = node->val;
	while (node)
	{
		if (temp >= node->val)
		{
			temp = node->val;
			tail = i;
		}
		node = node->prev;
		i++;
	}
	return (tail);
}

int	i_add_actual_max(t_data *data)
{
	t_node	*node;
	int		i;
	int		head;
	int		temp;

	i = 0;
	node = data->pile_b->head;
	temp = node->val;
	while (node)
	{
		if (temp >= node->val)
		{
			temp = node->val;
			head = i;
		}
		node = node->next;
		i++;
	}
	return (head);
}
