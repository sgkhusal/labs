/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frequency_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:37:07 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/10 17:27:34 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

static	int	check_zeros(int unsigned *result)
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

static void	frequency_test1(void)
{
	unsigned int	*result;

	printf(GREY "frequency_test 1: " END);
	result = huffman_frequency("Hello world");
	if (result['H'] == 1 && result['e'] == 1 && result['l'] == 3
		&& result['o'] == 2 && result['w'] == 1 && result['r'] == 1
		&& result['d'] == 1)
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	free(result);
}

static void	frequency_test2(void)
{
	unsigned int	*result;

	printf(GREY "frequency_test 2: " END);
	result = huffman_frequency("");
	check_zeros(result);
	free(result);
}

static void	frequency_test3(void)
{
	unsigned int	*result;

	printf(GREY "frequency_test 3: " END);
	result = huffman_frequency("\t\n\v\f\rçãÃ");
	if (result['\t'] == 1 && result['\n'] == 1 && result['\v'] == 1
		&& result['\f'] == 1 && result['\r'] == 1)
		//&& result[(unsigned char)('Ã')] == 1)
		printf(GREEN "OK" END "\n");
	else
		printf(RED "KO" END "\n");
	free(result);
}

static void	init_frequency_test(void)
{
	unsigned int	*result;

	printf(GREY "init_frequency_test: " END);
	result = init_frequency();
	check_zeros(result);
	free(result);
}

void	frequency_tests(void)
{
	printf(YELLOW "Huffan Coding - Frequency tests: " END "\n");
	init_frequency_test();
	frequency_test1();
	frequency_test2();
	frequency_test3();
}
