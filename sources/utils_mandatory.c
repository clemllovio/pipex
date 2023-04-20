/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mandatory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cllovio <cllovio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:26:12 by cllovio           #+#    #+#             */
/*   Updated: 2023/04/20 10:34:20 by cllovio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_structure(t_pipex *pipex)
{
	pipex->path = NULL;
	pipex->cmd = NULL;
	pipex->infile_fd = 0;
	pipex->outfile_fd = 0;
	pipex->check_infile = 0;
	pipex->check_outfile = 0;
	pipex->end[0] = 0;
	pipex->end[1] = 0;
	pipex->check_error = -1;
}
