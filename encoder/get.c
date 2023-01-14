/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 09:28:20 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/14 16:21:01 by sguilher         ###   ########.fr       */
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
		shared_memory_error("get_nbits_cmp in encoder");
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
		shared_memory_error("get_nbits_dcmp in encoder");
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
		shared_memory_error("get_time in encoder");
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
		shared_memory_error("get_nstr in encoder");
	str = (unsigned char *)strdup((char *)shared_memory);
	dettach_memory_block((char *)shared_memory);
	destroy_memory_block(block_id);
	return (str);
}

void	print_strings(unsigned char* strs)
{
	size_t	i;
	int		n;

	i = 0;
	n = 1;
	printf("Data 1:\n\n");
	while (strs[i])
	{
		if (strs[i] != '\a')
			printf("%c", strs[i]);
		else
		{
			n++;
			printf("\n\n------------------------------------------------------------------\n");
			printf("Data %d:\n\n", n);
		}
		i++;
	}
}

void	print_data(t_data const data)
{
	printf("\n");
	printf("------------------------------------------------------------------\n");
	printf("            DATA RECEIVED BY ENCODER FROM DECODER\n");
	printf("------------------------------------------------------------------\n");
	printf("                compressed bits: \t%lu\n", data.nbits_cmp);
	printf("              decompressed bits: \t%lu\n", data.nbits_dcmp);
	printf("             decompression time: \t%f s\n", data.time);
	printf("------------------------------------------------------------------\n\n");
	printf("                      Data decompressed: \n\n");
	print_strings(data.str);
	printf("\n\n-------------------- compression rate: %.2f%% --------------------\n\n",
			((double)data.nbits_cmp / (double)data.nbits_dcmp * (double)100));
}

void	receive_data(void)
{
	t_data	data;

	wait_semaphore();
	data.nbits_cmp = get_nbits_cmp();
	data.nbits_dcmp = get_nbits_dcmp();
	data.time = get_time();
	data.str = get_str();
	print_data(data);
}
