/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholl <jholl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 18:01:45 by jholl             #+#    #+#             */
/*   Updated: 2021/09/21 16:00:07 by jholl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	eject_min(int size_chunck_cpy, t_data *data)
{
	int		i;

	while (size_chunck_cpy--)
	{
		i = 0;
		fastest_move(data);
		if (data->count_head <= data->count_tail)
		{
			while (i < data->count_head)
			{
				ra(data);
				i++;
			}
		}
		else if (data->count_head > data->count_tail)
		{
			while (i < data->count_tail + 1)
			{
				rra(data);
				i++;
			}
		}
		pb(data);
	}
}

void	small_pivot(int actual_size, t_data *data)
{	
	int		i;
	t_node	*node;
	int		temp;

	i = 0;
	temp = 0;
	node = NULL;
	while (i < actual_size)
	{
		node = data->pile_a->head;
		lf_next_pivot(temp, node, data);
		i++;
	}
}

void	sort_five(t_data *data)
{
	init_pivot(data);
	if (data->pile_a->len == 4)
	{
		small_pivot(1, data);
		eject_min(1, data);
		push_swap_three(data);
		pa(data);
	}
	else if (data->pile_a->len == 5)
	{
		small_pivot(2, data);
		eject_min(2, data);
		push_swap_three(data);
		if (data->pile_b->head->val < data->pile_b->tail->val)
			sb(data);
		pa(data);
		pa(data);
	}
}
