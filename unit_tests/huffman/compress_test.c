/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:18:49 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/12 18:15:29 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

void	compress_test(unsigned char *str, unsigned char *expected)
{
	unsigned int	*freq;
	t_huffman		*head;
	char			**d;
	char			*str_bit;
	unsigned char	*result;
	size_t			nbits;
	static int		n = 1;

	printf(GREY "compress_test %d - |%s|: " END, n, str);
	freq = huffman_frequency(str);
	head = create_huffman_lst(freq);
	head = create_huffman_tree(&head);
	d = dictionary(head);
	str_bit = encode(d, str);
	nbits = number_of_bits(str_bit);
	result = compress(str_bit, nbits);
	if (result && strcmp((char *)result, (char *)expected))
		printf(RED "KO" END "\n");
	else if (result == NULL && expected != NULL)
		printf(RED "KO" END "\n");
	else
		printf(GREEN "OK" END "\n");
	free(freq);
	free_tree(head);
	free_dictionary(d);
	free(str_bit);
	free(result);
	n++;
}

void	compress_tests(void)
{
	unsigned char	expected[11];

	printf(YELLOW "Huffan Coding - compress tests: " END "\n");
	expected[0] = 245;
	expected[1] = 91;
	expected[2] = 134;
	expected[3] = 113;
	expected[4] = '\0';
	compress_test((unsigned char *)TEST1, expected);
	expected[0] = 241;
	expected[1] = 155;
	expected[2] = 12;
	expected[3] = 235;
	expected[4] = 43;
	expected[5] = 249;
	expected[6] = 172;
	expected[7] = 125;
	expected[8] = 117;
	expected[9] = 41;
	expected[10] = 128;
	expected[11] = '\0';
	compress_test((unsigned char *)"Vamos aprender a programa", expected);
	expected[0] = 64;
	expected[1] = '\0';
	compress_test((unsigned char *)"ab", expected);
	expected[0] = '\0';
	compress_test((unsigned char *)"aaaa", expected);
	compress_test((unsigned char *)"aaaaaaaaa", expected);
	compress_test((unsigned char *)"", expected);
}

