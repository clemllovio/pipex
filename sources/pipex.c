/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cllovio <cllovio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:22:00 by cllovio           #+#    #+#             */
/*   Updated: 2023/04/20 11:13:57 by cllovio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child_process_1(t_pipex *pipex, char **av, char **env);
static void	child_process_2(t_pipex *pipex, char **av, char **env);
static void	pipex_function(char **av, t_pipex *pipex, char **env);

static void	child_process_1(t_pipex *pipex, char **av, char **env)
{
	pipex->check_error = -1;
	dup_fd(pipex->infile_fd, pipex->end[1], pipex);
	execute_cmd(pipex, av[2], env);
}

static void	child_process_2(t_pipex *pipex, char **av, char **env)
{
	pipex->check_error = -1;
	dup_fd(pipex->end[0], pipex->outfile_fd, pipex);
	execute_cmd(pipex, av[3], env);
}

static	void	pipex_function(char **av, t_pipex *pipex, char **env)
{
	if (pipe(pipex->end) == -1)
		error_close(pipex);
	pipex->child_1 = fork();
	if (pipex->child_1 < 0)
		error_close(pipex);
	if (pipex->child_1 == 0)
		child_process_1(pipex, av, env);
	pipex->child_2 = fork();
	if (pipex->child_2 < 0)
		error_close(pipex);
	if (pipex->child_2 == 0)
		child_process_2(pipex, av, env);
}

int	main(int ac, char **av, char **env)
{
	t_pipex	pipex;

	init_structure(&pipex);
	if (ac == 5)
	{
		if (parsing(&pipex, av[1], av[4], env) == 1)
			return (1);
		pipex_function(av, &pipex, env);
		close_fd(&pipex);
		waitpid(pipex.child_1, NULL, 0);
		waitpid(pipex.child_2, NULL, 0);
		ft_free_tab(pipex.path);
	}
	else
		return (ft_putstr_fd(RED"Wrong number of argument\n"END, 2), 1);
	return (0);
}
