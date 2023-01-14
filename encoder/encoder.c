/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encoder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:25:28 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/14 02:35:01 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "encoder.h"

void	send_freq(unsigned int *freq)
{
	int		block_id;
	char	*shared_memory;

	block_id = create_shared_block(FILENAME, sizeof(unsigned int) * ASCII_SIZE, 0); // arrumar o tamanho
	shared_memory = attach_memory_block(block_id);
	if (shared_memory == NULL)
		shared_memory_error("send_freq in encoder");
	memcpy(shared_memory, freq, sizeof(unsigned int) * ASCII_SIZE);
	dettach_memory_block(shared_memory);
}

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

static void	send_nbits(size_t nbits)
{
	int		block_id;
	int		*shared_memory;

	printf("nbits: %lu\n", nbits);
	block_id = create_shared_block(FILENAME, sizeof(t_data), 1); // arrumar o tamanho
	shared_memory = (int *)attach_memory_block(block_id);
	if (shared_memory == NULL)
		shared_memory_error("send_nbits in encoder");
	//memcpy(shared_memory, &nbits, sizeof(size_t));
	*shared_memory = nbits;
	dettach_memory_block((char *)shared_memory);
}

static void	send_bits(char *bits)
{
	int		block_id;
	char	*shared_memory;
	size_t	size;

	size = strlen(bits);
	block_id = create_shared_block(FILENAME, sizeof(char) * size, 2);
	shared_memory = attach_memory_block(block_id);
	if (shared_memory == NULL)
		shared_memory_error("send_nbits in encoder");
	strncpy(shared_memory, bits, size);
	dettach_memory_block(shared_memory);
}

void	compress(unsigned char *text)
{
	unsigned int	*freq;
	char			*str_bits;
	size_t			nbits;
	char			*bits;

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
