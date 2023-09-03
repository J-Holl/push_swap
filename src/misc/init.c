/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholl <jholl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 21:53:58 by jholl             #+#    #+#             */
/*   Updated: 2021/09/21 22:41:45 by jholl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

void	init_data(t_data *data)
{
	data->pile_a = NULL;
	data->pile_b = NULL;
}

void	init_number_chunck(t_data *data)
{
	int	len;

	len = data->pile_a->len;
	if (len <= 10)
		data->number_chunck = 1;
	if (len > 10 && len <= 100)
		data->number_chunck = 5;
	if (len > 100 && len <= 500)
		data->number_chunck = 10;
	if (len > 500)
		data->number_chunck = 10;
	data->rest = len % data->number_chunck;
}

void	init_size_chunck(t_data *data)
{
	int	len;

	len = data->pile_a->len;
	if (len <= 10)
		data->size_chunck = data->pile_a->len;
	if (len > 10 && len <= 100)
		data->size_chunck = len / 5;
	if (len > 100 && len <= 500)
		data->size_chunck = len / 10;
	if (len > 500)
		data->size_chunck = len / 10;
}

void	init_pivot(t_data *data)
{
	t_node	*node;

	data->pivot = data->pile_a->head->val;
	node = data->pile_a->head;
	while (node)
	{
		if (data->pivot > node->val)
			data->pivot = node->val;
		node = node->next;
	}
}
