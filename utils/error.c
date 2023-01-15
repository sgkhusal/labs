/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:27:45 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/15 01:51:47 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	malloc_error(const char *str)
{
	dprintf(2, RED "\nMalloc error at: %s\n\n" RESET, str);
	exit(1);
}

void	shared_memory_error(const char *str)
{
	dprintf(2, RED "\nShared memory error at: %s\n\n" RESET, str);
	exit(2);
}
