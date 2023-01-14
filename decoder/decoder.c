/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decoder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:35:16 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/14 11:03:10 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "decoder.h"

unsigned char	*decode(char *str_bits, unsigned int *freq)
{
	t_huffman		*head;
	unsigned char	*str;

	head = create_huffman_lst(freq);
	head = create_huffman_tree(&head);
	str = huffman_decode(head, str_bits);
	free_tree(head);
	free(str_bits);
	return(str);
}

t_data	decompress(void)
{
	unsigned int	*freq;
	char			*bits;
	char			*str_bits;
	t_data			data;
	size_t			nbits;
	long long		start;

	start = time_now();
	freq = get_freq();
	nbits = get_nbits();
	bits = get_bits();
	printf("nbits: %lu\n", nbits);
	str_bits = huffman_decompress((unsigned char *)bits, nbits);
	data.str = decode(str_bits, freq);
	data.time = (double)get_delta_time(start) / 1000;
	data.nbits_dcmp = number_of_bits((char *)data.str);
	data.nbits_cmp = nbits;
	free(bits);
	return (data);
}
