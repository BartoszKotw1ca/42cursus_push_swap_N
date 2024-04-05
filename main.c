/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 19:44:37 by bkotwica          #+#    #+#             */
/*   Updated: 2024/04/05 11:54:33 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printing_nodes(t_Node *node)
{
	while(node)
	{
		printf("%d\n", node->value);
		node = node->next;
	}
}

int	check_if_sorted(t_Node **node)
{
	while ((*node)->next)
	{
		if ((*node)->value > (*node)->next->value)
			return (0);
		(*node) = (*node)->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	char	**list;
	t_Node	*lista;
	if (argc == 1)
		return (0);
	if (argc == 2)
		list = ft_split(argv[1], ' ');
	if (argc > 2)
		list = argv + 1;
	if (!check_all(list))
		exit(0);
	lista = create_node_list(list);
	ft_printf("%d", check_if_sorted(&lista));
	//printing_nodes(lista);
	return (0);
}
