/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cllovio <cllovio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 09:15:45 by cllovio           #+#    #+#             */
/*   Updated: 2023/04/17 10:33:48 by cllovio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_cmd(t_pipex *pipex, char *cmd, char **env)
{
	char	**cmd_tab;
	char	*path;

	close_fd(pipex);
	cmd_tab = ft_split(cmd, ' ');
	if (cmd_tab == NULL)
		error_close(pipex);
	path = get_cmd(pipex, cmd_tab[0]);
	if (path == NULL)
	{
		write(2, "\033[1;31mError\033[0m: Command not found\n", 42);
		close_fd(pipex);
		ft_free_tab(cmd_tab);
		if (pipex->path)
			ft_free_tab(pipex->path);
		exit(1);
	}
	ft_free_tab(pipex->path);
	if (execve(path, cmd_tab, env) == -1)
		error_close(pipex);
}
