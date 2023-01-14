/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:27:45 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/13 23:14:23 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	malloc_error(const char *str)
{
	dprintf(2, "Malloc error at %s\n", str);
	exit(1);
}

void	shared_memory_error(const char *str)
{
	dprintf(2, "Shared memory error at %s\n", str);
	exit(2);
}
