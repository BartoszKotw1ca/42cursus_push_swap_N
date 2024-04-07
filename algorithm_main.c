/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 09:18:53 by bkotwica          #+#    #+#             */
/*   Updated: 2024/04/07 12:46:09 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// that funcion pushes elements from a to b unless
// counter_el so unless in stack a is more than 3 elements
int	push_nodes_to_b(t_Node **node, t_Node **listb, int i, int el_a)
{
	t_Node	*tmp;
	int		target;
	int		el_to_ins_a;

	while (el_a -- >= 3)
	{
		tmp = node_to_push(node, listb);
		el_to_ins_a = push_cost_a(node, tmp, el_a);
		i += el_to_ins_a + 1;
		while (el_to_ins_a -- > 0)
		{
			r(node);
			ft_printf("ra\n");
		}
		target = search_for_lower_value(tmp, listb);
		while ((*listb)->value != target)
		{
			r(listb);
			ft_printf("rb\n");
			i ++;
		}
		p(node, listb);
		ft_printf("pb\n");
	}
	return (i);
}

int	helper_a(int counter_el, t_Node **node, int target)
{
	int	i;
	int	j;

	i = 0;
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
	return (i);
}

int	push_nodes_to_a(t_Node **node, t_Node **listb, int i)
{
	int	target;
	int	counter_el;

	counter_el = num_in_ll(node) + 1;
	while (*listb)
	{
		target = search_for_maks_value(*listb, node);
		i += helper_a(counter_el, node, target);
		counter_el ++;
		p(listb, node);
		ft_printf("pa\n");
	}
	return (i);
}

// this function should put the 
// minimanl value in the riht place 
// in the stack
int	put_the_min(t_Node **node, int counter_el)
{
	int	min;
	int	j;

	min = min_in_list(node);
	if ((counter_el / 2) < (current_pos(node, min)))
	{
		j = counter_el - (current_pos(node, min));
		counter_el = j;
		while (j-- > 0)
		{
			ft_printf("rra\n");
			rr(node);
		}
	}
	else
	{
		j = (current_pos(node, min));
		counter_el = j;
		while (j-- > 0)
		{
			ft_printf("ra\n");
			r(node);
		}
	}
	return (counter_el);
}

int	algorithm(t_Node **node, int counter_el)
{
	t_Node	*listb;
	int		i;

	listb = NULL;
	counter_el -= 2;
	i = push_first_two(node, &listb);
	i += push_nodes_to_b(node, &listb, 0, num_in_ll(node));
	i += for_three_numbers(node, 0, max_in_list(node));
	i += push_nodes_to_a(node, &listb, 0);
	i += put_the_min(node, num_in_ll(node) + 1);
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
