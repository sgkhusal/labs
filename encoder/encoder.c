/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encoder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:25:28 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/14 12:15:08 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "encoder.h"

char	*encode(unsigned char *text, unsigned int *freq)
{
	t_huffman		*head;
	char			**d;
	char			*str_bit;

	head = create_huffman_lst(freq);
	head = create_huffman_tree(&head);
	d = dictionary(head);
	str_bit = huffman_encode(d, text);
	free_tree(head);
	free_dictionary(d);
	return (str_bit);
}

void	compress(unsigned char *text)
{
	unsigned int	*freq;
	char			*str_bits;
	size_t			nbits;
	unsigned char	*bits;

	freq = huffman_frequency(text);
	send_freq(freq);
	str_bits = encode(text, freq);
	free(freq);
	nbits = number_of_bits(str_bits);
	bits = huffman_compress(str_bits, nbits);
	send_nbits(nbits);
	send_bits(bits);
	free(str_bits);
	free(bits);
}
