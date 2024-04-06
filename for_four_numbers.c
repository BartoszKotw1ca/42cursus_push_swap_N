/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_four_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 08:56:43 by bkotwica          #+#    #+#             */
/*   Updated: 2024/04/06 09:33:06 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// there itwill be max 6 steps
// max 3 for search and push min to b
// max 2 to sort numbers in a
// 1 for push min to a
int	for_four_numbers(t_Node **node, int	counter_el)
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
	i += for_three_numbers(node);
	p(&listb, node);
	ft_printf("pa\n");
	i ++;
	return (i);
}
