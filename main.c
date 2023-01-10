/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:50:42 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/10 11:04:20 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* O desafio consiste no desenvolvimento de uma aplicação de análise e
compressão de dados. Essa aplicação utilizará o algoritmo de compressão Huffman
e poderá receber múltiplos dados onde, uma vez que comprimido deve ser
descomprimido e coletar informações pertinentes para a análise do processo e
dado. */

#include "analysis.h"

int	main(int argc, char *argv[])
{
	if (argc == 1)
	{
		printf("No data received\n");
		return (1);
	}
	printf("%s\n", argv[argc - 1]);
	// salvar os dados no arquivo temporário
	// fork para executar o encoder
	// fork para executar o decoder
	return (0);
}
