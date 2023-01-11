/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:47:51 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/11 16:48:38 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

int	check_zeros(unsigned int *result)
{
	unsigned int	i;

	i = -1;
	while (++i < ASCII_SIZE)
	{
		if (result[i] != 0)
			return (printf(RED "KO at index %d: %d" END "\n", i, result[i]));
	}
	printf(GREEN "OK" END "\n");
	return (0);
}

void	print_frequency(unsigned int *f)
{
	for (int i = 0; i < ASCII_SIZE; i++)
	{
		if (f[i] > 0)
			printf("%d\t|%c|\t%d\n", i, i, f[i]);
	}
}
