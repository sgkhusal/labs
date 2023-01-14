/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:41:30 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/14 19:41:17 by sguilher         ###   ########.fr       */
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

unsigned char	*read_file(char *file)
{
	FILE			*fs;
	unsigned char	*content;
	long			size;

	fs = fopen(file, "r");
	if (!fs)
		return (NULL);
	fseek(fs, 0, SEEK_END); // manda o cursor para o final do arquivo
	size = ftell(fs); // dá a posição atual do cursor
	rewind(fs); // volta o cursor para o começo do arquivo
	content = (unsigned char *)malloc(size * sizeof(char));
	fread(content, 1, size, fs);
	fclose(fs);
	return (content);
}

/* unsigned char	*read_files(char **files)
{
	int	i;


} */

unsigned char	*get_text(char **strs)
{
	unsigned char	*text;
	int				i;
	size_t			size;

	if (strcmp(strs[0], "-f") == 0)
		return (read_file(strs[1]));
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
		if (strs[i][0])
		{
			strcat((char *)text, "\v");
			strcat((char *)text, strs[i]);
		}
		i++;
	}
	return (text);
}

int	main(int argc, char *argv[])
{
	unsigned char	*text;

	printf("\nencoder initialized...\n");
	if (argc == 1)
	{
		dprintf(2, "encoder: error: no data received by encoder\n\n");
		dprintf(2, "usage: %s [\"content 1\"] [\"content2 2\"]... " \
				"(data to compress)\n", argv[0]);
		dprintf(2, "usage: %s -f [filename1] [filename2]...\n\n", argv[0]);
		stop_decoder(true);
		return (1);
	}
	create_file();
	clean_shared_memory();
	text = get_text(&argv[1]);
	if (!text[0])
	{
		printf("encoder: error: data received is empty\n\n");
		stop_decoder(true);
		return (1);
	}
	//printf("text = |%s|\n", text);
	stop_decoder(false);
	compress(text);
	receive_data();
	return (0);
}
