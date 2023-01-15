/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_tests.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:37:27 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/15 02:21:30 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNIT_TESTS_H
# define UNIT_TESTS_H

# include <stdbool.h>
# include "huffman.h"

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
void	decode_tests(bool print);
void	compress_tests(void);
void	decompress_tests(void);

// utils
int		check_zeros(unsigned int *result);
void	print_frequency(unsigned int *f);

#endif
