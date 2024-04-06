/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 17:23:19 by bkotwica          #+#    #+#             */
/*   Updated: 2024/04/06 09:08:25 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_in_list(t_Node **node)
{
	int		min;
	t_Node	*tmp;

	tmp = *node;
	if (tmp == NULL)
		return (0);
	min = tmp->value;
	while (tmp)
	{
		if (min > tmp->value)
			min = tmp->value;
		tmp = tmp->next;
	}
	return (min);
}

int	check_if_sorted_b(t_Node **node)
{
	t_Node	*temp;

	if (*node == NULL)
		return (1);
	temp = *node;
	while (temp->next)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

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
