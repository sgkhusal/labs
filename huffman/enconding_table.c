/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enconding_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:49:04 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/11 16:04:59 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "huffman.h"

static char	**create_enconding_table(int columns)
{
	char	**d;
	int		i;

	d = (char **)malloc(sizeof(char *) * ASCII_SIZE);
	if (!d)
		malloc_error("create_enconding_table");
	i = 0;
	while (i < ASCII_SIZE)
	{
		d[i] = (char *)calloc(columns, sizeof(char));
		if (!d[i])
			malloc_error("create_enconding_table - line allocation");
		i++;
	}
	return (d);
}

static void	fill_enconding_table(char **enconding_table, t_huffman *branch, int columns,
							char *bits)
{
	char	left[columns];
	char	right[columns];

	if (branch->left == NULL && branch->right == NULL)
		strcpy(enconding_table[branch->c], bits);
	else
	{
		strcat(strcpy(left, bits), "0");
		fill_enconding_table(enconding_table, branch->left, columns, left);
		strcat(strcpy(right, bits), "1");
		fill_enconding_table(enconding_table, branch->right, columns, right);
	}
}

char	**enconding_table(t_huffman *tree)
{
	char	**d;
	char	*bits;
	int		columns;

	columns = tree_height(tree) + 1;
	d = create_enconding_table(columns);
	bits = (char *)calloc(columns, sizeof(char));
	fill_enconding_table(d, tree, columns, bits);
	free(bits);
	return(d);
}

void	free_enconding_table(char **d)
{
	int	i;

	i = 0;
	while (i < ASCII_SIZE)
	{
		free(d[i]);
		i++;
	}
	free(d);
}
