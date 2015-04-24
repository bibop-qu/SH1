/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 01:17:03 by basle-qu          #+#    #+#             */
/*   Updated: 2015/04/22 15:27:57 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

void	utf_21_bits(wchar_t c, char **b)
{
	**b = (unsigned char)(((c >> 18)) | 0xF0);
	(*b)++;
	**b = (unsigned char)(((c >> 12) & 0x3F) | 0x80);
	(*b)++;
	**b = (unsigned char)(((c >> 6) & 0x3F) | 0x80);
	**b = (unsigned char)((c & 0x3F) | 0x80);
	(*b)++;
}

void	wc_conversion(wchar_t c, char **b)
{
	if (c < (1 << 7))
	{
		**b = (unsigned char)(c);
		(*b)++;
	}
	else if (c < (1 << 11))
	{
		**b = (unsigned char)((c >> 6) | 0xC0);
		(*b)++;
		**b = (unsigned char)((c & 0x3F) | 0x80);
		(*b)++;
	}
	else if (c < (1 << 16))
	{
		**b = (unsigned char)(((c >> 12)) | 0xE0);
		(*b)++;
		**b = (unsigned char)(((c >> 6) & 0x3F) | 0x80);
		(*b)++;
		**b = (unsigned char)((c & 0x3F) | 0x80);
		(*b)++;
	}
	else if (c < (1 << 21))
		utf_21_bits(c, b);
	**b = '\0';
}

char	*cast_to_wc(wchar_t c)
{
	char wchar[5];
	char *b;
	char *str;

	b = wchar;
	wc_conversion(c, &b);
	str = ft_strdup(wchar);
	if (*str == 0)
		str = ft_strdup("");
	return (str);
}

char	*cast_to_ws(wchar_t *s)
{
	int		i;
	char	wchar[890];
	char	*b;
	char	*str;

	i = -1;
	b = wchar;
	if (!s)
	{
		str = NULL;
		return (str);
	}
	if (*s == 0)
	{
		str = ft_strdup("");
		return (str);
	}
	while (s[++i])
		wc_conversion(s[i], &b);
	str = ft_strdup(wchar);
	return (str);
}
