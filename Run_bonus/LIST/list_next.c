/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_next.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 13:31:35 by nherimam          #+#    #+#             */
/*   Updated: 2024/04/06 13:31:37 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (lst[0] != NULL)
		ft_lstlast (lst[0])->next = new;
	else
		lst[0] = new;
}

t_list	*ft_dellast(t_list *lst)
{
	t_list	*tmp;
	t_list	*tmps;
	t_list	*list;

	if (!lst)
		return (NULL);
	list = NULL;
	while (lst->next != NULL)
	{
		tmp = ft_lstnew (lst->content);
		ft_lstadd_back (&list, tmp);
		tmps = lst->next;
		free (lst);
		lst = tmps;
	}
	free (lst);
	return (list);
}

t_list	*ft_delfirst(t_list *lst)
{
	t_list	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst->next;
	free (lst);
	lst = tmp;
	return (lst);
}
