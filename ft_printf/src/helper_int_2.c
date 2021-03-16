/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helper_int_2.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: catalina <catalina@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/27 16:44:55 by catalina      #+#    #+#                 */
/*   Updated: 2021/03/13 13:09:45 by catalina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*join_int(t_info info, char *text, char *bigtext, int len_width)
{
	char	*tmp;

	if (info.prec < 1 && text[0] == '0' && text[1] == '\0'
		&& info.coma == 1 && info.width > -1)
		tmp = ft_strdup(bigtext);
	else if (text[0] == '-')
		tmp = ft_strjoin(bigtext, (text + 1));
	else
		tmp = ft_strjoin(bigtext, text);
	if (info.mines != 0 && tmp)
		tmp = fill_space_end(tmp, len_width);
	free(bigtext);
	return (tmp);
}

char	*fill_int(int len_width, int len_prec, char *text, t_info info)
{
	char	*bigtext;
	int		i;
	char	*tmp;

	i = 0;
	if (len_width == -1 && len_prec == -1 && text[0] == '0')
		len_width = info.width;
	if (len_width < 0)
		len_width = 0;
	if (len_prec < 0)
		len_prec = 0;
	if (info.zero == 1)
		return (fill_zero_flags(len_width, len_prec, text, info));
	bigtext = create_malloc_0(info, text, len_prec, len_width);
	if (!bigtext)
		return (NULL);
	while (i < len_width && info.mines == 0)
	{
		bigtext[i] = ' ';
		i++;
	}
	bigtext = fill_zero_txt(bigtext, text, len_prec, i);
	tmp = join_int(info, text, bigtext, len_width);
	return (tmp);
}

int	find_len_width_int(int len_width, t_info info, char *text)
{
	if (info.width > info.prec)
		len_width = info.width;
	if (info.width > info.prec && info.prec > 0)
		len_width = info.width - info.prec;
	if (info.prec < info.text_len && text[0] != '0' && len_width > 0)
		len_width = len_width - (info.text_len - info.prec);
	else if (info.prec < info.text_len && text[0] != '0')
		len_width = info.width - info.text_len;
	if (info.prec == -1)
		len_width = info.width - info.text_len;
	if (text[0] == '-' && info.width >= 0)
		len_width -= 1;
	return (len_width);
}

int	write_txt(char *bigtext)
{
	int	bigtext_len;

	ft_putstr_fd(bigtext, 1);
	bigtext_len = ft_strlen(bigtext);
	free(bigtext);
	return (bigtext_len);
}

int	helper_find_zero_of_space(t_info info, char *text)
{
	char	*bigtext;
	int		len_width;
	int		len_prec;

	len_width = 0;
	len_prec = 0;
	info.text_len = ft_strlen(text);
	if (info.prec < 1 && text[0] == '0' && text[1] == '\0' && info.coma == 1)
		info.text_len = ft_strlen(text) - 1;
	if (text[0] == '-')
		info.text_len -= 1;
	if (text[1] == '\0' && text[0] == '0' && info.coma == 1
		&& info.prec < 1 && info.width == -1)
		return (0);
	if (info.prec > info.text_len)
		len_prec = info.prec - info.text_len;
	len_width = find_len_width_int(len_width, info, text);
	if (text[0] == '-' && info.width == -2)
		len_prec -= 1;
	bigtext = fill_int(len_width, len_prec, text, info);
	if (!bigtext)
		return (-1);
	return (write_txt(bigtext));
}
