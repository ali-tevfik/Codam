/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstsize.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <adoner@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/14 18:12:14 by adoner        #+#    #+#                 */
/*   Updated: 2020/11/14 19:15:13 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int i;

	i = 0;
	while (lst != 0)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
