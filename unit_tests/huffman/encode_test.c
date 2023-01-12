/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encode_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 22:08:55 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/12 16:32:02 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

void	encode_test(unsigned char *str, char *expected)
{
	unsigned int	*freq;
	t_huffman		*head;
	char			**d;
	char			*result;
	static int		n = 1;

	printf(GREY "encode_test %d - |%s|: " END, n, str);
	freq = huffman_frequency(str);
	head = create_huffman_lst(freq);
	free(freq);
	head = create_huffman_tree(&head);
	d = dictionary(head);
	free_tree(head);
	result = encode(d, str);
	free_dictionary(d);
	if (result && strcmp(result, expected))
		printf(RED "KO" END "\n");
	else if (result == NULL && expected != NULL)
		printf(RED "KO" END "\n");
	else
		printf(GREEN "OK" END "\n");
	free(result);
	n++;
}

void	encode_tests(void)
{
	printf(YELLOW "Huffan Coding - encoding tests: " END "\n");
	encode_test((unsigned char *)TEST1, "11110101010110111000011001110001");
	encode_test((unsigned char *)"Vamos aprender a programa",
		"1111000110011011000011001110101100101011111110011010110001111101011101010010100110000");
	encode_test((unsigned char *)"ab", "01");
	encode_test((unsigned char *)"aaaa", "0000");
	encode_test((unsigned char *)"", NULL);
}
