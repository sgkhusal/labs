/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:40:00 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/13 12:39:33 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "analysis.h"

int	main(int argc, char *argv[])
{
	if (argc == 1)
	{
		printf("No data received\n");
		return (1);
	}
	printf("%s\n", argv[argc - 1]);

	// fork para executar o encoder
	// fork para executar o decoder
	// pipes para mínima funcionalidade

	// parte 2: implementar shared memory
	// parte 3: implementar flag de arquivos
	return (analysis());
}
