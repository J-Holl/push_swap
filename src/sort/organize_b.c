/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organize_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholl <jholl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:17:55 by jholl             #+#    #+#             */
/*   Updated: 2021/09/21 16:49:20 by jholl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	locate_next_push_tail(int *tail, t_node *node, int ti, t_data *data)
{
	int	temp;
	int	i;

	i = 0;
	while (node)
	{
		if (data->pile_a->head->val < node->val && !ti)
		{
			temp = node->val;
			ti = 1;
			*tail = i;
		}
		if (ti)
		{
			if (node->val < temp && node->val > data->pile_a->head->val)
			{
				temp = node->val;
				*tail = i;
			}
		}
		node = node->prev;
		i++;
	}
	if (!ti)
		*tail = j_add_actual_max(data);
}

void	locate_next_push_head(int *head, t_node *node, int ti, t_data *data)
{
	int	temp;
	int	i;

	i = 0;
	while (node)
	{
		if (data->pile_a->head->val < node->val && !ti)
		{
			temp = node->val;
			ti = 1;
			*head = i;
		}
		if (ti)
		{
			if (node->val < temp && node->val > data->pile_a->head->val)
			{
				temp = node->val;
				*head = i;
			}
		}
		node = node->next;
		i++;
	}
	if (!ti)
		*head = i_add_actual_max(data);
}

void	position_next_push(int *head, int *tail, t_data *data)
{
	int	i;

	i = 0;
	if (*head <= *tail)
	{
		while (i < *head)
		{
			rb(data);
			i++;
		}
	}
	else
	{
		while (i < *tail + 1)
		{
			rrb(data);
			i++;
		}
	}
}

void	organize_b(t_data *data)
{
	int	head;
	int	tail;
	int	ti;

	if (!data->pile_b)
		pb(data);
	else if (!data->pile_b->head)
		pb(data);
	else if (data->pile_b->head == data->pile_b->tail)
		pb(data);
	else
	{
		ti = 0;
		locate_next_push_head(&head, data->pile_b->head, ti, data);
		locate_next_push_tail(&tail, data->pile_b->tail, ti, data);
		position_next_push(&head, &tail, data);
		pb(data);
	}
}
