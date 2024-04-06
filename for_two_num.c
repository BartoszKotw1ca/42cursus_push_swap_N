/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:22:55 by bkotwica          #+#    #+#             */
/*   Updated: 2024/04/06 08:57:05 by bkotwica         ###   ########.fr       */
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
