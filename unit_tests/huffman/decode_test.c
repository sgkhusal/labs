/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decode_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 22:08:55 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/14 09:49:04 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

void	decode_test(unsigned char *str, bool print)
{
	unsigned int	*freq;
	t_huffman		*head;
	char			**d;
	unsigned char	*result;
	char			*str_bit;
	size_t			nbits;
	unsigned char	*bits;
	static int		n = 1;

	printf(GREY "decode_test %d - |%s|: " END, n, str);
	freq = huffman_frequency(str);
	head = create_huffman_lst(freq);
	head = create_huffman_tree(&head);
	d = dictionary(head);
	str_bit = huffman_encode(d, str);
	nbits = number_of_bits(str_bit);
	bits = huffman_compress(str_bit, nbits);
	free(str_bit);
	str_bit = huffman_decompress(bits, nbits);
	result = huffman_decode(head, str_bit);
	if (strcmp((const char *)result, (const char *)str))
		printf(RED "KO" END "\n");
	else
		printf(GREEN "OK" END "\n");
	if (print)
		printf("result: |%s|\n", result);
	free(freq);
	free_tree(head);
	free_dictionary(d);
	free(str_bit);
	free(result);
	n++;
}

void	decode_tests(bool print)
{
	printf(YELLOW "Huffan Coding - decoding tests: " END "\n");
	decode_test((unsigned char *)TEST1, print);
	decode_test((unsigned char *)"Vamos aprender a programa", print);
	decode_test((unsigned char *)"ab", print);
	decode_test((unsigned char *)"aaaa", print);
	decode_test((unsigned char *)"aaaaaaaaa", print);
	decode_test((unsigned char *)"", print);
	decode_test((unsigned char *)"maça", print);
	decode_test((unsigned char *)"ãõáéíóàèìò", print);
}
