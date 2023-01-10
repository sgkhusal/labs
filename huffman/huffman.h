/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   huffman.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 00:47:33 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/10 11:58:24 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUFFMAN_H
# define HUFFMAN_H

# include <stdio.h>
# include <stdlib.h>

# define ASCII_SIZE 256

int	*huffman_frequency(char *str);
int	*init_frequency(void);

#endif
