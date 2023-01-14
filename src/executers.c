/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:50:27 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/14 17:11:32 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmpanalyzer.h"

static char	**get_args(int nstrs, char *strs[])
{
	char **arr;

	arr = (char **)malloc((nstrs + 2) * sizeof(char *));
	if (!arr)
		malloc_error("cmpanalyzer: get_args\n");
	arr[0] = "encoder.bin";
	int i = 0;
	while (strs[i])
	{
		arr[i + 1] = strs[i];
		i++;
	}
	arr[nstrs + 1] = NULL;
	return (arr);
}

int	execute_encoder(int nstrs, char *strs[])
{
	int	child_pid;
	int	check;
	char **arr;

	arr = get_args(nstrs, strs);
	child_pid = fork();
	if (child_pid == 0) {

		check = execv("./encoder/encoder.bin", arr);
		if (check == -1)
			dprintf(2, "Error on encoder execution\n");
		exit(1);
	}
	free(arr);
	return (child_pid);
}

int	execute_decoder(void)
{
	int	child_pid;
	int	check;

	child_pid = fork();
	if (child_pid == 0) {
		check = execl("./decoder/decoder.bin", "decoder.bin", NULL);
		if (check == -1)
			dprintf(2, "Error on decoder execution\n");
		exit(1);
	}
	return (child_pid);
}

int	wait_for_child(int child_pid)
{
	int	status;

	if (child_pid == FORK_ERROR)
		return (EXIT_FAILURE);
	if (waitpid(child_pid, &status, 0) == -1)
		dprintf(2, "\nwaitpid error\n");
	if (WIFSIGNALED(status))
		return (INTERRUPT + WTERMSIG(status));
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (EXIT_FAILURE);
}
