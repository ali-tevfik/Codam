/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_back.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <adoner@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/15 11:19:02 by adoner        #+#    #+#                 */
/*   Updated: 2020/11/23 11:57:43 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *oldlst;

	if (!new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	oldlst = *lst;
	while (oldlst->next != NULL)
		oldlst = oldlst->next;
	oldlst->next = new;
}
