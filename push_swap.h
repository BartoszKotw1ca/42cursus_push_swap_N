/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 08:30:59 by bkotwica          #+#    #+#             */
/*   Updated: 2024/04/05 11:08:09 by bkotwica         ###   ########.fr       */
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


#endif
