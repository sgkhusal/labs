/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:41:30 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/13 20:41:32 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "decoder.h"

int	main(void)
{
	int		block_id;
	char	*shared_memory;
	char	*bits;

	block_id = create_shared_block(FILENAME, 0, 0);
	printf("block_id = %i\n", block_id);
	shared_memory = attach_memory_block(block_id);
	if (shared_memory == NULL)
		return (printf("Error creating shared memory for encoder\n"));
	bits = shared_memory;
	decoder(32, bits);
	dettach_memory_block(shared_memory);
	destroy_memory_block(block_id);

	return (0);
}
