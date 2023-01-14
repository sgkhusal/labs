/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decompress_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:18:49 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/14 10:27:14 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

void	decompress_test(unsigned char *str, char *expected)
{
	unsigned int	*freq;
	t_huffman		*head;
	char			**d;
	char			*str_bit;
	char			*result;
	size_t			nbits;
	unsigned char	*bits;
	static int		n = 1;

	printf(GREY "compress_test %d - |%s|: " END, n, str);
	freq = huffman_frequency(str);
	head = create_huffman_lst(freq);
	head = create_huffman_tree(&head);
	d = dictionary(head);
	str_bit = huffman_encode(d, str);
	nbits = number_of_bits(str_bit);
	bits = huffman_compress(str_bit, nbits);
	result = huffman_decompress(bits, nbits);
	if (result && strcmp((char *)result, expected))
		printf(RED "KO" END "\n");
	else if (result == NULL && str != NULL)
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

void	decompress_tests(void)
{
	printf(YELLOW "Huffan Coding - decompress tests: " END "\n");
	decompress_test((unsigned char *)TEST1, "11110101010110111000011001110001");
	decompress_test((unsigned char *)"Vamos aprender a programa",
		"1111000110011011000011001110101100101011111110011010110001111101011101010010100110000");
	decompress_test((unsigned char *)"ab", "01");
	decompress_test((unsigned char *)"aaaa", "0000");
	decompress_test((unsigned char *)"aaaaaaaaa", "000000000");
	decompress_test((unsigned char *)"", "");
}

