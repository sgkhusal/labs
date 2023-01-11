/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:03:55 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/11 00:56:21 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

static void	print_tree(t_huffman *node, int dist)
{
	if (node->left == NULL && node->right == NULL)
		printf("Leaf: |%c| - freq: %d - dist: %d\n",
			node->c, node->weight, dist);
	else
	{
		print_tree(node->left, dist + 1);
		print_tree(node->right, dist + 1);
	}
}

static void	create_huffman_tree_test(unsigned char *str)
{
	unsigned int	*freq;
	t_huffman		*head;

	printf(GREY "create_huffman_tree_test:\n" END);
	freq = huffman_frequency(str);
	head = create_huffman_lst(freq);
	free(freq);
	head = create_huffman_tree(&head);
	print_tree(head, 0);
	free_tree(head);
}

void	tree_height_test(unsigned char *str)
{
	unsigned int	*freq;
	t_huffman		*head;
	int				result;

	printf(GREY "tree_height_test: " END);
	freq = huffman_frequency(str);
	head = create_huffman_lst(freq);
	free(freq);
	head = create_huffman_tree(&head);
	result = tree_height(head);
	if (result == 4)
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	free_tree(head);
}

void	huffman_tree_tests(void)
{
	printf(YELLOW "Huffan Coding - tree tests: " END "\n");
	create_huffman_tree_test((unsigned char *)TEST1);
	tree_height_test((unsigned char *)TEST1);
	// needs free tree and nodes
}
