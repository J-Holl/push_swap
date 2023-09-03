/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholl <jholl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 17:29:55 by jholl             #+#    #+#             */
/*   Updated: 2021/09/21 17:30:18 by jholl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	locate_n_push(t_data *data)
{
	if (data->count_head <= data->count_tail)
	{
		while (data->count_head--)
			ra(data);
	}
	else if (data->count_head > data->count_tail)
	{
		data->count_tail++;
		while (data->count_tail--)
			rra(data);
	}
	organize_b(data);
}

void	chunck_sort(int number_chunck_cpy, t_data *data)
{
	int		i;
	t_node	*node;

	i = 0;
	node = NULL;
	while (i < data->size_chunck)
	{
		if (number_chunck_cpy == (data->number_chunck - 1))
			first_fastest_move_ultimate(node, data);
		else
			fastest_move_ultimate(node, data);
		locate_n_push(data);
		i++;
	}
}

void	start_sort(t_data *data)
{
	int		number_chunck_cpy;
	int		i;

	number_chunck_cpy = data->number_chunck;
	while (number_chunck_cpy--)
	{
		data->prev_pivot = data->pivot;
		if (!number_chunck_cpy)
			data->size_chunck += data->rest;
		calculate_pivot(data);
		chunck_sort(number_chunck_cpy, data);
		if (number_chunck_cpy != (data->number_chunck - 1))
			prev_pivot_last_pos(data);
		i = 0;
		re_organize_b(data);
		while (i < data->size_chunck)
		{
			pa(data);
			ra(data);
			i++;
		}
	}
}

void	sort(t_data *data)
{
	init_pivot(data);
	init_size_chunck(data);
	init_number_chunck(data);
	start_sort(data);
}
