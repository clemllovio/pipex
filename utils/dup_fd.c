/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_fd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cllovio <cllovio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 13:53:03 by cllovio           #+#    #+#             */
/*   Updated: 2023/04/20 09:25:20 by cllovio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	dup_fd(int infile_to_be, int outfile_to_be, t_pipex *pipex)
{
	if (dup2(infile_to_be, STDIN_FILENO) == -1)
		error_close(pipex);
	if (dup2(outfile_to_be, STDOUT_FILENO) == -1)
		error_close(pipex);
}
