/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 19:44:37 by bkotwica          #+#    #+#             */
/*   Updated: 2024/04/08 14:50:29 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_arg(int argc, char **argv, char ***list, int *counter_words)
{
	if (argc == 1)
		exit (0);
	if (argc == 2)
	{
		*counter_words = count_words_split(argv[1], ' ');
		*list = ft_split(argv[1], ' ');
	}
	if (argc > 2)
	{
		*counter_words = count_words(argv + 1);
		*list = argv + 1;
	}
	if (!check_all(*list))
	{
		write(2, "Error\n", 6);
		exit(0);
	}
}

void	process_list(t_Node **lista, int counter_words)
{
	if (counter_words == 2)
		for_two_numbers(lista);
	else if (counter_words == 3)
		for_three_numbers(lista, 0, max_in_list(lista));
	else if (counter_words == 4)
		for_four_numbers(lista, counter_words);
	else if (counter_words >= 5)
		algorithm(lista, counter_words);
	//printing_nodes(*lista);
	//printf("myasb%lld ", check(1457189065, -2107009500));
	//printf("myasdf%lld\n", myabs(myabs(-2107009500) + myabs(1457189065)));
	printing_nodes(*lista);
	del(lista);
}

int	main(int argc, char **argv)
{
	char	**list;
	t_Node	*lista;
	int		counter_words;

	list = NULL;
	counter_words = 0;
	parse_arg(argc, argv, &list, &counter_words);
	lista = create_node_list(list);
	process_list(&lista, counter_words);
	return (0);
}
