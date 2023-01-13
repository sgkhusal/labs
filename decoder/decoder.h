/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decoder.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:34:32 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/13 15:42:55 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DECODER_H
# define DECODER_H

# include "huffman.h"
# include "utils.h"

int	decoder(int nbits, char *bits);

#endif
