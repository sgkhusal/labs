/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encoder.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:25:54 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/14 23:13:41 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENCODER_H
# define ENCODER_H

# include "huffman.h"
# include "shared_memory.h"
# include "utils.h"

# include <unistd.h>
# include <fcntl.h>

unsigned char	*get_text(char **strs);

char			*encode(unsigned char *text, unsigned int *freq);
void			compress(unsigned char *text);

void			send_freq(unsigned int *freq);
void			send_nbits(size_t nbits);
void			send_bits(unsigned char *bits);

void			receive_data(void);
void			wait_decoder(void);

void			init_decoder(void);
void			stop_decoder(bool yes);

#endif
