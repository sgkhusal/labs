/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 12:22:09 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/15 02:23:37 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "decoder.h"

void	move_on(void)
{
	int	block_id;
	int	*semaphore;

	block_id = create_shared_block(FILENAME, 0, 7);
	semaphore = (int *)attach_memory_block(block_id);
	if (semaphore == NULL)
		shared_memory_error("decoder: move_on");
	*semaphore = 1;
	dettach_memory_block((char *)semaphore);
}

void	check_if_must_stop(void)
{
	int	block_id;
	int	*stop;

	block_id = create_shared_block(FILENAME, 0, 8);
	stop = (int *)attach_memory_block(block_id);
	if (stop == NULL)
		shared_memory_error("decoder: check_if_must_stop");
	if (*stop)
	{
		printf(RED \
			"\ndecoder: error: no data received by encoder - decoder closed\n\n" \
			RESET);
		dettach_memory_block((char *)stop);
		destroy_memory_block(block_id);
		exit(1);
	}
	dettach_memory_block((char *)stop);
	destroy_memory_block(block_id);
}

void	wait_encoder(void)
{
	int	block_id;
	int	*semaphore;

	block_id = create_shared_block(FILENAME, sizeof(int), 9);
	semaphore = (int *)attach_memory_block(block_id);
	if (semaphore == NULL)
		shared_memory_error("decoder: wait_encoder");
	*semaphore = 0;

	while (!(*semaphore))
		sleep(1);

	dettach_memory_block((char *)semaphore);
	destroy_memory_block(block_id);
}
