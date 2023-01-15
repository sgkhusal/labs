/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 01:58:47 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/15 02:44:18 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "encoder.h"

static void	print_strings(unsigned char* strs)
{
	size_t	i;
	int		n;

	i = 0;
	n = 1;
	printf(BLUE "Data 1:\n\n" GREY);
	while (strs[i])
	{
		if (strs[i] != '\v')
			printf("%c", strs[i]);
		else
		{
			n++;
			printf(BLUE "\n\n------------------------------------------------------------------\n");
			printf("Data %d:\n\n" GREY, n);
		}
		i++;
	}
}

void	print_data(t_data const data)
{
	printf("\n" BLUE);
	printf("------------------------------------------------------------------\n");
	printf("            DATA RECEIVED BY ENCODER FROM DECODER\n");
	printf("------------------------------------------------------------------\n");
	printf(ORANGE "                compressed bits: \t%lu\n", data.nbits_cmp);
	printf(ORANGE "              decompressed bits: \t%lu\n", data.nbits_dcmp);
	printf(ORANGE "             decompression time: \t%f s\n", data.time);
	printf(BLUE "------------------------------------------------------------------\n\n");
	printf("                      Data decompressed: \n");
	printf("                     -------------------- \n");
	print_strings(data.str);
	printf(BLUE "\n\n-------------------- " ORANGE "compression rate: %.2f%%" BLUE " --------------------\n\n",
			((double)data.nbits_cmp / (double)data.nbits_dcmp * (double)100));
	printf(RESET);
	free(data.str);
}
