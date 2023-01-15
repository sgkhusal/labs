/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmpanalyzer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:40:00 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/15 01:49:49 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmpanalyzer.h"

int	main(int argc, char *argv[])
{
	int	encoder;
	int	decoder;

	if (argc == 1)
	{
		dprintf(2, RED "\ncmpanalyzer: error: no data received\n\n" RESET);
		dprintf(2, GREY "usage: %s [\"str1\"] [\"str2\"] ... (data to compress)\n" RESET,
				argv[0]);
		dprintf(2, GREY "usage: %s -f [filename1] [filename2]...\n\n" RESET, argv[0]);
		return (1);
	}
	header();
	encoder = execute_encoder(argc - 1, &argv[1]);
	decoder = execute_decoder();
	encoder = wait_for_child(encoder);
	decoder = wait_for_child(decoder);
	cat();
	if (encoder > 0)
		return (encoder);
	return (decoder);
}
