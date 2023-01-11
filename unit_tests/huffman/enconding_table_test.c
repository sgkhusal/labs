/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enconding_table_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:22:31 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/11 16:27:46 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

static void	print_enconding_table(char **d)
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

void	enconding_table_test(unsigned char *str)
{
	unsigned int	*freq;
	t_huffman		*head;
	char			**d;
	static int		n = 1;

	printf(GREY "enconding_table_test %d: \n" END, n);
	freq = huffman_frequency(str);
	head = create_huffman_lst(freq);
	free(freq);
	head = create_huffman_tree(&head);
	d = enconding_table(head);
	free_tree(head);
	print_enconding_table(d);
	free_enconding_table(d);
	n++;
}

void	enconding_table_tests(void)
{
	printf(YELLOW "Huffan Coding - enconding_table tests: " END "\n");
	enconding_table_test((unsigned char *)TEST1);
	enconding_table_test((unsigned char *)"maçãçç");
	//enconding_table_test((unsigned char *)TEST2);
}
