/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:38:26 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/11 16:46:01 by sguilher         ###   ########.fr       */
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
	enconding_table_tests();
	return (0);
}
