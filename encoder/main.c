/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:25:28 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/10 11:58:01 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "encoder.h"

/* Encoder:
	open file
	read file
	create structure
	1. Count how many times each character is used - structure char and frequency - OK
	2. Order them in a list from the most used to the least used
	3. Create the Huffman Tree:
	- Put the 2 least used characters in the bottom branches and sum their frequencies into the top branch
	- Add the node sum back to the list, in the right order
	- Repeat the process until you have only one character on the list
	4. Create the encoding/translation table according with the Huffman Tree
	5. Encode the text using the table  ***bitwise?***
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
	int	*freq;

	freq = huffman_frequency("Hello world");
	free(freq);
	return (0);
}
