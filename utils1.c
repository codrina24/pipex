/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coholbur <coholbur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:33:52 by coholbur          #+#    #+#             */
/*   Updated: 2025/02/24 12:49:20 by coholbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "pipex.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	if (split == NULL)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	create_pipe(int *fd)
{
	if (pipe(fd) == -1)
	{
		perror("pipe creation failed");
		exit(1);
	}
}

void	my_error(void)
{
	char	*str;

	str = "Error Occured!:\n";
	write(2, str, ft_strlen(str));
	exit(EXIT_FAILURE);
}

void	fork_error(void)
{
	perror("Fork error");
	exit(EXIT_FAILURE);
}

void	my_perror(char **cmd, char *path)
{
	perror(cmd[0]);
	free(path);
	free_split(cmd);
	exit(EXIT_FAILURE);
}
