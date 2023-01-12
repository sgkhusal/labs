/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:49:04 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/12 01:54:14 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "huffman.h"

static char	**create_dictionary(int columns)
{
	char	**d;
	int		i;

	d = (char **)malloc(sizeof(char *) * ASCII_SIZE);
	if (!d)
		malloc_error("create_dictionary");
	i = 0;
	while (i < ASCII_SIZE)
	{
		d[i] = (char *)calloc(columns, sizeof(char));
		if (!d[i])
			malloc_error("create_dictionary - line allocation");
		i++;
	}
	return (d);
}

static void	fill_dictionary(char **dictionary, t_huffman *branch, int columns,
							char *bits)
{
	char	left[columns];
	char	right[columns];

	if (branch->left == NULL && branch->right == NULL)
		strcpy(dictionary[branch->c], bits);
	else
	{
		strcat(strcpy(left, bits), "0");
		fill_dictionary(dictionary, branch->left, columns, left);
		strcat(strcpy(right, bits), "1");
		fill_dictionary(dictionary, branch->right, columns, right);
	}
}

static char	**dictionary_for_only_one_node(t_huffman *tree) // pode ser que isso bugue
{
	char	**d;
	char	*bits;

	d = create_dictionary(2);
	bits = (char *)calloc(2, sizeof(char));
	bits[0] = '0';
	fill_dictionary(d, tree, 2, bits);
	free(bits);
	return(d);
}

char	**dictionary(t_huffman *tree)
{
	char	**d;
	char	*bits;
	int		columns;

	if (tree == NULL)
		return (NULL);
	columns = tree_height(tree) + 1;
	if (columns == 1)
		return (dictionary_for_only_one_node(tree));
	d = create_dictionary(columns);
	bits = (char *)calloc(columns, sizeof(char));
	fill_dictionary(d, tree, columns, bits);
	free(bits);
	return(d);
}

void	free_dictionary(char **d)
{
	int	i;

	if (d == NULL)
		return ;
	i = 0;
	while (i < ASCII_SIZE)
	{
		free(d[i]);
		i++;
	}
	free(d);
}
