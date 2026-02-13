/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coholbur <coholbur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:00:20 by coholbur          #+#    #+#             */
/*   Updated: 2024/12/03 14:15:38 by coholbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*dernier;

	if (lst == 0)
		return (lst);
	while (lst)
	{
		dernier = lst;
		lst = lst->next;
	}
	return (dernier);
}
/*
int	main(void)
{
t_list	*src;

src = (t_list *)malloc(sizeof(t_list));
src->content = (char *)"abc";
src->next = NULL;
printf("%s\n", (char *)ft_lstlast(src));
return (0);
}
*/