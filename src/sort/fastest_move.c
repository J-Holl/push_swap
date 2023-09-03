/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fastest_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholl <jholl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 13:16:12 by jholl             #+#    #+#             */
/*   Updated: 2021/09/21 17:29:38 by jholl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fastest_move_next(t_data *data)
{
	t_node	*node;

	node = data->pile_a->tail;
	while (node)
	{
		if (node->val >= data->pivot)
		{
			data->count_tail++;
			node = node->prev;
		}
		else
			node = NULL;
	}
}

void	fastest_move(t_data *data)
{
	t_node	*node;

	node = data->pile_a->head;
	data->count_head = 0;
	data->count_tail = 0;
	while (node)
	{
		if (node->val >= data->pivot)
		{
			data->count_head++;
			node = node->next;
		}
		else
			node = NULL;
	}
	fastest_move_next(data);
}

void	fastest_move_ultimate(t_node *node, t_data *data)
{
	node = data->pile_a->head;
	data->count_head = 0;
	data->count_tail = 0;
	while (node)
	{
		if (node->val > data->pivot || node->val <= data->prev_pivot)
		{
			data->count_head++;
			node = node->next;
		}
		else
			node = NULL;
	}
	node = data->pile_a->tail;
	while (node)
	{
		if (node->val > data->pivot || node->val <= data->prev_pivot)
		{
			data->count_tail++;
			node = node->prev;
		}
		else
			node = NULL;
	}
}

void	first_fastest_move_ultimate(t_node *node, t_data *data)
{
	node = data->pile_a->head;
	data->count_head = 0;
	data->count_tail = 0;
	while (node)
	{
		if (node->val > data->pivot)
		{
			data->count_head++;
			node = node->next;
		}
		else
			node = NULL;
	}
	node = data->pile_a->tail;
	while (node)
	{
		if (node->val > data->pivot)
		{
			data->count_tail++;
			node = node->prev;
		}
		else
			node = NULL;
	}
}
