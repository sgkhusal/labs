/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 00:38:26 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/12 17:57:41 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "huffman.h"

size_t	number_of_bits(char *bit_str)
{
	if (!bit_str)
		return (0);
	return (strlen(bit_str));
}

size_t	number_of_bytes(size_t nb_bits)
{
	size_t	n_bytes;

	n_bytes = nb_bits / 8;
	if (nb_bits % 8 != 0)
		n_bytes++;
	return (n_bytes);
}

unsigned char	*compress(char *bit_str, size_t nb_bits)
{
	unsigned char	*bits;
	size_t			n_bytes;
	int				powder;
	int				j;

	n_bytes = number_of_bytes(nb_bits);
	bits = (unsigned char *)calloc(n_bytes + 1, sizeof(char));
	for (size_t i = 0; i < n_bytes; i++)
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
