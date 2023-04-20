/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_close.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cllovio <cllovio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 09:28:54 by cllovio           #+#    #+#             */
/*   Updated: 2023/04/20 11:14:39 by cllovio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_fd(t_pipex *pipex)
{
	if (pipex->end[0] > 0)
		close(pipex->end[0]);
	if (pipex->end[1] > 0)
		close(pipex->end[1]);
	if (pipex->infile_fd > 0)
		close(pipex->infile_fd);
	if (pipex->outfile_fd > 0)
		close(pipex->outfile_fd);
}

void	print_error(int check_error)
{
	if (check_error == CMD_NOT_FOUND)
		write(2, "\033[1;31mError\033[0m: Command not found\n", 42);
	else if (check_error == MALLOC_FAIL)
		write(2, "\033[1;31mError\033[0m: A malloc failed\n", 39);
	else if (check_error == WRONG_FILE)
		write(2, "\033[1;31mError\033[0m: No such file or directory\n", 49);
}

void	error_close(t_pipex *pipex)
{
	if (pipex->check_infile == 0 && pipex->check_outfile == 0)
		perror(RED"Error"END);
	else
		pipex->check_infile = 0;
	close_fd(pipex);
	if (pipex->path != NULL)
		ft_free_tab(pipex->path);
	exit(errno);
}
