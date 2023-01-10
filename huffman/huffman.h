/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   huffman.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 00:47:33 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/10 14:50:38 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUFFMAN_H
# define HUFFMAN_H

# include "utils.h"

# define ASCII_SIZE 256

typedef struct s_huffman
{
	int					weight;
	char				c;
	struct s_huffman	*next;
	struct s_huffman	*left;
	struct s_huffman	*right;
}				t_huffman;

void		huffman_coding(void);

int			*huffman_frequency(char *str);
int			*init_frequency(void);

t_huffman	*create_huffman_lst(int *freq);
t_huffman	*create_huffman_node(int freq, char c);
void		huffman_lstadd(t_huffman **head, t_huffman *node);
void		huffman_lstsort(t_huffman *head);
void		free_huffman_lst(t_huffman **head);

#endif
