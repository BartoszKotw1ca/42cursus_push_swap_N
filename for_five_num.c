/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_five_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 17:21:34 by bkotwica          #+#    #+#             */
/*   Updated: 2024/04/05 21:29:39 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	current_pos(t_Node **node, int arg)
{
	t_Node	*temp;
	int		i;

	i = 0;
	temp = *node;
	while (temp)
	{
		if (arg == temp->value)
			return (i);
		temp = temp->next;
		i ++;
	}
	return (0);
}

int	for_five_numbers(t_Node **node, int	counter_el)
{
	int		min;
	int		i;
	int		j;
	t_Node	*listb;
	listb = NULL;

	i = 0;
	while (!check_if_sorted(node))
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
			break;
		}
		else if ((counter_el / 2) < (current_pos(node, min)))
		{
			j = counter_el - (current_pos(node, min));
			printf("valu :%d\n", (*node)->value);
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
		//printf("conter el: %d\n", counter_el);
		printing_nodes(*node);
		i ++;
	}
	return (i);
}
