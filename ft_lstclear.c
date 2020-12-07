/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <adoner@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/15 12:42:57 by adoner        #+#    #+#                 */
/*   Updated: 2020/11/15 16:44:52 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *oldlst;

	if (*lst == NULL)
		return ;
	while (*lst != NULL)
	{
		oldlst = (*lst)->next;
		del((*lst)->content);
		free(*(lst));
		*lst = oldlst;
	}
}
