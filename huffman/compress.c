/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 00:38:26 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/14 22:10:42 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "huffman.h"

size_t	number_of_bits(char *str)
{
	if (!str)
		return (0);
	return (strlen(str));
}

size_t	number_of_bytes(size_t nbits)
{
	size_t	nbytes;

	nbytes = nbits / 8;
	if (nbits % 8 != 0)
		nbytes++;
	return (nbytes);
}

unsigned char	*huffman_compress(char *bit_str, size_t nbits)
{
	unsigned char	*bits;
	size_t			nbytes;
	int				powder;
	int				j;

	nbytes = number_of_bytes(nbits);
	bits = (unsigned char *)calloc(nbytes + 1, sizeof(char));
	if (!bits)
		malloc_error("compress function");
	for (size_t i = 0; i < nbytes; i++)
	{
		powder = 7;
		j = 0;
		while (bit_str[i * 8 + j] && j < 8)
		{
			if (bit_str[i * 8 + j] == '1')
				bits[i] |= (unsigned char)(pow(2, powder));
			powder--;
			j++;
		}
	}
	return (bits);
}
