/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:40:00 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/13 16:26:22 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "analysis.h"
/* O desafio consiste no desenvolvimento de uma aplicação de análise e
compressão de dados. Essa aplicação utilizará o algoritmo de compressão Huffman
e poderá receber múltiplos dados onde, uma vez que comprimido deve ser
descomprimido e coletar informações pertinentes para a análise do processo e
dado. */

/* int	execute_encoder(char *strs[]) {

} */

int	main(int argc, char *argv[])
{
	//int	pipe1[2];
	//int	pipe2[2];
	int	child_pid;
	int	check;

	if (argc == 1)
	{
		printf("No data received\n");
		return (1);
	}
	printf("%s\n", argv[argc - 1]);
	child_pid = fork();
	if (child_pid == 0) {

		check = execl("./encoder/encoder.bin", "encoder.bin", "Hello World", NULL);
		if (check == -1)
			dprintf(2, "Error on encoder execution\n");
		exit(1);
	}
	child_pid = fork();
	if (child_pid == 0) {
		check = execl("./decoder/decoder.bin", "decoder.bin", NULL);
		if (check == -1)
			dprintf(2, "Error on decoder execution\n");
		exit(1);
	}
	// pipes para mínima funcionalidade

	// parte 2: implementar shared memory
	// parte 3: implementar flag de arquivos
	return (analysis());
}
