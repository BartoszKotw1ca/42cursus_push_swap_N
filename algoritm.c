/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:22:55 by bkotwica          #+#    #+#             */
/*   Updated: 2024/04/05 17:07:40 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	for_two_numbers(t_Node **node)
{
	int	i;

	i = 0;
	if ((*node)->value > (*node)->next->value)
	{
		s(node);
		ft_printf("pa\n");
		i ++;
	}
	return (i);
}

int	for_four_numbers(t_Node **node)
{
	int		i;
	int		max;
	t_Node	*lista;

	lista = NULL;
	max = max_in_list(node);
	ft_printf("max ::%d", max);
	i = 0;
	while (!check_if_sorted(node))
	{
		p(node, &lista);
		ft_printf("pb\n");
		i += for_three_numbers(node);
		p(&lista, node);
		ft_printf("pa\n");
		if (max == (*node)->value)
		{
			r(node);
			ft_printf("rra");
		}
		i += 3;
		//printf("%d", (*node)->value);
		break;
	}
	return (i);
}
