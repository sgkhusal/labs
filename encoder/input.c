/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 20:55:58 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/15 03:21:35 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "encoder.h"

static void	file_error(const char *filename, const char *error)
{
	dprintf(2, RED "\nencoder: %s: %s\n\n" RESET, filename, error);
	stop_decoder(true);
	init_decoder();
	exit(2);
}

unsigned char	*read_file(char *file)
{
	FILE			*fs;
	unsigned char	*content;
	unsigned long	size;

	if (access(file, F_OK))
		file_error(file, "error accessing file");
	fs = fopen(file, "r");
	if (fs == NULL)
		file_error(file, "error opening file");
	fseek(fs, 0, SEEK_END); // manda o cursor para o final do arquivo
	size = ftell(fs); // dá a posição atual do cursor
	if (size == MAX_L_INT)
		file_error(file, "error reading file");
	rewind(fs); // volta o cursor para o começo do arquivo
	content = (unsigned char *)malloc(size * sizeof(char) + 1);
	fread(content, 1, size, fs); // lê todo o conteúdo
	fclose(fs);
	content[size] = '\0';
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
	unsigned char	*text;

	i = 0;
	while (files[i])
		i++;
	contents = (unsigned char **)malloc((i + 1) * sizeof(char *));
	if (!contents)
		malloc_error("encoder: read_files");
	i = -1;
	while (files[++i])
		contents[i] = read_file(files[i]);
	contents[i] = NULL;
	text = join_strs((char **)contents);
	i = -1;
	while (contents[++i])
		free(contents[i]);
	free(contents);
	return (text);
}

unsigned char	*get_text(char **strs)
{

	if (strcmp(strs[0], "-f") == 0)
		return (read_files(&strs[1]));
	return (join_strs(strs));
}
