/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   huffman_coding.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:42:12 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/12 17:41:12 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "huffman.h"

/* Huffman coding:
	1. Count how many times each character is used - structure char and frequency - OK
	2. Order them in a list from the least used to the most used - OK
	3. Create the Huffman Tree: - OK!!
	- Put the 2 least used characters in the bottom branches and sum their frequencies into the top branch
	- Add the node sum back to the list, in the right order
	- Repeat the process until you have only one character on the list
	4. Create the encoding/translation table according with the Huffman Tree - OK
	5. Encode the text using the table - OK
	6. Decode the str of bits using the tree - OK
	7. Compression - transform the str of bits into real bits - OK
	8. Decompression - transform the bits into the string of bits
	close file
	*/

void	huffman_coding(void)
{
	unsigned int	*freq;
	t_huffman		*head;
	char			**d;
	char			*str_bit;
	size_t			nb_bits;
	unsigned char	*bits;
	unsigned char	*str;

	freq = huffman_frequency((unsigned char *)"Hello World");
	head = create_huffman_lst(freq);
	head = create_huffman_tree(&head);
	d = dictionary(head);
	str_bit = encode(d, (unsigned char *)"Hello World");
	printf("%s\n", str_bit);
	nb_bits = number_of_bits(str_bit);
	bits = compress(str_bit, nb_bits);
	//(void)bits;
	printf("%s\n", bits);
	str = decode(head, str_bit);
	printf("%s\n", str);
	free(freq);
	free_dictionary(d);
	free(str_bit);
	free(str);
	free_tree(head);
}
