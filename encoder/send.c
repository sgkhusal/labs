/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 09:28:24 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/14 10:32:07 by sguilher         ###   ########.fr       */
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

void	send_nbits(size_t nbits)
{
	int		block_id;
	unsigned int		*shared_memory;

	printf("nbits: %lu\n", nbits);
	block_id = create_shared_block(FILENAME, sizeof(t_data), 1); // arrumar o tamanho
	shared_memory = (unsigned int *)attach_memory_block(block_id);
	if (shared_memory == NULL)
		shared_memory_error("send_nbits in encoder");
	//memcpy(shared_memory, &nbits, sizeof(size_t));
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
		shared_memory_error("send_nbits in encoder");
	strncpy(shared_memory, (char *)bits, size);
	dettach_memory_block(shared_memory);
}
