/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encoder.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:25:54 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/14 11:58:53 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENCODER_H
# define ENCODER_H

# include "huffman.h"
# include "shared_memory.h"
# include "utils.h"

# include <unistd.h>
# include <fcntl.h>

char			*encode(unsigned char *text, unsigned int *freq);
void			compress(unsigned char *text);

void			send_freq(unsigned int *freq);
void			send_nbits(size_t nbits);
void			send_bits(unsigned char *bits);

size_t			get_nbits_cmp(void);
size_t			get_nbits_dcmp(void);
double			get_time(void);
unsigned char	*get_str(void);

#endif
