/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_organize_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholl <jholl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:51:11 by jholl             #+#    #+#             */
/*   Updated: 2021/09/21 17:26:37 by jholl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lf_data_pivot_tail(t_data *data)
{
	int		j;
	t_node	*node;

	node = data->pile_b->tail;
	j = 0;
	while (node)
	{
		if (node->val == data->pivot)
			node = NULL;
		if (node)
			j++;
		if (node)
			node = node->prev;
	}
	return (j);
}

int	lf_data_pivot_head(t_data *data)
{
	int		i;
	t_node	*node;

	node = data->pile_b->head;
	i = 0;
	while (node)
	{
		if (node->val == data->pivot)
			node = NULL;
		if (node)
			i++;
		if (node)
			node = node->next;
	}
	return (i);
}

void	re_organize_b(t_data *data)
{
	int	i;
	int	j;
	int	x;

	i = lf_data_pivot_head(data);
	j = lf_data_pivot_tail(data);
	x = 0;
	if (i <= j)
	{
		while (x < i + 1)
		{
			rb(data);
			x++;
		}
	}
	else
	{
		while (x < j)
		{
			rrb(data);
			x++;
		}
	}
}
