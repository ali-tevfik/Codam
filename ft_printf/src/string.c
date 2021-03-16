#include "ft_printf.h"

char	*emty_string(int len)
{
	int		i;
	char	*text;

	if (len < 0)
		len = 0;
	text = malloc(sizeof(text) * (len + 1));
	if (!text)
		return (text);
	i = 0;
	while (i < len)
	{
		text[i] = ' ';
		i++;
	}
	text[i] = '\0';
	return (text);
}

char	*find_tmp(t_info info, char *tmp, const char *text, char *new_text)
{
	char *ptr;

	if (info.prec <= 0)
		info.prec = info.text_len;
	ptr = ft_substr(text, 0, info.prec);
	if (!ptr)
		return (NULL);
	if (info.mines == 0)
		tmp = ft_strjoin(new_text, ptr);
	else
		tmp = ft_strjoin(ptr, new_text);
	free(ptr);
	return (tmp);
}

int	fill_string(int len_width, char *new_text, const char *text, t_info info)
{
	int		i;
	char	*tmp;
	int		len_tmp;

	i = 0;
	tmp = NULL;
	while (len_width > i)
	{
		new_text[i] = ' ';
		i++;
	}
	new_text[i] = '\0';
	if (info.coma == 1 && info.prec < 1 && info.width >= -1 && info.width < 1)
		tmp = ft_strdup(new_text);
	else if (info.width > -1 && info.coma == 1
		&& info.prec == -1 && info.prec_is_negative == 1)
		tmp = emty_string(info.width);
	else
		tmp = find_tmp(info, tmp, text, new_text);
	if (!tmp)
		return (-1);
	len_tmp = ft_strlen(tmp);
	ft_putstr_fd(tmp, 1);
	free(tmp);
	return (len_tmp);
}

int	find_len_width_str(t_info info, int len_width)
{
	if (info.width > info.text_len && info.prec != -1)
		len_width = info.width - info.prec;
	if (info.width > info.text_len && info.prec == -1 && info.coma == 0)
		len_width = info.width - info.text_len;
	if (info.coma == 1 && info.width != -1 && info.prec == -1)
		len_width = info.width;
	if (len_width == 0 && info.prec != -1)
		len_width = info.width - info.prec;
	if (len_width == 0 && info.prec == -1)
		len_width = info.width - info.text_len;
	if (info.prec > info.text_len && info.prec != -1)
		len_width = info.width - info.text_len;
	if (info.prec == -1)
		len_width = info.width - info.text_len;
	if (len_width < 0)
		len_width = 0;
	return (len_width);
}

int	parse_string(va_list data, t_info info)
{
	const char	*text;
	int			len_width;
	char		*new_text;
	int			len_tmp;

	text = va_arg(data, const char *);
	len_width = 0;
	if (info.prec < 1 && info.width < 1 && info.coma == 1
		&& text && info.prec_is_negative == 0)
		return (0);
	if (info.mines < 2 && info.width > -1 && info.coma == 1
		&& info.prec == -1 && info.prec_is_negative == 0)
		text = ft_strdup("");
	if (!text)
		text = ft_strdup("(null)");
	if (!text)
		return (-1);
	info.text_len = ft_strlen(text);
	len_width = find_len_width_str(info, len_width);
	new_text = malloc(sizeof(char) * (len_width + 1));
	if (!new_text)
		return (-1);
	len_tmp = fill_string(len_width, new_text, text, info);
	free(new_text);
	return (len_tmp);
}
