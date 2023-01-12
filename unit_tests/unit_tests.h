/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_tests.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:37:27 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/11 22:36:22 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNIT_TESTS_H
# define UNIT_TESTS_H

# include <stdbool.h>
# include "huffman.h"

# define YELLOW "\033[0;33m"
# define GREY "\033[38;5;244m"
# define PURPLE "\033[1;35m"
# define BLUE "\033[1;34m"
# define LIGHT_BLUE "\033[0;36m"
# define GREEN "\033[38;5;83m"
# define GREEN2 "\033[38;2;34;183;235m"
# define RED "\033[38;2;222;56;43m"
# define PINK "\033[38;5;212m"
# define END "\033[0m"

# define TEST1 "Hello World"
# define TEST2 "Not for the first time, an argument had broken out over \
				breakfast at number four, Privet Drive. Mr Vernon Dursley \
				had been woken in early hours of the morning by a loud, \
				hooting noise from his nephew Harry's room."

void	frequency_tests(void);
void	huffman_lst_tests(void);
void	huffman_tree_tests(void);
void	dictionary_tests(void);
void	encode_tests(void);

// utils
int		check_zeros(unsigned int *result);
void	print_frequency(unsigned int *f);

#endif
