/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 09:18:53 by bkotwica          #+#    #+#             */
/*   Updated: 2024/04/06 11:30:10 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	algorithm(t_Node **node, int counter_el)
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
