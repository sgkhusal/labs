/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 09:28:24 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/14 18:13:03 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "encoder.h"

void	send_freq(unsigned int *freq)
{
	int		block_id;
	char	*shared_memory;

	block_id = create_shared_block(FILENAME, sizeof(unsigned int) * ASCII_SIZE, 0);
	shared_memory = attach_memory_block(block_id);
	if (shared_memory == NULL)
		shared_memory_error("encoder: send_freq");
	memcpy(shared_memory, freq, sizeof(unsigned int) * ASCII_SIZE);
	dettach_memory_block(shared_memory);
}

void	send_nbits(size_t nbits)
{
	int		block_id;
	size_t	*shared_memory;

	block_id = create_shared_block(FILENAME, sizeof(size_t), 1);
	shared_memory = (size_t *)attach_memory_block(block_id);
	if (shared_memory == NULL)
		shared_memory_error("encoder: send_nbits");
	*shared_memory = nbits;
	dettach_memory_block((char *)shared_memory);
}

void	send_bits(unsigned char *bits)
{
	int		block_id;
	char	*shared_memory;
	size_t	size;

	size = strlen((char *)bits);
	block_id = create_shared_block(FILENAME, sizeof(char) * size, 2);
	shared_memory = attach_memory_block(block_id);
	if (shared_memory == NULL)
		shared_memory_error("encoder: send_nbits");
	strncpy(shared_memory, (char *)bits, size);
	dettach_memory_block(shared_memory);
}
