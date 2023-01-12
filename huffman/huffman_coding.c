/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   huffman_coding.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:42:12 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/11 22:06:14 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "huffman.h"

/* Huffman coding:
	1. Count how many times each character is used - structure char and frequency - OK
	2. Order them in a list from the least used to the most used - OK
	3. Create the Huffman Tree: - OK!!
	- Put the 2 least used characters in the bottom branches and sum their frequencies into the top branch
	- Add the node sum back to the list, in the right order
	- Repeat the process until you have only one character on the list
	4. Create the encoding/translation table according with the Huffman Tree - OK
	5. Encode the text using the table  ***bitwise?***
	6. Send the encoded text to the shared memory
	7. Read the info from the decoder and display it
	close file
	*/

void	huffman_coding(void)
{
	unsigned int	*freq;
	t_huffman		*head;
	char			**d;
	char			*comp;

	freq = huffman_frequency((unsigned char *)"Hello world");
	head = create_huffman_lst(freq);
	free(freq);
	head = create_huffman_tree(&head);
	d = dictionary(head);
	comp = encode(d, (unsigned char *)"Hello world");
	printf("%s\n", comp);
	free_dictionary(d);
	free(comp);
	free_tree(head);
}
