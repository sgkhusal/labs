/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 09:41:11 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/14 10:09:18 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "decoder.h"

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

size_t	get_nbits(void)
{
	int		block_id;
	unsigned char	*shared_memory;
	size_t	nbits;

	block_id = create_shared_block(FILENAME, 0, 1);
	shared_memory = (unsigned char	*)attach_memory_block(block_id);
	if (shared_memory == NULL)
		shared_memory_error("get_nbits in decoder");
	nbits = *shared_memory;
	printf("nbits: %lu\n", nbits);
	dettach_memory_block((char *)shared_memory);
	destroy_memory_block(block_id);
	return (nbits);
}

char	*get_bits(void)
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
