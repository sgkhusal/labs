/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:41:30 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/13 16:27:41 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "encoder.h"

//int	main(int argc, char *argv[])
int	main(void)
{
	// verificar se a string recebida é nula ou vazia e retornar
	// mandar uma mensagem?
	/* if (argc == 1)
	{
		printf("No data received by encoder\n");
		return (encoder((unsigned char *)""));
	} */
	return (encoder((unsigned char *)"Hello World"));
}
