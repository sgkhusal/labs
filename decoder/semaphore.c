/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 12:22:09 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/14 12:38:15 by sguilher         ###   ########.fr       */
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
		shared_memory_error("send_nbits in encoder");
	*semaphore = 1;
	dettach_memory_block((char *)semaphore);
}
