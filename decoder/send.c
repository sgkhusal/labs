/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 10:46:18 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/14 18:11:34 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "decoder.h"

void	send_nbits_cmp(size_t nbits_cmp)
{
	int		block_id;
	size_t	*shared_memory;

	block_id = create_shared_block(FILENAME, sizeof(size_t), 3);
	shared_memory = (size_t *)attach_memory_block(block_id);
	if (shared_memory == NULL)
		shared_memory_error("decoder: send_nbits_cmp");
	*shared_memory = nbits_cmp;
	dettach_memory_block((char *)shared_memory);
}

void	send_nbits_dcmp(size_t nbits_dcmp)
{
	int		block_id;
	size_t	*shared_memory;

	block_id = create_shared_block(FILENAME, sizeof(size_t), 4);
	shared_memory = (size_t *)attach_memory_block(block_id);
	if (shared_memory == NULL)
		shared_memory_error("decoder: send_nbits_dcmp");
	*shared_memory = nbits_dcmp;
	dettach_memory_block((char *)shared_memory);
}

void	send_time(double time)
{
	int		block_id;
	double	*shared_memory;

	block_id = create_shared_block(FILENAME, sizeof(double), 5);
	shared_memory = (double *)attach_memory_block(block_id);
	if (shared_memory == NULL)
		shared_memory_error("decoder: send_time");
	*shared_memory = time;
	dettach_memory_block((char *)shared_memory);
}

void	send_str(unsigned char *str)
{
	int		block_id;
	char	*shared_memory;
	size_t	size;

	if (str)
		size = strlen((char *)str);
	else
		size = 1;
	block_id = create_shared_block(FILENAME, sizeof(char) * size, 6);
	shared_memory = attach_memory_block(block_id);
	if (shared_memory == NULL)
		shared_memory_error("decoder: send_str");
	strncpy(shared_memory, (char *)str, size);
	dettach_memory_block(shared_memory);
}
