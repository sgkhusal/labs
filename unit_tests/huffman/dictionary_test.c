/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:22:31 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/15 14:18:47 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

static void	print_dictionary(char **d)
{
	int	i;

	i = 0;
	if (d == NULL)
	{
		printf("%p\n", d);
		return ;
	}
	while (i < ASCII_SIZE - 1)
	{
		if (d[i][0])
			printf("|%c| --> %s\n", i, d[i]);
		i++;
	}
}

void	dictionary_test1(void)
{
	unsigned int	*freq;
	t_huffman		*head;
	char			**d;

	printf(GREY "dictionary_test 1 - |%s|: " END, TEST1);
	freq = huffman_frequency((unsigned char *)TEST1);
	head = create_huffman_lst(freq);
	free(freq);
	head = create_huffman_tree(&head);
	d = dictionary(head);
	if (strcmp(d['W'], "000") || strcmp(d['d'], "001") || strcmp(d['e'], "010")
		|| strcmp(d['r'], "011") || strcmp(d['l'], "10")
		|| strcmp(d['o'], "110") || strcmp(d[' '], "1110")
		|| strcmp(d['H'], "1111"))
		printf(RED "KO" END "\n");
	else
		printf(GREEN "OK" END "\n");
	free_tree(head);
	print_dictionary(d);
	free_dictionary(d);
}

void	dictionary_test(unsigned char *str)
{
	unsigned int	*freq;
	t_huffman		*head;
	char			**d;
	static int		n = 2;

	printf(GREY "dictionary_test %d - |%s|:\n" END, n, str);
	freq = huffman_frequency(str);
	head = create_huffman_lst(freq);
	free(freq);
	head = create_huffman_tree(&head);
	d = dictionary(head);
	free_tree(head);
	print_dictionary(d);
	free_dictionary(d);
	n++;
}

void	dictionary_tests(void)
{
	printf(YELLOW "Huffan Coding - dictionary tests: " END "\n");
	dictionary_test1();
	dictionary_test((unsigned char *)"maçãçç");
	dictionary_test((unsigned char *)"ab");
	dictionary_test((unsigned char *)"aaaa");
	dictionary_test((unsigned char *)"");
	dictionary_test((unsigned char *)TEST2);
}
