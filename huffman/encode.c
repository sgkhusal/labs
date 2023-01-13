/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encode.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:44:11 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/13 18:48:22 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "huffman.h"

static size_t	str_encode_size(char **dictionary, unsigned char *text)
{
	int		i;
	size_t	size;
	size_t	sizes[ASCII_SIZE];

	i = 0;
	while (i < ASCII_SIZE)
	{
		sizes[i] = strlen(dictionary[i]);
		i++;
	}
	i = 0;
	size = 0;
	while (text[i])
	{
		size += sizes[text[i]];
		i++;
	}
	return (size + 1);
}

char	*huffman_encode(char **dictionary, unsigned char *text)
{
	int		i;
	size_t	size;
	char	*bit_str;

	if (text[0] == '\0')
		return (NULL);
	size = str_encode_size(dictionary, text);
	bit_str = (char *)calloc(size, sizeof(char));
	if (!bit_str)
		malloc_error("encode function");
	i = 0;
	while (text[i])
	{
		strcat(bit_str, dictionary[text[i]]);
		i++;
	}
	return (bit_str);
}
