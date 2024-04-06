/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 09:18:53 by bkotwica          #+#    #+#             */
/*   Updated: 2024/04/06 19:44:54 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// that 2 functions calculate the cost to push
// how many times we have to rra or ra stacks to put
// the number in stack b
int	push_cost_b(t_Node **lista, t_Node **listb, int c1)
{
	int		target;
	int		push_cost;
	int		cur_pos;

	target = search_for_lower_value(*lista, listb);
	cur_pos = current_pos(listb, target);
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
	l = push_cost_a(lista, tmp, num_in_ll(lista))
		+ push_cost_b(lista, listb, num_in_ll(listb));
	res = tmp;
	tmp = tmp->next;
	while (tmp)
	{
		curr_cost = push_cost_a(lista, tmp, num_in_ll(lista))
			+ push_cost_b(lista, listb, num_in_ll(listb));
		if (l > curr_cost)
		{
			l = curr_cost;
			res = tmp;
		}
		tmp = tmp->next;
	}
	return (res);
}

// that funcion pushes elements from a to b unless
// counter_el so unless in stack a is more than 3 elements
int	push_nodes_to_b(t_Node **node, t_Node **listb)
{
	t_Node	*tmp;
	int		el_a;
	int		target;
	int		el_to_ins_a;
	int		i;

	i = 0;
	el_a = num_in_ll(node);
	while (el_a -- >= 3)
	{
		tmp = node_to_push(node, listb);
		el_to_ins_a = push_cost_a(node, tmp, el_a);
		i = el_to_ins_a + i + 1;
		while (el_to_ins_a -- > 0)
		{
			r(node);
			ft_printf("ra\n");
		}
		target = search_for_lower_value(tmp, listb);
		while ((*listb)->value != target)
		{
			rr(listb);
			ft_printf("rb\n");
			i ++;
		}
		p(node, listb);
		ft_printf("pb\n");
	}
	return (i);
}

int	push_nodes_to_a(t_Node **node, t_Node **listb)
{
	int	target;
	int	counter_el;
	int	j;
	int	min;
	int	i;

	i = 0;
	counter_el = num_in_ll(node) + 1;
	while (*listb)
	{
		target = search_for_maks_value(*listb, node);
		if ((counter_el / 2) < (current_pos(node, target)))
		{
			j = counter_el - (current_pos(node, target));
			i = i + j + 2;
			while (j-- > 0)
			{
				ft_printf("rra\n");
				rr(node);
			}
		}
		else
		{
			j = (current_pos(node, target));
			i = i + j + 1;
			while (j-- > 0)
			{
				ft_printf("ra\n");
				r(node);
			}
		}
		counter_el ++;
		p(listb, node);
		ft_printf("pa\n");
	}
	min = min_in_list(node);
	if ((counter_el / 2) < (current_pos(node, min)))
	{
		j = counter_el - (current_pos(node, min));
		while (j-- > 0)
		{
			ft_printf("rra\n");
			rr(node);
		}
	}
	else
	{
		j = (current_pos(node, min));
		while (j-- > 0)
		{
			ft_printf("ra\n");
			r(node);
		}
	}
	return (i);
}

int	algorithm(t_Node **node, int counter_el)
{
	t_Node	*listb;
	int		i;

	listb = NULL;
	counter_el -= 2;
	i = push_first_two(node, &listb);
	i += push_nodes_to_b(node, &listb);
	i += for_three_numbers(node);
	i += push_nodes_to_a(node, &listb);
	return (i);
}

/*
{
	int		min;
	int		i;
	int		j;
	t_Node	*listb;

	listb = NULL;
	i = 0;
	while (!check_if_sorted(node) || listb != NULL)
	{
		min = min_in_list(node);
		if (*node == NULL)
		{
			while (listb)
			{
				p(&listb, node);
				ft_printf("pa\n");
				i ++;
			}
			break ;
		}
		else if ((counter_el / 2) < (current_pos(node, min)))
		{
			j = counter_el - (current_pos(node, min));
			while (j-- > 0)
			{
				ft_printf("rra\n");
				rr(node);
				i ++;
			}
		}
		else
		{
			j = (current_pos(node, min));
			while (j-- > 0)
			{
				ft_printf("ra\n");
				r(node);
				i ++;
			}
		}
		counter_el --;
		p(node, &listb);
		ft_printf("pb\n");
		i ++;
	}
	return (i);
}
*/
