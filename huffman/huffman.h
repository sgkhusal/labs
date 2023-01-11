/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   huffman.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 00:47:33 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/11 01:05:35 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUFFMAN_H
# define HUFFMAN_H

# include "utils.h"
# include <string.h>

# define ASCII_SIZE 256

typedef struct s_huffman
{
	int					weight;
	unsigned char		c;
	struct s_huffman	*next;
	struct s_huffman	*left;
	struct s_huffman	*right;
}				t_huffman;

void			huffman_coding(void);

unsigned int	*huffman_frequency(unsigned char *str);
unsigned int	*init_frequency(void);

t_huffman		*create_huffman_lst(unsigned int *freq);
t_huffman		*create_huffman_node(unsigned int freq, unsigned char c);
void			huffman_lstadd_sort(t_huffman **head, t_huffman *node);
void			free_huffman_lst(t_huffman **head);
t_huffman		*create_huffman_tree(t_huffman **lst);
void			free_tree(t_huffman *tree);

int				tree_height(t_huffman *tree);
char			**dictionary(t_huffman *tree);
void			free_dictionary(char **d);

#endif
