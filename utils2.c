/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coholbur <coholbur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:50:03 by coholbur          #+#    #+#             */
/*   Updated: 2025/02/24 13:04:07 by coholbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "pipex.h"

void	ft_error(char *command)
{
	ft_putstr_fd("bash: ", 2);
	ft_putstr_fd(command, 2);
	ft_putstr_fd(": Permission denied\n", 2);
}

void	ft_error_command_notfound(char **args)
{
	char	*str;

	str = "Error : command not found in PATH\n";
	write(2, str, ft_strlen(str));
	free_split(args);
	exit(EXIT_FAILURE);
}

void	error_command_notfound(char **args)
{
	char	*str;

	str = "Error : command not found in PATH\n";
	write(2, str, ft_strlen(str));
	free_split(args);
	exit(EXIT_FAILURE);
}

void	permission_error(char *command)
{
	ft_putstr_fd("bash: ", 2);
	ft_putstr_fd(command, 2);
	ft_putstr_fd(": Permission denied\n", 2);
}
