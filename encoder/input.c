/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 20:55:58 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/14 23:45:27 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "encoder.h"

static void	error_open_file(const char *filename)
{
	dprintf(2, "Error open file: %s\n", filename);
	stop_decoder(true);
	init_decoder();
	exit(2);
}

unsigned char	*read_file(char *file)
{
	FILE			*fs;
	unsigned char	*content;
	long			size;

	fs = fopen(file, "r");
	if (!fs)
		error_open_file(file);
	fseek(fs, 0, SEEK_END); // manda o cursor para o final do arquivo
	size = ftell(fs); // dá a posição atual do cursor
	rewind(fs); // volta o cursor para o começo do arquivo
	content = (unsigned char *)malloc(size * sizeof(char));
	fread(content, 1, size, fs); // lê todo o conteúdo
	fclose(fs);
	return (content);
}

unsigned char	*join_strs(char **strs)
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
		if (strs[i][0])
		{
			strcat((char *)text, "\v");
			strcat((char *)text, strs[i]);
		}
		i++;
	}
	return (text);
}

unsigned char	*read_files(char **files)
{
	int				i;
	unsigned char	**contents;

	i = 0;
	while (files[i])
		i++;
	contents = (unsigned char **)malloc((i + 1) * sizeof(char *));
	if (!contents)
		malloc_error("encoder: read_files");
	i = 0;
	while (files[i])
	{
		contents[i] = read_file(files[i]);
		i++;
	}
	contents[i] = NULL;
	return (join_strs((char **)contents));
}

unsigned char	*get_text(char **strs)
{

	if (strcmp(strs[0], "-f") == 0)
		return (read_files(&strs[1]));
	return (join_strs(strs));
}
