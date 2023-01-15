/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:41:30 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/15 01:57:50 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "encoder.h"

static void	create_shared_file(void)
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

static void	check_argc(int argc, char *program)
{
	if (argc == 1)
	{
		dprintf(2, RED "\nencoder: error: no data received by encoder\n\n" RESET);
		dprintf(2, GREY "usage: %s [\"content 1\"] [\"content2 2\"]... " \
				"(data to compress)\n" RESET, program);
		dprintf(2, GREY "usage: %s -f [filename1] [filename2]...\n\n" RESET, program);
		stop_decoder(true);
		init_decoder();
		exit (1);
	}
}

int	main(int argc, char *argv[])
{
	unsigned char	*text;

	printf(YELLOW "\nencoder initialized...\n" RESET);
	check_argc(argc, argv[0]);
	create_shared_file();
	clean_shared_memory();
	text = get_text(&argv[1]);
	if (!text[0])
	{
		printf(RED "\nencoder: error: data received is empty\n\n" RESET);
		stop_decoder(true);
		init_decoder();
		return (1);
	}
	stop_decoder(false);
	compress(text);
	init_decoder();
	free(text);
	receive_data();
	return (0);
}
