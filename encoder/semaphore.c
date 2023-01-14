/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 12:15:29 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/14 12:34:13 by sguilher         ###   ########.fr       */
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
		shared_memory_error("send_nbits in encoder");
	*semaphore = 0;

	while (!(*semaphore))
		sleep(1);

	dettach_memory_block((char *)semaphore);
	destroy_memory_block(block_id);
}
