/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 09:47:59 by bkotwica          #+#    #+#             */
/*   Updated: 2024/04/08 14:53:02 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// that 2 functions calculate the cost to push
// how many times we have to rra or ra stacks to put
// the number in stack b
int	push_cost_b(t_Node *node, t_Node **listb, int c1)
{
	int		target;
	int		push_cost;
	int		cur_pos;

	target = search_for_lower_value(node, listb);
	//ft_printf("value: %d, target:%d\n", node->value, target);
	cur_pos = current_pos(listb, target);
	//printf("curr_pos: %d,\n el_in_li: %d\n", cur_pos, c1);
	push_cost = 0;
	if ((c1 / 2) < cur_pos)
		push_cost = c1 - cur_pos;
	else
		push_cost = cur_pos;
	return (push_cost);
}

int	push_cost_a(t_Node **lista, t_Node *node, int c2)
{
	int	push_cost;
	int	cur_pos;

	cur_pos = current_pos(lista, node->value);
	if ((c2 / 2) < cur_pos)
		push_cost = c2 - cur_pos;
	else
		push_cost = cur_pos;
	return (push_cost);
}

// that function return the node with that cheapest 
// cost to push to b
t_Node	*node_to_push(t_Node **lista, t_Node **listb)
{
	t_Node	*tmp;
	t_Node	*res;
	int		curr_cost;
	int		l;

	if (!(*lista))
		return (NULL);
	tmp = *lista;
	l = push_cost_a(lista, tmp, num_in_ll(lista) + 1)
		+ push_cost_b(tmp, listb, num_in_ll(listb) + 1);
	res = tmp;
	tmp = tmp->next;
	//printf("curr_cost: %d\n", l);
	while (tmp)
	{
		 //ft_printf("cost:%d\n tmp: %d\n", curr_cost, tmp->value);
		curr_cost = push_cost_a(lista, tmp, num_in_ll(lista) + 1)
			+ push_cost_b(tmp, listb, num_in_ll(listb) + 1);
		//printf("curr_cost: %d\n", curr_cost);
		if (l > curr_cost)
		{
			l = curr_cost;
			res = tmp;
		}
		tmp = tmp->next;
	}
	return (res);
}

int	num_in_ll(t_Node **node)
{
	int		i;
	t_Node	*tmp;

	i = 0;
	tmp = *node;
	while (tmp->next)
	{
		tmp = tmp->next;
		i ++;
	}
	return (i);
}
