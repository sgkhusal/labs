/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:11:12 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/10 17:57:37 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

static void	create_node_test(void)
{
	t_huffman	*node;

	printf(GREY "create_node_test: " END);
	node = create_huffman_node(42, 's');
	if (node->c == 's' && node->weight == 42
		&& !node->next && !node->left && !node->right)
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	free(node);
}

static void	huffman_lstadd_sort_test(void)
{
	t_huffman	*node1;
	t_huffman	*node2;
	t_huffman	*head;

	printf(GREY "huffman_lstadd_sort_test 1: " END);
	head = NULL;
	node1 = create_huffman_node(42, 's');
	huffman_lstadd_sort(&head, node1);
	if (head->c == 's' && head->weight == 42
		&& !head->next && !head->left && !head->right)
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	printf(GREY "huffman_lstadd_sort_test 2: " END);
	node2 = create_huffman_node(1024, 'j');
	huffman_lstadd_sort(&head, node2);
	if (head->next && head->next == node2
		&&head->next->c == 'j' && head->next->weight == 1024
		&& !head->next->next && !head->next->left && !head->next->right)
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	free(node1);
	free(node2);
}

static void	print_lst(t_huffman	*lst)
{
	t_huffman	*aux;

	aux = lst;
	printf("|");
	while (aux)
	{
		printf("%c", aux->c);
		aux = aux->next;
	}
	printf("| ---> frequencies: ");
	aux = lst;
	while (aux)
	{
		printf("%d ", aux->weight);
		aux = aux->next;
	}
	printf("\n");
}

static void	create_huffman_lst_test(void)
{
	unsigned int			*freq;
	t_huffman	*head;

	printf(GREY "create_huffman_lst_test:\n" END);
	freq = huffman_frequency(TEST);
	head = create_huffman_lst(freq);
	free(freq);
	print_lst(head);
	free_huffman_lst(&head);
}

void	huffman_lst_tests(void)
{
	printf(YELLOW "Huffan Coding - list tests: " END "\n");
	create_node_test();
	huffman_lstadd_sort_test();
	create_huffman_lst_test();
}
