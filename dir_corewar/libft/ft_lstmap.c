/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 16:58:07 by kgricour          #+#    #+#             */
/*   Updated: 2017/11/20 19:50:47 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *tmp;

	if (!(new = ft_lstnew((*f)(lst)->content, (*f)(lst)->content_size)))
		return (NULL);
	tmp = new;
	lst = lst->next;
	while (lst)
	{
		if (!(new->next = ft_lstnew((*f)(lst)->content,
			(*f)(lst)->content_size)))
			return (NULL);
		lst = lst->next;
		new = new->next;
	}
	return (tmp);
}
