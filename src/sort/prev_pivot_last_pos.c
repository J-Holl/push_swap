/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prev_pivot_last_pos.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholl <jholl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 17:13:35 by jholl             #+#    #+#             */
/*   Updated: 2021/09/21 17:19:24 by jholl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lf_prev_pivot_head(t_data *data)
{
	t_node	*node;
	int		i;

	i = 0;
	node = data->pile_a->head;
	while (node)
	{
		if (data->prev_pivot == node->val)
			node = NULL;
		if (node)
			i++;
		if (node)
			node = node->next;
	}
	return (i);
}

int	lf_prev_pivot_tail(t_data *data)
{
	t_node	*node;
	int		j;

	j = 0;
	node = data->pile_a->tail;
	while (node)
	{
		if (data->prev_pivot == node->val)
			node = NULL;
		if (node)
			j++;
		if (node)
			node = node->prev;
	}
	return (j);
}

void	prev_pivot_last_pos(t_data *data)
{
	int		i;
	int		j;
	int		x;

	if (data->pile_a->tail->val == data->prev_pivot)
		return ;
	i = lf_prev_pivot_head(data);
	j = lf_prev_pivot_tail(data);
	x = 0;
	if (i <= j)
	{
		while (x < i + 1)
		{
			ra(data);
			x++;
		}
	}
	else
	{
		while (x < j)
		{
			rra(data);
			x++;
		}
	}
}
