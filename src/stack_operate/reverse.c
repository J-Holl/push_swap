/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholl <jholl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 19:18:42 by jholl             #+#    #+#             */
/*   Updated: 2021/09/13 17:16:16 by jholl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_data *data)
{
	reverse(data->pile_a);
	ft_putstr(1, "rra\n");
}

void	rrb(t_data *data)
{
	reverse(data->pile_b);
	ft_putstr(1, "rrb\n");
}

void	rrr(t_data *data)
{
	reverse(data->pile_a);
	reverse(data->pile_b);
	ft_putstr(1, "rrr\n");
}

void	reverse(t_dlist *reverse_me)
{
	t_node	*node;

	if (reverse_me->len <= 1)
		return ;
	node = reverse_me->tail;
	reverse_me->tail = reverse_me->tail->prev;
	reverse_me->tail->next = NULL;
	node->next = reverse_me->head;
	reverse_me->head = node;
	reverse_me->head->next->prev = reverse_me->head;
	node->prev = NULL;
}
