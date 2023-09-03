/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_no_malloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholl <jholl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 17:57:38 by jholl             #+#    #+#             */
/*   Updated: 2021/09/03 17:06:40 by jholl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	dlist_add_front_nm(t_node *node, t_dlist **dlist, t_data *data)
{
	if (!*dlist)
		exit_error(data);
	node->prev = NULL;
	if ((*dlist)->head)
	{
		(*dlist)->head->prev = node;
		node->next = (*dlist)->head;
		(*dlist)->head = node;
	}
	else
	{
		(*dlist)->head = node;
		(*dlist)->tail = node;
		node->next = NULL;
	}	
	(*dlist)->len++;
}

t_dlist	*dlist_new_nm(t_node *node, t_data *data)
{
	t_dlist	*dlist;

	dlist = (t_dlist *)malloc(sizeof(t_dlist) * 1);
	if (!dlist)
		exit_error(data);
	dlist->len = 1;
	dlist->head = node;
	dlist->tail = node;
	node->next = NULL;
	node->prev = NULL;
	return (dlist);
}
