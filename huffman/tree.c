/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:07:20 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/13 00:31:27 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "huffman.h"

static t_huffman	*create_huffman_tree_node(t_huffman	*l, t_huffman *r)
{
	t_huffman	*node;

	node = (t_huffman *)malloc(sizeof(t_huffman));
	if (!node)
		malloc_error("create_huffman_tree_node");
	node->weight = l->weight + r->weight;
	node->next = NULL;
	node->left = l;
	node->right = r;
	return (node);
}

static t_huffman	*remove_first_node(t_huffman **head)
{
	t_huffman	*first_node;

	first_node = *head;
	if (first_node)
	{
		*head = first_node->next;
		first_node->next = NULL;
	}
	return (first_node);
}

t_huffman	*create_huffman_tree(t_huffman **lst)
{
	t_huffman	*left;
	t_huffman	*right;
	t_huffman	*tree_node;

	while (*lst && (*lst)->next)
	{
		left = remove_first_node(lst);
		right = remove_first_node(lst);
		tree_node = create_huffman_tree_node(left, right);
		huffman_lstadd_sort(lst, tree_node);
	}
	return (*lst);
}

int	tree_height(t_huffman *tree)
{
	int	left;
	int	right;

	if (tree == NULL)
		return (-1);
	left = tree_height(tree->left) + 1;
	right = tree_height(tree->right) + 1;
	if (left > right)
		return (left);
	return (right);
}

void	free_tree(t_huffman *tree)
{
	if (tree == NULL)
		return ;
	free_tree(tree->left);
	free_tree(tree->right);
	free(tree);
	tree = NULL;
}
