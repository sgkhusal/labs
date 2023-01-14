/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:41:30 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/14 01:35:24 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "encoder.h"

static void	create_file(void)
{
	int	fd;

	fd = open(FILENAME, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd != -1)
		close(fd);
}

static void	clean_shared_memory(void)
{
	destroy_memory_block(create_shared_block(FILENAME, 0, 0));
	destroy_memory_block(create_shared_block(FILENAME, 0, 1));
}

int	main(int argc, char *argv[])
{
	unsigned char	*text;

	if (argc == 1)
	{
		printf("No data received by encoder\n");
		printf("usage - %s [\"str1\"] [\"str2\"] ... (data to compress)", argv[0]);
		//printf("usage - %s -f [filename]", argv[0]);
		return (1);
	}
	printf("Initializing encoder...\n");
	create_file();
	clean_shared_memory();
	// tratar os inputs recebidos para ficar com apenas uma string
	// verificar se a string recebida é nula ou vazia e retornar
	text = (unsigned char *)argv[1];

	compress(text);
	//get_data_from_decoder();
	// ler as infos do decoder
	// printar as infos
	//printf("delta time: %f s\n", data.time);
	return (0);
}
