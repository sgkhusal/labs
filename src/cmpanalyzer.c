/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmpanalyzer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:40:00 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/14 16:50:47 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmpanalyzer.h"

int	main(int argc, char *argv[])
{
	int	encoder;
	int	decoder;

	if (argc == 1)
	{
		printf("No data received\n");
		return (1);
	}
	// parte 3: implementar flag de arquivos
	encoder = execute_encoder(argc - 1, &argv[1]);
	sleep(1);
	decoder = execute_decoder();
	encoder = wait_for_child(encoder);
	decoder = wait_for_child(decoder);
	if (encoder > 0)
		return (encoder);
	return (decoder);
}
