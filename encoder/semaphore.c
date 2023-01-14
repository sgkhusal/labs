/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 12:15:29 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/14 17:45:10 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "encoder.h"

void	wait_semaphore(void)
{
	int	block_id;
	int	*semaphore;

	block_id = create_shared_block(FILENAME, sizeof(int), 7);
	semaphore = (int *)attach_memory_block(block_id);
	if (semaphore == NULL)
		shared_memory_error("encoder: wait_semaphore");
	*semaphore = 0;

	while (!(*semaphore))
		sleep(1);

	dettach_memory_block((char *)semaphore);
	destroy_memory_block(block_id);
}

void	stop_decoder(bool yes)
{
	int	block_id;
	int	*stop;

	block_id = create_shared_block(FILENAME, sizeof(int), 8);
	stop = (int *)attach_memory_block(block_id);
	if (stop == NULL)
		shared_memory_error("encoder: stop_decoder");
	*stop = yes;
	dettach_memory_block((char *)stop);
}
