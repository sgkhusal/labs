/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decode.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 22:07:19 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/12 02:11:43 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "huffman.h"

static unsigned char	*decode_for_only_one_node(unsigned char c, char *str_bit)
{
	char		*str;
	char		tmp[2];
	int			i;

	i = 0;
	tmp[0] = c;
	tmp[1] = '\0';
	str = (char *)calloc(strlen(str_bit) + 1, sizeof(char));
	if (!str)
		malloc_error("decode_for_only_one_node");
	while (str_bit[i])
	{
		strcat(str, tmp);
		i++;
	}
	return((unsigned char *)str);
}


unsigned char	*decode(t_huffman *tree, char *str_bit)
{
	t_huffman	*aux;
	char		*str;
	char		tmp[2];
	int			i;

	i = 0;
	if (tree == NULL)
		return ((unsigned char *)calloc(1, sizeof(char)));
	if (tree_height(tree) == 0)
		return (decode_for_only_one_node(tree->c, str_bit));
	aux = tree;
	tmp[1] = '\0';
	str = (char *)calloc(strlen(str_bit) + 1, sizeof(char));
	if (!str)
		malloc_error("decode function");
	while (str_bit[i])
	{
		if (str_bit[i] == '0')
			aux = aux->left;
		else
			aux = aux->right;
		if (aux->left == NULL && aux->right == NULL)
		{
			tmp[0] = aux->c;
			strcat(str, tmp);
			aux = tree;
		}
		i++;
	}
	return ((unsigned char *)str);
}
