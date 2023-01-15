/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared_memory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:25:28 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/15 14:18:29 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared_memory.h"

int	create_shared_block(char *filename, int size, int mem_id)
{
	key_t key;

	key = ftok(filename, mem_id);
	if (key == -1)
		return (-1);
	if (size == 0)
		return (shmget(key, size, 0));
	return (shmget(key, size, 0644 | IPC_CREAT));
}

char	*attach_memory_block(int block_id) {
	char	*result;

	if (block_id == -1)
		return (NULL);
	result = shmat(block_id, NULL, 0);
	if (result == (char *)(-1))
		return (NULL);
	return (result);
}

bool dettach_memory_block(char *block) {
	return (shmdt(block) != -1);
}

bool destroy_memory_block(int block_id) {
	return (shmctl(block_id, IPC_RMID, NULL) != -1);
}
