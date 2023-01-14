/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:41:30 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/14 16:21:36 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "encoder.h"

static void	create_file(void)
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

unsigned char	*get_text(char **strs)
{
	unsigned char	*text;
	int				i;
	size_t			size;

	i = 0;
	size = 0;
	while (strs[i])
	{
		size += strlen(strs[i]);
		i++;
	}
	text = (unsigned char *)calloc(size + i + 1, sizeof(char));
	if (!text)
		malloc_error("encoder: get_text");
	strcat((char *)text, strs[0]);
	i = 1;
	while (strs[i])
	{
		strcat((char *)text, "\a");
		strcat((char *)text, strs[i]);
		i++;
	}
	return (text);
}

int	main(int argc, char *argv[])
{
	unsigned char	*text;
	//bool			files;

	if (argc == 1)
	{
		printf("No data received by encoder\n");
		printf("usage - %s [\"str1\"] [\"str2\"] ... (data to compress)", argv[0]);
		//printf("usage - %s -f [filename]", argv[0]);
		return (1); // ver como vai lidar no encoder - semáforo indicando que deu problema?
	}
	printf("\nencoder initialized...\n");
	create_file();
	clean_shared_memory();
	// verificar se a string recebida é nula ou vazia e retornar
	text = get_text(&argv[1]); // caso especial: ""
	compress(text);
	receive_data();
	return (0);
}
