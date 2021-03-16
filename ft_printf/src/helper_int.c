/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helper_int.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: catalina <catalina@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/03 16:11:18 by catalina      #+#    #+#                 */
/*   Updated: 2021/03/11 21:04:09 by catalina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*fill_space_end(char *tmp, int len_width)
{
	char	*new_tmp;
	int		i;
	char	*fill_space;

	i = 0;
	fill_space = malloc(sizeof(char) * (len_width + 1));
	if (!fill_space)
	{
		free(tmp);
		return (NULL);
	}
	while (i < len_width)
	{
		fill_space[i] = ' ';
		i++;
	}
	fill_space[i] = '\0';
	new_tmp = ft_strjoin(tmp, fill_space);
	free(tmp);
	free(fill_space);
	if (!new_tmp)
		return (NULL);
	return (new_tmp);
}

char	*fill_zero_txt(char *bigtext, char *text, int len_prec, int i)
{
	int	x;

	if (!bigtext)
		return (NULL);
	x = 0;
	if (text[0] == '-')
	{
		bigtext[i] = '-';
		i++;
	}
	while (len_prec > x)
	{
		bigtext[i] = '0';
		i++;
		x++;
	}
	bigtext[i] = '\0';
	return (bigtext);
}

char	*join_zero_text(char *text, char *bigtext, int len_prec, t_info info)
{
	char	*tmp;

	if (!bigtext)
		return (NULL);
	if (text[0] == '-')
		tmp = ft_strjoin(bigtext, text + 1);
	else if (text[0] == '0' && len_prec < 1 && info.width != -1)
		tmp = ft_strjoin(bigtext, "");
	else
		tmp = ft_strjoin(bigtext, text);
	free(bigtext);
	return (tmp);
}

char	*create_malloc_0(t_info info, char *text, int len_prec, int len_width)
{
	char	*bigtext;

	if (info.mines == 0 && text[0] != '-')
		bigtext = malloc(sizeof(char) * (len_prec + len_width + 1));
	else
		bigtext = malloc(sizeof(char) * (len_prec + 2));
	return (bigtext);
}

char	*fill_zero_flags(int len_width, int len_prec, char *text, t_info info)
{
	char	*tmp;
	char	*bigtext;
	int		x;
	int		i;

	i = 0;
	x = 0;
	bigtext = create_malloc_0(info, text, len_prec, len_width);
	if (info.coma == 0 && info.width != -1 && info.mines == 0 && bigtext)
	{
		len_prec = len_width;
		len_width = 0;
	}
	while (len_width > x && info.mines == 0 && bigtext)
	{
		bigtext[i] = ' ';
		x++;
		i++;
	}
	bigtext = fill_zero_txt(bigtext, text, len_prec, i);
	tmp = join_zero_text(text, bigtext, len_prec, info);
	if (info.mines == 1 && tmp)
		tmp = fill_space_end(tmp, len_width);
	return (tmp);
}
