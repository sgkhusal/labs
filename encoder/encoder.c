/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encoder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:25:28 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/13 19:31:23 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "encoder.h"

/* Encoder:
	open file
	read file
	apply huffman coding
	6. Send the encoded text to the shared memory
	7. Read the info from the decoder and display it
	close file
	*/

/* Decoder:
	open file
	read file
	1. Aplly the translation table */

char	*encode(unsigned char *text)
{
	unsigned int	*freq;
	t_huffman		*head;
	char			**d;
	char			*str_bit;

	freq = huffman_frequency(text);
	head = create_huffman_lst(freq);
	head = create_huffman_tree(&head);
	d = dictionary(head);
	str_bit = huffman_encode(d, text);
	free(freq);
	free_tree(head);
	free_dictionary(d);
	return (str_bit);
}

char	*compress(char *str_bit)
{
	size_t	nbits;
	char	*bits;

	nbits = number_of_bits(str_bit);
	bits = huffman_compress(str_bit, nbits);
	free(str_bit);
	return (bits);
}
