/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmpanalyzer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:40:00 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/14 22:54:25 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmpanalyzer.h"

int	main(int argc, char *argv[])
{
	int	encoder;
	int	decoder;

	if (argc == 1)
	{
		dprintf(2, "\ncmpanalyzer: error: no data received\n\n");
		dprintf(2, "usage: %s [\"str1\"] [\"str2\"] ... (data to compress)\n",
				argv[0]);
		dprintf(2, "usage: %s -f [filename1] [filename2]...\n\n", argv[0]);
		return (1);
	}
	encoder = execute_encoder(argc - 1, &argv[1]);
	sleep(1);
	decoder = execute_decoder();
	encoder = wait_for_child(encoder);
	decoder = wait_for_child(decoder);
	if (encoder > 0)
		return (encoder);
	return (decoder);
}
