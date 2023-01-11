/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:22:31 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/11 16:27:46 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

static void	print_dictionary(char **d)
{
	int	i;

	i = 0;
	while (i < ASCII_SIZE - 1)
	{
		if (d[i][0])
			printf("|%c| --> %s\n", i, d[i]);
		i++;
	}
}

void	dictionary_test(unsigned char *str)
{
	unsigned int	*freq;
	t_huffman		*head;
	char			**d;
	static int		n = 1;

	printf(GREY "dictionary_test %d: \n" END, n);
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
	dictionary_test((unsigned char *)TEST1);
	dictionary_test((unsigned char *)"maçãçç");
	dictionary_test((unsigned char *)TEST2);
}
