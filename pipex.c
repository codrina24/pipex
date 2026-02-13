/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coholbur <coholbur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:32:29 by coholbur          #+#    #+#             */
/*   Updated: 2025/02/24 12:22:42 by coholbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "pipex.h"

void	child_process(char **argv, char **env, int *fd)
{
	int	infile;

	infile = open(argv[1], O_RDONLY, 0777);
	if (infile == -1)
	{
		perror(argv[1]);
		exit(EXIT_FAILURE);
	}
	close(fd[0]);
	dup2(infile, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	close(infile);
	ft_execute(argv[2], env);
	exit(EXIT_SUCCESS);
}

void	second_child_process(char **argv, char **env, int *fd)
{
	int	outfile;

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile == -1)
	{
		perror(argv[4]);
		exit(EXIT_FAILURE);
	}
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	dup2(outfile, STDOUT_FILENO);
	close(outfile);
	ft_execute(argv[3], env);
	exit(EXIT_SUCCESS);
}

void	parent_process(int *fd, pid_t child1, pid_t child2)
{
	close(fd[0]);
	close(fd[1]);
	waitpid(child1, NULL, 0);
	waitpid(child2, NULL, 0);
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
}

int	main(int argc, char **argv, char **env)
{
	int		fd[2];
	pid_t	child1;
	pid_t	child2;

	if (argc != 5)
	{
		ft_putstr_fd("Follow this: ./pipex <infile> <cmd1> <cmd2> <file2>\n", 1);
		return (EXIT_FAILURE);
	}
	create_pipe(fd);
	child1 = fork();
	if (child1 < 0)
		fork_error();
	if (child1 == 0)
		child_process(argv, env, fd);
	child2 = fork();
	if (child2 < 0)
		fork_error();
	if (child2 == 0)
		second_child_process(argv, env, fd);
	parent_process(fd, child1, child2);
	return (EXIT_SUCCESS);
}
