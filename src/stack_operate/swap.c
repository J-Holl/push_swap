/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholl <jholl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 17:41:57 by jholl             #+#    #+#             */
/*   Updated: 2021/09/22 17:06:01 by jholl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_data *data)
{
	swap(data->pile_a);
	ft_putstr(1, "sa\n");
}

void	sb(t_data *data)
{
	swap(data->pile_b);
	ft_putstr(1, "sb\n");
}

void	ss(t_data *data)
{
	swap(data->pile_a);
	swap(data->pile_b);
	ft_putstr(1, "ss\n");
}

void	swap(t_dlist *to_swap)
{
	t_node	*temp;

	if (to_swap->len < 1)
		return ;
	temp = to_swap->head;
	to_swap->head = to_swap->head->next;
	temp->next = to_swap->head->next;
	to_swap->head->next = temp;
	temp->prev = to_swap->head;
	to_swap->head->prev = NULL;
	if (to_swap->len == 2)
		to_swap->tail = to_swap->head->next;
	if (to_swap->len > 2)
		temp->next->prev = temp;
}
