/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/22 15:57:10 by basle-qu          #+#    #+#             */
/*   Updated: 2015/04/22 15:58:55 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		print_d(va_list ap)
{
	int					ret;
	long int			nbr;
	unsigned long int	tmp;

	ret = 0;
	nbr = va_arg(ap, long int);
	if (nbr >= 0)
		ret += ft_putlnbr(nbr);
	else
	{
		tmp = (unsigned long int)nbr;
		ret += ft_putlnbr(tmp);
	}
	return (ret);
}

int		print_c(va_list ap)
{
	int		ret;
	char	*str;
	wchar_t	c;

	ret = 0;
	c = va_arg(ap, wchar_t);
	str = cast_to_wc(c);
	if (c == 0)
		ret = 1;
	else
		ret = ft_putstring(str);
	return (ret);
}

int		print_s(va_list ap)
{
	int		ret;
	char	*str;
	wchar_t	*s;

	ret = 0;
	s = va_arg(ap, wchar_t*);
	str = cast_to_ws(s);
	ret = ft_putstring(str);
	return (ret);
}
