/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:02:49 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/10 18:19:45 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "huffman.h"

t_huffman	*create_huffman_node(unsigned int freq, unsigned char c)
{
	t_huffman	*node;

	node = (t_huffman *)malloc(sizeof(t_huffman));
	if (!node)
		malloc_error("create_huffman_node");
	node->weight = freq;
	node->c = c;
	node->next = NULL;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

void	huffman_lstadd_sort(t_huffman **head, t_huffman *node)
{
	t_huffman	*aux;

	if (*head == NULL)
	{
		*head = node;
		return ;
	}
	if ((*head)->weight > node->weight)
	{
		node->next = *head;
		*head = node;
		return ;
	}
	aux = *head;
	while (aux->next && aux->next->weight <= node->weight)
		aux = aux->next;
	node->next = aux->next;
	aux->next = node;
}

t_huffman	*create_huffman_lst(unsigned int *freq)
{
	t_huffman		*head;
	unsigned int	i;

	i = 0;
	head = NULL;
	while (i < ASCII_SIZE)
	{
		if (freq[i] > 0)
			huffman_lstadd_sort(&head, create_huffman_node(freq[i], i));
		i++;
	}
	return (head);
}

void	free_huffman_lst(t_huffman **head)
{
	t_huffman	*aux;

	while (*head)
	{
		aux = (*head)->next;
		free(*head);
		*head = aux;
	}
}
