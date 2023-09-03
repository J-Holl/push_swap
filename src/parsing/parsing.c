/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholl <jholl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 21:02:58 by jholl             #+#    #+#             */
/*   Updated: 2021/09/22 15:58:35 by jholl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_isspace(int *i, char *s, t_data *data)
{
	(void)data;
	while (s[*i] == '\f' || s[*i] == '\n' || s[*i] == '\r'
		|| s[*i] == '\t' || s[*i] == '\v' || s[*i] == ' ')
		(*i)++;
	if (s[*i] == 0)
		return (0);
	return (1);
}

void	result_in_pile(int result, t_data *data)
{
	t_node	*node;

	if (data->pile_a)
	{
		node = data->pile_a->head;
		while (node)
		{
			if (result == node->val)
				exit_error(data);
			node = node->next;
		}
	}
	if (!data->pile_a)
	{
		data->pile_a = dlist_new(result);
		if (!data->pile_a)
			exit_error(data);
	}
	else
	{
		dlist_add_back(result, &data->pile_a, data);
	}
}

int	recup_digits(int *i, char *s, t_data *data)
{
	long	sign;
	long	result;

	sign = 1;
	result = 0;
	(void)check_isspace(i, s, data);
	if (s[*i] == '-')
	{
		sign = -1;
		(*i)++;
	}
	if (!(s[*i] >= '0' && s[*i] <= '9'))
		exit_error(data);
	while (s[*i] >= '0' && s[*i] <= '9')
	{
		result *= 10;
		result += s[*i] - '0';
		(*i)++;
	}
	if ((result * sign) < -2147483648 || (result * sign) > 2147483647)
		exit_error(data);
	result_in_pile((int)(result * sign), data);
	return (check_isspace(i, s, data));
}

void	check_av(char *s, t_data *data)
{
	int	i;
	int	stop;

	i = 0;
	stop = 1;
	while (stop)
	{
		stop = recup_digits(&i, s, data);
	}
}

void	parsing(int ac, char **av, t_data *data)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		check_av(av[i], data);
		i++;
	}
}	
