/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholl <jholl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 17:20:23 by jholl             #+#    #+#             */
/*   Updated: 2021/09/21 17:21:05 by jholl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lf_next_pivot(int temp, t_node *node, t_data *data)
{
	int	temp_init;

	temp_init = 0;
	while (node)
	{
		if (node->val > data->pivot && !temp_init)
		{
			temp = node->val;
			temp_init = 1;
		}
		if (temp_init)
			if (temp != data->pivot)
				if (node->val < temp && node->val > data->pivot)
					temp = node->val;
		node = node->next;
	}
	if (temp_init)
		data->pivot = temp;
}

void	calculate_pivot(t_data *data)
{
	int		i;
	t_node	*node;
	int		temp;

	if (!data->pile_b)
		i = 1;
	else
		i = 0;
	temp = 0;
	node = NULL;
	while (i < data->size_chunck)
	{
		node = data->pile_a->head;
		lf_next_pivot(temp, node, data);
		i++;
	}
}
