/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared_memory.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:23:54 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/13 20:34:18 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARED_MEMORY_H
# define SHARED_MEMORY_H

# include <sys/ipc.h>
# include <sys/shm.h>
# include <string.h>
# include <stdbool.h>

# define BLOCK_SIZE 4096
#define FILENAME "../shared_memory/.sharedmem" /////

int		create_shared_block(char *filename, int size, int mem_id);
char	*attach_memory_block(int block_id);
bool	dettach_memory_block(char *block);
bool	destroy_memory_block(int block_id);

#endif
