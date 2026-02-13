/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coholbur <coholbur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:52:05 by coholbur          #+#    #+#             */
/*   Updated: 2025/02/24 13:02:01 by coholbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "pipex.h"

char	*get_path(char **env)
{
	int		i;
	char	*path;

	i = 0;
	path = NULL;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			path = ft_strdup(env[i] + 5);
			if (!path)
			{
				ft_putstr_fd("Failed to duplicate PATH\n", STDERR_FILENO);
				return (NULL);
			}
			break ;
		}
		i++;
	}
	if (!path)
	{
		ft_putstr_fd("PATH not found in env\n", STDERR_FILENO);
		return (NULL);
	}
	return (path);
}

char	**split_path(char *path)
{
	char	**splitted_path;

	splitted_path = ft_split(path, ':');
	if (!splitted_path)
	{
		ft_putstr_fd("Failed to split PATH\n", STDERR_FILENO);
		return (NULL);
	}
	return (splitted_path);
}

char	*build_complete_path(const char *dir, const char *command)
{
	char	*complete_path;
	int		len;

	len = ft_strlen(dir) + ft_strlen(command);
	complete_path = (char *)malloc(sizeof(char) * (len + 2));
	if (!complete_path)
		return (NULL);
	ft_strcpy(complete_path, dir);
	ft_strcat(complete_path, "/");
	ft_strcat(complete_path, command);
	return (complete_path);
}

char	*find_command_in_path(char *command, char **env)
{
	char	*path;
	char	**path_dir;
	char	*complete_path;
	int		i;

	i = 0;
	path = get_path(env);
	if (!path)
		return (NULL);
	path_dir = split_path(path);
	if (!path_dir)
		return (free(path), NULL);
	while (path_dir[i])
	{
		complete_path = build_complete_path(path_dir[i], command);
		if (!complete_path)
			return (free(path_dir), free(path), NULL);
		if (access(complete_path, X_OK) == 0)
			return (free(path), free(path_dir), complete_path);
		if (access(complete_path, F_OK) == 0)
			ft_error(command);
		free(complete_path);
		i++;
	}
	return (free(path), free(path_dir), NULL);
}

void	ft_execute(char *command, char **env)
{
	char	**args;
	char	*path;

	args = ft_split(command, ' ');
	if (!args)
		my_error();
	if (args[0][0] == '/' || (args[0][0] == '.' && args[0][1] == '/'))
	{
		if (execve(args[0], args, env) == -1)
			my_perror(args, NULL);
	}
	else
	{
		path = find_command_in_path(args[0], env);
		if (!path)
			ft_error_command_notfound(args);
		if (execve(path, args, env) == -1)
			my_perror(args, path);
		free(path);
	}
	free_split(args);
}
