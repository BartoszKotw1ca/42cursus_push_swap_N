/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 19:44:37 by bkotwica          #+#    #+#             */
/*   Updated: 2024/04/05 20:36:28 by bkotwica         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	char	**list;
	t_Node	*lista;
	int		counter_steps;
	int		counter_words;

	counter_words = 0;
	counter_steps = 0;
	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		counter_words = count_words_split(argv[1], ' ');
		list = ft_split(argv[1], ' ');
	}
	if (argc > 2)
	{
		counter_words = count_words(argv + 1);
		list = argv + 1;
	}
	if (!check_all(list))
		exit(0);
	lista = create_node_list(list);
	printing_nodes(lista);
	if (counter_words == 2)
		counter_steps += for_two_numbers(&lista);
	else if (counter_words == 3)
		counter_steps += for_three_numbers(&lista);
	else if (counter_words == 4)
		counter_steps += for_four_numbers(&lista);
	else if(counter_words == 5)
		counter_steps += for_five_numbers(&lista, counter_words);
	printing_nodes(lista);
	ft_printf("------\nSteps: %d\n------", counter_steps);
	return (0);
}
