/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkotwica <bkotwica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 08:30:59 by bkotwica          #+#    #+#             */
/*   Updated: 2024/04/04 19:47:27 by bkotwica         ###   ########.fr       */
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

#endif