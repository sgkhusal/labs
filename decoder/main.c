/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:41:30 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/14 17:31:25 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "decoder.h"

int	main(void)
{
	t_data	data;

	printf("\ndecoder initialized...\n");
	check_if_must_stop();
	data = decompress();
	send_nbits_cmp(data.nbits_cmp);
	send_nbits_dcmp(data.nbits_dcmp);
	send_time(data.time);
	send_str(data.str);
	move_on();
	return (0);
}
