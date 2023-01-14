/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmpanalyzer.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:53:43 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/14 16:53:29 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANALYSIS_H
# define ANALYSIS_H

# include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

# include "utils.h"

# define FORK_ERROR -1
# define INTERRUPT 128

int	execute_encoder(int nstrs, char *strs[]);
int	execute_decoder(void);
int	wait_for_child(int child_pid);

#endif
