/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:38:26 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/12 19:25:19 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"

int	main(int argc, char *argv[])
{
	bool	print;

	print = false;
	if (argc != 1 && strcmp(argv[1], "p") == 0)
		print = true;
	frequency_tests();
	huffman_lst_tests();
	huffman_tree_tests();
	dictionary_tests();
	encode_tests();
	compress_tests();
	decompress_tests();
	decode_tests(print);
	return (0);
}
