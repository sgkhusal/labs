/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frequency.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:33:44 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/10 15:50:26 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "huffman.h"

unsigned int	*huffman_frequency(char *str)
{
	unsigned int	*freq;
	unsigned int	i;

	freq = init_frequency();
	i = 0;
	while (str[i])
	{
		freq[(int) str[i]]++;
		i++;
	}
	return (freq);
}

unsigned int	*init_frequency(void)
{
	unsigned int	*freq;
	unsigned int	i;

	freq = (unsigned int *)malloc(sizeof(unsigned int) * ASCII_SIZE);
	i = 0;
	while (i < ASCII_SIZE)
	{
		freq[i] = 0;
		i++;
	}
	return (freq);
}
