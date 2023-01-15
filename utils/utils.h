/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:28:21 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/15 03:18:45 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdio.h>
# include <stdlib.h>

# define ORANGE	"\033[0;38;5;166m"
# define BLUE	"\033[38;5;75m"
# define GREEN	"\033[38;5;83m"
# define RED	"\033[38;2;222;56;43m"
# define YELLOW	"\033[1;33m"
# define LIGHT_BLUE "\033[0;36m"
# define GREEN2 "\033[38;2;34;183;235m"
# define PINK "\033[38;5;212m"
# define PURPLE	"\033[38;5;200m"
# define GREY	"\033[38;5;244m"
# define EYES	"\033[1;36m"
# define WHISKERS	"\033[1;36m"
# define NOSE	"\033[1;35m"
# define RESET	"\033[0m"
# define END "\033[0m"

# define MAX_L_INT 9223372036854775807

void	malloc_error(const char *str);
void	shared_memory_error(const char *str);

#endif
