/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 18:21:11 by basle-qu          #+#    #+#             */
/*   Updated: 2015/04/22 15:02:31 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_modif(va_list ap, char *str, int *i)
{
	int		ret;

	ret = ft_modifier(ap, str, i);
	*i = *i + 1;
	return (ret);
}

int		ft_ap(va_list ap, char *str, int *i)
{
	int		ret;
	char	*option;
	char	*flag;
	char	*modifier;

	ret = 0;
	option = "sSpdDioOuUxXcC%";
	flag = "#0-+ ";
	modifier = "hljz0123456789";
	if (ft_strchr(option, str[*i]))
		ret = ft_option(ap, str, *i);
	else if (ft_strchr(flag, str[*i]))
	{
		ret = ft_flag(ap, str, i, option);
		*i = *i + 1;
	}
	else if (ft_strchr(modifier, str[*i]))
		ret = ft_modif(ap, str, i);
	else if (str[*i] != ' ')
	{
		ft_putchar(str[*i]);
		ret++;
	}
	return (ret);
}

int		ft_printf(char *str, ...)
{
	int		i;
	int		size;
	int		ret;
	va_list	ap;

	i = 0;
	size = ft_strlen(str);
	ret = 0;
	va_start(ap, str);
	while (i < size)
	{
		if (str[i] == '%')
		{
			i++;
			ret += ft_ap(ap, str, &i);
		}
		else
		{
			ft_putchar(str[i]);
			ret++;
		}
		i++;
	}
	va_end(ap);
	return (ret);
}
