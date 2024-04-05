/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 08:30:59 by bkotwica          #+#    #+#             */
/*   Updated: 2024/04/05 19:46:19 by bkotwica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "mylibft/mylibft.h"
# include <stdlib.h>

typedef struct Node
{
	struct Node	*next;
	struct Node	*previous;
	int			value;
}		t_Node;

long long	ft_atoilong(const char *nptr);
int			check_all(char **list);
t_Node		*create_node_list(char **list);
void		s(t_Node **node);
void		p(t_Node **node1, t_Node **node2);
void		r(t_Node **node);
void		rr(t_Node **node);
int			for_two_numbers(t_Node **node);
int			check_if_sorted(t_Node **node);
int			for_two_numbers(t_Node **node);
int			for_three_numbers(t_Node **node);
int			for_four_numbers(t_Node **node);
int			max_in_list(t_Node **node);
int			check_if_sorted_back(t_Node **node);
int			count_words_split(char const *s, char c);
int			count_words(char **list);
int			check_if_sorted(t_Node **node);
int			min_in_list(t_Node **node);
int			for_five_numbers(t_Node **node, int counter_el);
void		printing_nodes(t_Node *node);
#endif
