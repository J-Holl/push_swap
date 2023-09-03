/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholl <jholl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 18:50:31 by jholl             #+#    #+#             */
/*   Updated: 2021/09/15 12:33:10 by jholl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_error(t_data *data)
{
	if (data->pile_a)
		dlist_del(data->pile_a);
	if (data->pile_b)
		dlist_del(data->pile_b);
	ft_putstr(2, "Error\n");
	exit(0);
}

void	exit_no_error(t_data *data)
{
	if (data->pile_a)
		dlist_del(data->pile_a);
	if (data->pile_b)
		dlist_del(data->pile_b);
}
