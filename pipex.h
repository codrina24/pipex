/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coholbur <coholbur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:40:44 by coholbur          #+#    #+#             */
/*   Updated: 2025/02/24 13:02:54 by coholbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <time.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>

char	*get_path(char **env);
char	**split_path(char *path);
char	*build_complete_path(const char *dir, const char *command);
char	*find_command_in_path(char *command, char **env);
void	ft_execute(char *command, char **env);
void	ft_error_command_notfound(char **args);
void	my_perror(char **cmd, char *path);
void	create_pipe(int *fd);
void	fork_error(void);
void	free_split(char **split);
void	my_error(void);
void	child_process(char **argv, char **env, int *fd);
void	second_child_process(char **argv, char **env, int *fd);
void	parent_process(int *fd, pid_t child1, pid_t child2);
void	ft_error(char *command);

#endif
