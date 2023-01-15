/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:50:49 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/15 02:11:06 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	header(void)
{
	printf("\n\n\n" BLUE);
	printf(" ██████ ███    ███ ██████   █████  ███    ██  █████  ██      ██    ██ ███████ ███████ ██████  \n");
	printf("██      ████  ████ ██   ██ ██   ██ ████   ██ ██   ██ ██       ██  ██     ███  ██      ██   ██ \n");
	printf("██      ██ ████ ██ ██████  ███████ ██ ██  ██ ███████ ██        ████     ███   █████   ██████  \n");
	printf("██      ██  ██  ██ ██      ██   ██ ██  ██ ██ ██   ██ ██         ██     ███    ██      ██   ██ \n");
	printf(" ██████ ██      ██ ██      ██   ██ ██   ████ ██   ██ ███████    ██    ███████ ███████ ██   ██ \n");
	printf("                                                                                              \n");
	printf("\n" RESET);
}

void	cat(void)
{
	printf("\n" YELLOW);
	printf("                            /\\_______/\\\n");
	printf("                           /           \\\n");
	printf("                          /   " EYES "<0   0>" YELLOW "   \\\n");
	printf("                         (    " WHISKERS "=  " NOSE "Y  " WHISKERS "=    " YELLOW ")\n");
	printf("                          \\             /\n");
	printf("                          /    ~~~~~    \\\n");
	printf("                         /               \\    (\\\n");
	printf("                        /        0        \\    \\\\\n");
	printf("                       /  |      0      |  \\    ))\n");
	printf("                      /   |   |  0  |   |   \\  //\n");
	printf("                     /    |   |     |   |    \\((\n");
	printf("                    (     |   |     |   |     )\n");
	printf("                     \\    |   |     |   |    /\n");
	printf("                      \\   |   |     |   |   /\n");
	printf("                       \\_(_;_;_)___(_;_;_)_/\n");
	printf("\n");
	printf(PURPLE "                        by Sheela G. Khusal\n\n");
	printf("\n" RESET);
}
