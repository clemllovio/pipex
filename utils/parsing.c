/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cllovio <cllovio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:31:58 by cllovio           #+#    #+#             */
/*   Updated: 2023/04/20 11:13:18 by cllovio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	check_files(t_pipex *pipex, char *infile, char *outfile);
static int	get_path(char **env, t_pipex *pipex);

int	parsing(t_pipex *pipex, char *infile, char *outfile, char **env)
{
	check_files(pipex, infile, outfile);
	if (get_path(env, pipex) == 1)
		return (1);
	return (0);
}

static void	check_files(t_pipex *pipex, char *infile, char *outfile)
{
	pipex->infile_fd = open(infile, O_RDONLY);
	if (pipex->infile_fd < 0)
	{
		pipex->check_infile = 1;
		perror(infile);
	}
	pipex->outfile_fd = open(outfile, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (pipex->outfile_fd < 0)
	{
		pipex->check_outfile = 1;
		perror(outfile);
	}
}

static int	get_path(char **env, t_pipex *pipex)
{
	int		i;
	char	*env_path;

	i = 0;
	env_path = NULL;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			env_path = env[i];
			break ;
		}
		i++;
	}
	env_path += 5;
	pipex->path = ft_split(env_path, ':');
	if (!(pipex->path))
		return (print_error(MALLOC_FAIL), 1);
	return (0);
}

char	*get_cmd(t_pipex *pipex, char *cmd)
{
	int		i;
	char	*path_w_cmd;
	char	*path_access;

	i = 0;
	if (cmd[0] == '.' && cmd[1] == '/')
		return (print_error(WRONG_FILE), NULL);
	if (cmd && access(cmd, X_OK) == 0)
		return (cmd);
	while (pipex->path[i])
	{
		path_access = ft_strjoin(pipex->path[i], "/");
		if (!(pipex->path[i]))
			return (print_error(MALLOC_FAIL), NULL);
		path_w_cmd = ft_strjoin(path_access, cmd);
		free(path_access);
		if (!(path_w_cmd))
			return (print_error(MALLOC_FAIL), NULL);
		if (access(path_w_cmd, F_OK | X_OK) == 0)
			return (path_w_cmd);
		free(path_w_cmd);
		i++;
	}
	pipex->check_error = 0;
	return (NULL);
}
