/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholl <jholl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 18:46:27 by jholl             #+#    #+#             */
/*   Updated: 2021/09/13 17:16:41 by jholl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_data *data)
{
	rotate(data->pile_a);
	ft_putstr(1, "ra\n");
}

void	rb(t_data *data)
{
	rotate(data->pile_b);
	ft_putstr(1, "rb\n");
}

void	rr(t_data *data)
{
	rotate(data->pile_a);
	rotate(data->pile_b);
	ft_putstr(1, "rr\n");
}

void	rotate(t_dlist *rotate_me)
{
	t_node	*node;

	if (rotate_me->len <= 1)
		return ;
	node = rotate_me->head;
	rotate_me->head = rotate_me->head->next;
	rotate_me->head->prev = NULL;
	node->prev = rotate_me->tail;
	rotate_me->tail = node;
	rotate_me->tail->prev->next = rotate_me->tail;
	node->next = NULL;
}
