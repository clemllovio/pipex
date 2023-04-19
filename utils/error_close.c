/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_close.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cllovio <cllovio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 09:28:54 by cllovio           #+#    #+#             */
/*   Updated: 2023/04/19 13:03:50 by cllovio          ###   ########.fr       */
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

void	error_close(t_pipex *pipex)
{
	if (pipex->check_infile == 0 && pipex->check_outfile == 0)
		perror(RED"Error"END);
	else
		pipex->check_infile = 0;
	close_fd(pipex);
	if (pipex->path)
		ft_free_tab(pipex->path);
	exit(errno);
}
