/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decompress.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:01:44 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/13 19:15:34 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "huffman.h"

char	*huffman_decompress(unsigned char *bits, size_t nbits)
{
	char	*bit_str;
	size_t	nbytes;
	int		powder;
	int		j;

	bit_str = (char *)calloc(nbits + 1, sizeof(char));
	if (!bit_str)
		malloc_error("decompress function");
	nbytes = number_of_bytes(nbits);
	for (size_t i = 0; i < nbytes; i++)
	{
		powder = 7;
		j = 0;
		while (i * 8 + j < nbits && j < 8)
		{
			if (bits[i] & (unsigned char)(pow(2, powder)))
				bit_str[i * 8 + j] = '1';
			else
				bit_str[i * 8 + j] = '0';
			powder--;
			j++;
		}
	}
	return (bit_str);
}
