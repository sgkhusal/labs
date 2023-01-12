/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:38:26 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/12 01:44:58 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_tests.h"
#include <locale.h>

int	main(void)
{
	setlocale(LC_ALL, "Portuguese");
	frequency_tests();
	huffman_lst_tests();
	huffman_tree_tests();
	dictionary_tests();
	encode_tests();
	decode_tests();
	return (0);
}
