/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decoder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:35:16 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/14 02:17:21 by sguilher         ###   ########.fr       */
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

unsigned int	*get_freq(void)
{
	int		block_id;
	char	*shared_memory;
	unsigned int *freq;

	freq = init_frequency();
	block_id = create_shared_block(FILENAME, 0, 0);
	shared_memory = attach_memory_block(block_id);
	if (shared_memory == NULL)
		shared_memory_error("get_freq in decoder");
	memcpy(freq, shared_memory, sizeof(unsigned int) * ASCII_SIZE);
	for (int i = 0; i < ASCII_SIZE; i++) {
		if (freq[i] > 0)
			printf("%c - freq = %i\n", i, freq[i]);
	}
	dettach_memory_block(shared_memory);
	destroy_memory_block(block_id);
	return (freq);
}

static size_t	get_nbits(void)
{
	int		block_id;
	char	*shared_memory;
	size_t	nbits;

	block_id = create_shared_block(FILENAME, 0, 1);
	shared_memory = attach_memory_block(block_id);
	if (shared_memory == NULL)
		shared_memory_error("get_nbits in decoder");
	nbits = *shared_memory;
	printf("nbits: %lu\n", nbits);
	dettach_memory_block(shared_memory);
	destroy_memory_block(block_id);
	return (nbits);
}

static char	*get_bits(void)
{
	int		block_id;
	char	*shared_memory;
	char	*bits;
	//size_t	nbytes;

	block_id = create_shared_block(FILENAME, 0, 2);
	shared_memory = attach_memory_block(block_id);
	if (shared_memory == NULL)
		shared_memory_error("get_bits in decoder");
	//nbytes =number_of_bytes(nbits);
	//bits = (char *)calloc(nbytes, sizeof(char));
	// if malloc error
	//memcpy(bits, shared_memory, sizeof(char) * nbytes);
	bits = strdup(shared_memory);
	dettach_memory_block(shared_memory);
	destroy_memory_block(block_id);
	return (bits);
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
	data.str_nbits = number_of_bits((char *)data.str);
	free(bits);
	return (data);
}
