/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:41:30 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/15 02:42:22 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "decoder.h"

int	main(void)
{
	t_data	data;

	wait_encoder();
	printf(YELLOW "\ndecoder initialized...\n" RESET);
	check_if_must_stop();
	data = decompress();
	send_nbits_cmp(data.nbits_cmp);
	send_nbits_dcmp(data.nbits_dcmp);
	send_time(data.time);
	send_str(data.str);
	printf(YELLOW "\ndecoder ended...\n" RESET);
	move_on();
	free(data.str);
	return (0);
}
