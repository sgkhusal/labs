/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frequency.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:33:44 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/10 23:26:44 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "huffman.h"

unsigned int	*huffman_frequency(unsigned char *str)
{
	unsigned int	*freq;
	unsigned int	i;

	freq = init_frequency();
	i = 0;
	while (str[i])
	{
		freq[(unsigned char) str[i]]++;
		i++;
	}
	return (freq);
}

unsigned int	*init_frequency(void)
{
	unsigned int	*freq;

	freq = (unsigned int *)calloc(ASCII_SIZE, sizeof(unsigned int));
	if (!freq)
		malloc_error("init_frequency");
	return (freq);
}
