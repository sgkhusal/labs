/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:41:30 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/14 11:51:28 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "decoder.h"

int	main(void)
{
	t_data	data;

	printf("Initializing decoder...\n");
	data = decompress();
	send_nbits_cmp(data.nbits_cmp);
	send_nbits_dcmp(data.nbits_dcmp);
	send_time(data.time);
	send_str(data.str);
	return (0);
}
