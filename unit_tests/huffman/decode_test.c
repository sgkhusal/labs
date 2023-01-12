/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decode_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 22:08:55 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/12 17:58:24 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

void	decode_test(unsigned char *str)
{
	unsigned int	*freq;
	t_huffman		*head;
	char			**d;
	unsigned char	*result;
	char			*str_bit;
	static int		n = 1;

	printf(GREY "decode_test %d - |%s|: " END, n, str);
	freq = huffman_frequency(str);
	head = create_huffman_lst(freq);
	head = create_huffman_tree(&head);
	d = dictionary(head);
	str_bit = encode(d, str);
	result = decode(head, str_bit);
	if (strcmp((const char *)result, (const char *)str))
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

void	decode_tests(void)
{
	printf(YELLOW "Huffan Coding - decoding tests: " END "\n");
	decode_test((unsigned char *)TEST1);
	decode_test((unsigned char *)"Vamos aprender a programa");
	decode_test((unsigned char *)"ab");
	decode_test((unsigned char *)"aaaa");
	decode_test((unsigned char *)"");
}
