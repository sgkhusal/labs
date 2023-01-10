/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:25:28 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/10 14:52:13 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "encoder.h"

/* Encoder:
	open file
	read file
	apply huffman coding
	6. Send the encoded text to the shared memory
	7. Read the info from the decoder and display it
	close file
	*/

/* Decoder:
	open file
	read file
	1. Aplly the translation table */

int	main(void)
{
	huffman_coding();
	return (0);
}
