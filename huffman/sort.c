/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:54:06 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/10 13:54:31 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "huffman.h"

static void	swap_int(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void	swap_char(char *a, char *b)
{
	char	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	huffman_lstsort(t_huffman *head)
{
	t_huffman	*aux1;
	t_huffman	*aux2;

	aux1 = head;
	while (aux1)
	{
		aux2 = aux1->next;
		while (aux2)
		{
			if (aux1->weight > aux2->weight)
			{
				swap_int(&aux1->weight, &aux2->weight);
				swap_char(&aux1->c, &aux2->c);
			}
			aux2 = aux2->next;
		}
		aux1 = aux1->next;
	}
}
