/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_tests.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:37:27 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/10 11:42:26 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNIT_TESTS_H
# define UNIT_TESTS_H

# include <stdbool.h>
# include "huffman.h"

# define YELLOW "\033[0;33m"
# define GREY "\033[38;5;244m"
# define PURPLE "\033[1;35m"
# define BLUE "\033[1;34m"
# define LIGHT_BLUE "\033[0;36m"
# define GREEN "\033[38;5;83m"
# define GREEN2 "\033[38;2;34;183;235m"
# define RED "\033[38;2;222;56;43m"
# define PINK "\033[38;5;212m"
# define END "\033[0m"

void	frequency_tests(void);

#endif
