/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmpanalyzer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:40:00 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/14 00:25:25 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmpanalyzer.h"
/* O desafio consiste no desenvolvimento de uma aplicação de análise e
compressão de dados. Essa aplicação utilizará o algoritmo de compressão Huffman
e poderá receber múltiplos dados onde, uma vez que comprimido deve ser
descomprimido e coletar informações pertinentes para a análise do processo e
dado. */

/* int	execute_encoder(char *strs[]) {

} */

int	main(int argc, char *argv[])
{
	int	child_pid;
	int	check;

	if (argc == 1)
	{
		printf("No data received\n");
		return (1);
	}
	child_pid = fork();
	if (child_pid == 0) {

		check = execl("./encoder/encoder.bin", "encoder.bin", argv[1], NULL);
		if (check == -1)
			dprintf(2, "Error on encoder execution\n");
		exit(1);
	}
	sleep(1);
	child_pid = fork();
	if (child_pid == 0) {
		check = execl("./decoder/decoder.bin", "decoder.bin", NULL);
		if (check == -1)
			dprintf(2, "Error on decoder execution\n");
		exit(1);
	}

	// parte 2: implementar shared memory
	// parte 3: implementar flag de arquivos
	wait(NULL);
	wait(NULL);
	return (0);
}
