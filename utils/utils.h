/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:28:21 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/15 01:47:26 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdio.h>
# include <stdlib.h>

# define ORANGE	"\033[0;38;5;166m"
# define BLUE	"\033[38;5;75m"
# define GREEN	"\033[1;32m"
# define RED	"\033[38;5;196m"
# define YELLOW	"\033[1;33m"
# define GREY	"\033[38;5;244m"
# define PURPLE	"\033[38;5;200m"
# define EYES	"\033[1;36m"
# define WHISKERS	"\033[1;36m"
# define NOSE	"\033[1;35m"
# define RESET	"\033[0m"

void	malloc_error(const char *str);
void	shared_memory_error(const char *str);

#endif
