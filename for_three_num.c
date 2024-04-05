/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_three_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 17:05:44 by bkotwica          #+#    #+#             */
/*   Updated: 2024/04/05 17:06:46 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	for_three_numbers(t_Node **node)
{
	int	i;
	int	max;

	max = max_in_list(node);
	i = 0;
	while (!check_if_sorted(node))
	{
		if (check_if_sorted_back(node))
		{
			s(node);
			rr(node);
			ft_printf("sa\nrra\n");
			i += 2;
		}
		else if (max == (*node)->value)
		{
			rr(node);
			ft_printf("rra\n");
			i ++;
		}
		else if ((*node)->next->value > (*node)->next->next->value)
		{
			rr(node);
			ft_printf("rra\n");
			i ++;
		}
		else if ((*node)->value > (*node)->next->value)
		{
			i += for_two_numbers(node);
		}
	}
	return (i);
}
