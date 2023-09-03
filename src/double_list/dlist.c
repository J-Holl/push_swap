/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholl <jholl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 14:23:56 by jholl             #+#    #+#             */
/*   Updated: 2021/09/22 16:38:13 by jholl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dlist	*dlist_new(int val)
{
	t_dlist	*dlist;
	t_node	*node;

	dlist = (t_dlist *)malloc(sizeof(t_dlist) * 1);
	if (!dlist)
		return (NULL);
	node = (t_node *)malloc(sizeof(t_node) * 1);
	if (!node)
		return (NULL);
	dlist->len = 1;
	dlist->head = node;
	dlist->tail = node;
	node->val = val;
	node->next = NULL;
	node->prev = NULL;
	return (dlist);
}

void	dlist_add_front(int val, t_dlist **dlist, t_data *data)
{
	t_node	*node;

	if (!*dlist)
		exit_error(data);
	node = (t_node *)malloc(sizeof(t_node) * 1);
	if (!node)
		exit_error(data);
	node->val = val;
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

void	dlist_add_back(int val, t_dlist **dlist, t_data *data)
{
	t_node	*node;

	if (!*dlist)
		exit_error(data);
	node = (t_node *)malloc(sizeof(t_node) * 1);
	if (!node)
		exit_error(data);
	node->val = val;
	node->next = NULL;
	if ((*dlist)->tail)
	{
		(*dlist)->tail->next = node;
		node->prev = (*dlist)->tail;
		(*dlist)->tail = node;
	}
	else
	{
		(*dlist)->head = node;
		(*dlist)->tail = node;
		node->prev = NULL;
	}
	(*dlist)->len++;
}

void	dlist_del(t_dlist *dlist)
{
	t_node	*node;

	node = dlist->head;
	if (node)
	{
		while (node->next)
		{
			node = node->next;
			if (node->prev)
			{
				free (node->prev);
				node->prev = NULL;
			}
		}
	}
	if (node)
	{
		free (node);
		node = NULL;
	}
	if (dlist)
	{
		free (dlist);
		dlist = NULL;
	}
}
