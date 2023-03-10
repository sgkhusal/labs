/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 09:41:11 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/15 03:30:45 by sguilher         ###   ########.fr       */
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
		shared_memory_error("decoder: get_freq");
	memcpy(freq, shared_memory, sizeof(unsigned int) * ASCII_SIZE);
	dettach_memory_block(shared_memory);
	destroy_memory_block(block_id);
	return (freq);
}

size_t	get_nbits(void)
{
	int		block_id;
	size_t	*shared_memory;
	size_t	nbits;

	block_id = create_shared_block(FILENAME, 0, 1);
	shared_memory = (size_t	*)attach_memory_block(block_id);
	if (shared_memory == NULL)
		shared_memory_error("decoder: get_nbits");
	nbits = *shared_memory;
	dettach_memory_block((char *)shared_memory);
	destroy_memory_block(block_id);
	return (nbits);
}

char	*get_bits(size_t nbits)
{
	int		block_id;
	char	*shared_memory;
	char	*bits;

	block_id = create_shared_block(FILENAME, 0, 2);
	shared_memory = attach_memory_block(block_id);
	if (shared_memory == NULL)
		shared_memory_error("decoder: get_bits");
	bits = (char *)malloc((nbits + 1) * sizeof(char));
	memcpy(bits, shared_memory, sizeof(char) * (nbits + 1));
	dettach_memory_block(shared_memory);
	destroy_memory_block(block_id);
	return (bits);
}
