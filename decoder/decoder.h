/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decoder.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:34:32 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/14 09:43:40 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DECODER_H
# define DECODER_H

# include "huffman.h"
# include "utils.h"
# include "shared_memory.h"
# include <sys/time.h>

t_data			decompress(void);
unsigned char	*decode(char *str_bits, unsigned int *freq);

long long		time_now(void);
long long		get_delta_time(long long start);

unsigned int	*get_freq(void);
size_t			get_nbits(void);
char			*get_bits(void);

#endif
