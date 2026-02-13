/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coholbur <coholbur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:57:39 by coholbur          #+#    #+#             */
/*   Updated: 2024/12/03 14:16:03 by coholbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*src;

	src = (t_list *)malloc(sizeof(t_list));
	if (!src)
		return (NULL);
	src->content = content;
	src->next = NULL;
	return (src);
}
/*
int	main(void)
{
	char	srcc[] = "abc";
	t_list	*new;

	new = ft_lstnew(srcc);
	printf("%s\n", (char*)new->content);
	printf("%s\n", (char*)new->next);
	return (0);
}
 */