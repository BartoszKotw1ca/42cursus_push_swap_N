/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 09:44:49 by bkotwica          #+#    #+#             */
/*   Updated: 2024/04/04 10:03:03 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// function that is supposed to create a list of numbers
int	*creating_list(int argc, char **argv)
{
	int	j;
	int	i;
	int	*numbers;

	i = 1;
	j = 0;
	numbers = malloc(sizeof(int) * (argc - 1));
	while (i < argc)
		numbers[j ++] = ft_atoi(argv[i ++]);
	return (numbers);
}

// that function should be able to print on stdio numbers in the list
void	printing_numbers(int *numbers, int argc)
{
	int	i;

	i = 0;
	while (i < argc - 1)
		ft_printf("%d ", numbers[i ++]);
}

// command to run operations
// p(n1, n2, argc);
//rr(n1, argc);
// sa(n1);
// r(n1, argc);

int	check_if_sorted(int *n, int argc)
{
	argc --;
	while (argc-- > 0)
		if (n[argc] < n[argc - 1])
			return (0);
	return (1);
}

void	sort(int *n1, int *n2, int argc)
{
	while (!check_if_sorted(n1, argc))
	{
		if (n1[0] > n1[1] && n2[0] > n2[1])
		{
			s(n1);
			s(n2);
			ft_printf("ss\n");
		}
		else if (n1[0] > n1[1])
		{
			ft_printf("sa\n");
			s(n1);
		}
		else if (n2[0] > n2[1])
		{
			s(n2);
			ft_printf("sb\n");
		}
		else
		{
			p(n2, n1, argc);
			ft_printf("pb\n");
		}
		(void) argc;
	}
}

int	main(int argc, char **argv)
{
	int *n1;
	int	*n2;

	n1 = creating_list(argc, argv);
	n2 = ft_calloc(argc - 1, sizeof(int));
	printing_numbers(n1, argc);
	ft_printf("\n");
	printing_numbers(n2, argc);
	ft_printf("\n");
	sort(n1, n2, argc);
	printing_numbers(n1, argc);
	ft_printf("\n");
	printing_numbers(n2, argc);
	ft_printf("\n");
}
// remember to free the memorey of s1 and s2
