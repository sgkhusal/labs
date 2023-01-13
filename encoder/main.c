/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:41:30 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/13 11:59:38 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "encoder.h"

int	main(int argc, char *argv[])
{
	// verificar se a string recebida é nula ou vazia e retornar
	// mandar uma mensagem?
	if (argc == 1)
	{
		printf("No data received\n");
		return (encoder(0, NULL));
	}
	return (encoder(argc - 1, (unsigned char **)&argv[1]));
}
