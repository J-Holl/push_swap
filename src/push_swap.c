/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholl <jholl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 14:25:23 by jholl             #+#    #+#             */
/*   Updated: 2021/09/22 15:47:22 by jholl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pile_is_sorted(t_data *data)
{
	t_node	*node;
	int		prev;

	if (!data->pile_a->head)
		return (0);
	node = data->pile_a->head;
	prev = node->val;
	while (node)
	{
		if (prev > node->val)
			return (0);
		prev = node->val;
		node = node->next;
	}
	return (1);
}

void	push_swap_two(t_data *data)
{
	if (data->pile_a->head->val > data->pile_a->tail->val)
		sa(data);
}

void	push_swap_three(t_data *data)
{
	if (data->pile_a->head->val > data->pile_a->tail->val)
	{
		if (data->pile_a->head->val < data->pile_a->head->next->val)
			rra(data);
		else if (data->pile_a->tail->val > data->pile_a->tail->prev->val)
			ra(data);
		else
		{
			ra(data);
			sa(data);
		}
	}
	else
	{
		if (data->pile_a->head->val > data->pile_a->head->next->val)
			sa(data);
		else if (data->pile_a->tail->val < data->pile_a->tail->prev->val)
		{
			sa(data);
			ra(data);
		}
	}
}

void	push_swap(t_data *data)
{
	if (data->pile_a->len <= 1)
		return ;
	if (data->pile_a->len == 2)
		push_swap_two(data);
	if (data->pile_a->len == 3)
		push_swap_three(data);
	if (data->pile_a->len == 4 || data->pile_a->len == 5)
		sort_five(data);
	if (data->pile_a->len > 5)
		sort(data);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 1)
		return (0);
	init_data(&data);
	parsing(ac, av, &data);
	if (!pile_is_sorted(&data))
		push_swap(&data);
	exit_no_error(&data);
	return (0);
}
