/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholl <jholl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 14:27:41 by jholl             #+#    #+#             */
/*   Updated: 2021/09/23 18:20:05 by jholl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_node
{
	int				val;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

typedef struct s_dlist
{
	size_t	len;
	t_node	*head;
	t_node	*tail;

}				t_dlist;

typedef struct s_data
{
	t_dlist	*pile_a;
	t_dlist	*pile_b;
	int		number_chunck;
	int		size_chunck;
	int		pivot;
	int		prev_pivot;
	int		rest;
	int		count_head;
	int		count_tail;
}				t_data;

//sort
void	prev_pivot_last_pos(t_data *data);
int		lf_prev_pivot_head(t_data *data);
int		lf_prev_pivot_tail(t_data *data);
int		lf_data_pivot_tail(t_data *data);
int		lf_data_pivot_head(t_data *data);
void	re_organize_b(t_data *data);
void	locate_next_push_tail(int *tail, t_node *node, int ti, t_data *data);
void	locate_next_push_head(int *head, t_node *node, int ti, t_data *data);
void	position_next_push(int *head, int *tail, t_data *data);
void	first_fastest_move_ultimate(t_node *node, t_data *data);
void	fastest_move(t_data *data);
void	fastest_move_next(t_data *data);
void	fastest_move_ultimate(t_node *node, t_data *data);
void	calculate_pivot(t_data *data);
void	lf_next_pivot(int temp, t_node *node, t_data *data);
void	organize_b(t_data *data);
void	start_sort(t_data *data);
void	chunck_sort(int number_chunck_cpy, t_data *data);
void	sort(t_data *data);
void	rotate_push_a(int j, t_data *data);
void	locate_max_b(int x, t_data *data);
void	eject_min(int size_chunck_cpy, t_data *data);
void	small_pivot(int actual_size, t_data *data);
void	sort_five(t_data *data);
int		i_add_actual_max(t_data *data);
int		j_add_actual_max(t_data *data);

//push_swap
void	push_swap_two(t_data *data);
void	push_swap_three(t_data *data);

//stack operate
void	push(t_dlist *push, t_dlist **pushed, t_data *data);
void	pa(t_data *data);
void	pb(t_data *data);
void	swap(t_dlist *to_swap);
void	sa(t_data *data);
void	sb(t_data *data);
void	ss(t_data *data);
void	rotate(t_dlist *rotate_me);
void	rr(t_data *data);
void	rb(t_data *data);
void	ra(t_data *data);
void	reverse(t_dlist *reverse_me);
void	rrr(t_data *data);
void	rra(t_data *data);
void	rrb(t_data *data);

// parsing
int		check_isspace(int *i, char *s, t_data *data);
void	result_in_pile(int result, t_data *data);
int		recup_digits(int *i, char *s, t_data *data);
void	check_av(char *s, t_data *data);
void	parsing(int ac, char **av, t_data *data);

//dlist
void	dlist_del(t_dlist *dlist);
void	dlist_add_back(int val, t_dlist **dlist, t_data *data);
void	dlist_add_front(int val, t_dlist **dlist, t_data *data);
void	dlist_add_front_nm(t_node *node, t_dlist **dlist, t_data *data);
t_dlist	*dlist_new(int val);
t_dlist	*dlist_new_nm(t_node *node, t_data *data);

//misc
void	init_data(t_data *data);
void	init_size_chunck(t_data *data);
void	init_number_chunck(t_data *data);
void	init_pivot(t_data *data);
void	ft_putstr(int fd, char *s);

//error
void	exit_no_error(t_data *data);
void	exit_error(t_data *data);

#endif
