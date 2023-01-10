/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frequency.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:33:44 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/10 11:41:50 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "huffman.h"

int	*huffman_frequency(char *str)
{
	int	*freq;
	int	i;

	freq = init_frequency();
	i = 0;
	while (str[i])
	{
		freq[str[i]]++;
		i++;
	}
	return (freq);
}

int	*init_frequency(void)
{
	int	*freq;
	int	i;

	freq = (int *)malloc(sizeof(int) * ASCII_SIZE);
	i = 0;
	while (i < ASCII_SIZE)
	{
		freq[i] = 0;
		i++;
	}
	return (freq);
}
