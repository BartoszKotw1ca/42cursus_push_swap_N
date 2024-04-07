/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_four_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 08:56:43 by bkotwica          #+#    #+#             */
/*   Updated: 2024/04/07 11:01:16 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// there itwill be max 6 steps
// max 3 for search and push min to b
// max 2 to sort numbers in a
// 1 for push min to a

int	helper(t_Node **node, int min, int counter_el, int j)
{
	int	i;

	i = 0;
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
	return (i);
}

int	for_four_numbers(t_Node **node, int counter_el)
{
	int		i;
	int		min;
	int		j;
	t_Node	*listb;

	listb = NULL;
	min = min_in_list(node);
	i = 0;
	j = 0;
	while (listb == NULL)
	{
		i += helper(node, min, counter_el, j);
		counter_el --;
		p(node, &listb);
		ft_printf("pb\n");
		i ++;
	}
	i += for_three_numbers(node, 0, max_in_list(node));
	p(&listb, node);
	ft_printf("pa\n");
	i ++;
	free(listb);
	return (i);
}
