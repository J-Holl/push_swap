/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholl <jholl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 16:25:04 by jholl             #+#    #+#             */
/*   Updated: 2021/09/13 17:19:19 by jholl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_data *data)
{
	push(data->pile_b, &data->pile_a, data);
	ft_putstr(1, "pa\n");
}

void	pb(t_data *data)
{
	push(data->pile_a, &data->pile_b, data);
	ft_putstr(1, "pb\n");
}

void	push(t_dlist *push, t_dlist **pushed, t_data *data)
{
	t_dlist	*temp_pushed;
	t_node	*node;

	temp_pushed = *pushed;
	if (!push)
		return ;
	if (push->len == 0)
		return ;
	node = push->head;
	push->head = push->head->next;
	if (push->head)
		push->head->prev = NULL;
	if (!push->head)
		push->tail = NULL;
	if (!temp_pushed)
	{
		*pushed = dlist_new_nm(node, data);
	}
	else
	{
		dlist_add_front_nm(node, pushed, data);
	}
	push->len--;
}
