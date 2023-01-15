/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 09:28:20 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/15 01:59:24 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "encoder.h"

static size_t	get_nbits_cmp(void)
{
	int		block_id;
	size_t	*shared_memory;
	size_t	nbits_cmp;

	block_id = create_shared_block(FILENAME, 0, 3);
	shared_memory = (size_t *)attach_memory_block(block_id);
	if (shared_memory == NULL)
		shared_memory_error("encoder: get_nbits_cmp");
	nbits_cmp = *shared_memory;
	dettach_memory_block((char *)shared_memory);
	destroy_memory_block(block_id);
	return (nbits_cmp);
}

static size_t	get_nbits_dcmp(void)
{
	int		block_id;
	size_t	*shared_memory;
	size_t	nbits_dcmp;

	block_id = create_shared_block(FILENAME, 0, 4);
	shared_memory = (size_t *)attach_memory_block(block_id);
	if (shared_memory == NULL)
		shared_memory_error("encoder: get_nbits_dcmp");
	nbits_dcmp = *shared_memory;
	dettach_memory_block((char *)shared_memory);
	destroy_memory_block(block_id);
	return (nbits_dcmp);
}

static double	get_time(void)
{
	int		block_id;
	double	*shared_memory;
	double	time;

	block_id = create_shared_block(FILENAME, 0, 5);
	shared_memory = (double *)attach_memory_block(block_id);
	if (shared_memory == NULL)
		shared_memory_error("encoder: get_time");
	time = *shared_memory;
	dettach_memory_block((char *)shared_memory);
	destroy_memory_block(block_id);
	return (time);
}

static unsigned char	*get_str(void)
{
	int				block_id;
	unsigned char	*shared_memory;
	unsigned char	*str;

	block_id = create_shared_block(FILENAME, 0, 6);
	shared_memory = (unsigned char *)attach_memory_block(block_id);
	if (shared_memory == NULL)
		shared_memory_error("encoder: get_nstr");
	str = (unsigned char *)strdup((char *)shared_memory);
	dettach_memory_block((char *)shared_memory);
	destroy_memory_block(block_id);
	return (str);
}

void	receive_data(void)
{
	t_data	data;

	wait_decoder();
	data.nbits_cmp = get_nbits_cmp();
	data.nbits_dcmp = get_nbits_dcmp();
	data.time = get_time();
	data.str = get_str();
	print_data(data);
}
