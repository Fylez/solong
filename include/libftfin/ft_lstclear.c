/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:43:41 by marvin            #+#    #+#             */
/*   Updated: 2023/05/15 10:43:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*todel;

	if (!*lst || !del)
		return ;
	while (*lst)
	{	
		todel = *lst;
		*lst = (*lst)-> next;
		ft_lstdelone(todel,*del);
	}
	todel = NULL;
}
