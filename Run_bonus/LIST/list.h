/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:01:21 by nherimam          #+#    #+#             */
/*   Updated: 2024/04/09 11:01:25 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include "../LIBFT/libft.h"
# include "../PRINTF/ft_printf.h"

void	ft_lstprintf(t_list *lst);
t_list	*ft_lstnew(int content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstfirst(t_list *lst);
t_list	*ft_lstfirst(t_list *lst);
t_list	*ft_delfirst(t_list *lst);
t_list	*ft_dellast(t_list *lst);

#endif
