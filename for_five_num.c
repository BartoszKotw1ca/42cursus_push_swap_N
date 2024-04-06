/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_five_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 17:21:34 by bkotwica          #+#    #+#             */
/*   Updated: 2024/04/06 11:35:12 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	for_five_numbers(t_Node **node, int counter_el)
{
	int		i;
	int		min;
	int		j;
	t_Node	*listb;

	listb = NULL;
	min = min_in_list(node);
	i = 0;
	while (listb == NULL)
	{
		if ((counter_el / 2) < (current_pos(node, min)))
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
	i += for_four_numbers(node, 4);
	p(&listb, node);
	ft_printf("pa\n");
	i ++;
	free(listb);
	return (i);
}
