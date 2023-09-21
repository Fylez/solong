/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:43:18 by marvin            #+#    #+#             */
/*   Updated: 2023/05/15 10:43:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include"string.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;

	result = 0;
	if (!lst || !del || !f)
		return (NULL);
	while (lst)
	{	
		ft_lstadd_back(&result, ft_lstnew((*f)(lst->content)));
		lst = lst -> next;
	}
	return (result);
}
