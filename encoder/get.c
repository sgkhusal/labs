/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 09:28:20 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/14 11:59:18 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "encoder.h"

size_t	get_nbits_cmp(void)
{
	int		block_id;
	size_t	*shared_memory;
	size_t	nbits_cmp;

	block_id = create_shared_block(FILENAME, 0, 3);
	shared_memory = (size_t *)attach_memory_block(block_id);
	if (shared_memory == NULL)
		shared_memory_error("get_nbits_cmp in encoder");
	nbits_cmp = *shared_memory;
	printf("nbits_cmp received: %lu\n", nbits_cmp);
	dettach_memory_block((char *)shared_memory);
	destroy_memory_block(block_id);
	return (nbits_cmp);
}

size_t	get_nbits_dcmp(void)
{
	int		block_id;
	size_t	*shared_memory;
	size_t	nbits_dcmp;

	block_id = create_shared_block(FILENAME, 0, 4);
	shared_memory = (size_t *)attach_memory_block(block_id);
	if (shared_memory == NULL)
		shared_memory_error("get_nbits_dcmp in encoder");
	nbits_dcmp = *shared_memory;
	dettach_memory_block((char *)shared_memory);
	destroy_memory_block(block_id);
	printf("nbits_dcmp received: %lu\n", nbits_dcmp);
	return (nbits_dcmp);
}

double	get_time(void)
{
	int		block_id;
	double	*shared_memory;
	double	time;

	block_id = create_shared_block(FILENAME, 0, 5);
	shared_memory = (double *)attach_memory_block(block_id);
	if (shared_memory == NULL)
		shared_memory_error("get_time in encoder");
	time = *shared_memory;
	dettach_memory_block((char *)shared_memory);
	destroy_memory_block(block_id);
	printf("time received: %f\n", time);
	return (time);
}

unsigned char	*get_str(void)
{
	int				block_id;
	unsigned char	*shared_memory;
	unsigned char	*str;

	block_id = create_shared_block(FILENAME, 0, 6);
	shared_memory = (unsigned char *)attach_memory_block(block_id);
	if (shared_memory == NULL)
		shared_memory_error("get_nstr in encoder");
	str = (unsigned char *)strdup((char *)shared_memory);
	dettach_memory_block((char *)shared_memory);
	destroy_memory_block(block_id);
	return (str);
}
