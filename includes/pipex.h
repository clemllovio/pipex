/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cllovio <cllovio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:25:43 by cllovio           #+#    #+#             */
/*   Updated: 2023/04/19 13:00:54 by cllovio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/* ---- LIBRAIRIE ----*/
# include "libft.h"
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>
# include <errno.h>

# define END "\033[0m"
# define RED "\033[1;31m"

typedef struct s_pipex{
	char	**path;
	int		infile_fd;
	int		outfile_fd;
	int		end[2];
	char	*cmd;
	pid_t	child_1;
	pid_t	child_2;
	int		check_infile;
	int		check_outfile;
}	t_pipex;

/* ---- SOURCES ----*/
void	init_structure(t_pipex *pipex);

/* ---- UTILS ----*/
void	dup_fd(int infile_to_be, int outfile_to_be, t_pipex *pipex);
void	close_fd(t_pipex *pipex);
void	error_close(t_pipex *pipex);
void	execute_cmd(t_pipex *pipex, char *cmd, char **env);
void	*ft_free_tab(char **tab);
int		parsing(t_pipex *pipex, char *infile, char *outfile, char **env);
char	*get_cmd(t_pipex *pipex, char *cmd);

#endif