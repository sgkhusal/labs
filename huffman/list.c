/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:02:49 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/10 14:50:01 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "huffman.h"

t_huffman	*create_huffman_node(int freq, char c)
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

void	huffman_lstadd(t_huffman **head, t_huffman *node)
{
	t_huffman	*aux;

	if (*head == NULL)
	{
		*head = node;
		return ;
	}
	aux = *head;
	while (aux->next)
		aux = aux->next;
	aux->next = node;
	aux = aux->next;
}

t_huffman	*create_huffman_lst(int *freq)
{
	t_huffman	*head;
	int			i;

	i = 0;
	head = NULL;
	while (i < ASCII_SIZE)
	{
		if (freq[i] > 0)
		{
			huffman_lstadd(&head, create_huffman_node(freq[i], i));
		}
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
