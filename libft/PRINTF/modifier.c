/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifier.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 16:54:20 by basle-qu          #+#    #+#             */
/*   Updated: 2015/04/23 13:45:26 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		modifhhu(va_list ap)
{
	int		ret;
	int		tmp;

	ret = 0;
	tmp = va_arg(ap, int);
	if (tmp >= -238 && tmp <= 255)
		ret = ft_putnbr(tmp);
	else if (tmp > 255)
		ret = ft_putnbr(-256 + tmp);
	else
		ret = ft_putnbr(237 + (tmp % 239));
	return (ret);
}

int		modifhho(va_list ap)
{
	int		ret;
	int		tmp;

	ret = 0;
	tmp = va_arg(ap, int);
	if (tmp > 255)
		ret = ft_putstring(ft_base("01234567", tmp % 256));
	else
		ret = ft_putstring(ft_base("01234567", tmp));
	return (ret);
}

int		modifhhx(va_list ap)
{
	int		ret;
	int		tmp;

	ret = 0;
	tmp = va_arg(ap, int);
	if (tmp > 255)
		ret = ft_putstring(ft_base("0123456789abcdef", tmp % 256));
	else
		ret = ft_putstring(ft_base("0123456789abcdef", tmp));
	return (ret);
}

int		modifhh_x(va_list ap)
{
	int		ret;
	int		tmp;

	ret = 0;
	tmp = va_arg(ap, int);
	if (tmp > 255)
		ret = ft_putstring(ft_base("0123456789ABCDEF", tmp % 256));
	else
		ret = ft_putstring(ft_base("0123456789ABCDEF", tmp));
	return (ret);
}

int		ft_modifier(va_list ap, char *str, int *i)
{
	int		ret;

	ret = 0;
	if (str[*i] == 'l')
	{
		if (str[*i + 1] == 'd' || str[*i + 1] == 'i' || str[*i + 1] == 'D')
			ret = ft_putlnbr(va_arg(ap, long int));
		else if (str[*i + 1] == 'u' || str[*i + 1] == 'U')
			ret = ft_putulnbr(va_arg(ap, long int));
		else if (str[*i + 1] == 'o' || str[*i + 1] == 'O')
			ret = ft_putstring(ft_base("01234567", va_arg(ap, long int)));
		else if (str[*i + 1] == 'x')
			ret = ft_putstring(ft_base("0123456789abcdef",
								va_arg(ap, long int)));
		else if (str[*i + 1] == 'X')
			ret = ft_putstring(ft_base("0123456789ABCDEF",
								va_arg(ap, long int)));
		else if (str[*i + 1] == 'c')
			ret = print_c(ap);
		else if (str[*i + 1] == 's')
			ret = print_d(ap);
		else if (str[*i + 1] == 'l')
		{
			*i = *i + 1;
			if (str[*i + 1] == 'u')
				ret = ft_putulnbr(va_arg(ap, unsigned long int));
			else if (str[*i + 1] == 'o' || str[*i + 1] == 'O')
				ret = ft_putstring(ft_base("01234567", va_arg(ap, long int)));
			else if (str[*i + 1] == 'x')
				ret = ft_putstring(ft_base("0123456789abcdef", va_arg(ap, long int)));
			else if (str[*i + 1] == 'X')
				ret = ft_putstring(ft_base("0123456789ABCDEF", va_arg(ap, long int)));
			else
				ret = ft_putlnbr(va_arg(ap, long long int));
		}
		else if (str[*i + 1] == 'p')
			ret = ft_option(ap, str, *i + 1);
	}
	else if (str[*i] == 'h')
	{
		if (str[*i + 1] == 'h')
		{
			*i = *i + 1;
			if (str[*i + 1] == 'd' || str[*i + 1] == 'i')
				ret = modifhhd(ap);
			else if (str[*i + 1] == 'u')
				ret = modifhhu(ap);
			else if (str[*i + 1] == 'o')
				ret = modifhho(ap);
			else if (str[*i + 1] == 'x')
				ret = modifhhx(ap);
			else if (str[*i + 1] == 'X')
				ret = modifhh_x(ap);
			else if (str[*i + 1] == 'C')
			{
				ft_putchar(va_arg(ap, int));
				ret = ret + 2;
			}
			else
				ret = ft_option(ap, str, *i + 1);
		}
		else
			ret = ft_option(ap, str, *i + 1);
	}
	else if (str[*i] == 'j')
	{
		if (str[*i + 1] == 'u')
			ret = ft_putulnbr(va_arg(ap, unsigned long int));
		else if (str[*i + 1] == 'o' || str[*i + 1] == 'O')
			ret = ft_putstring(ft_base("01234567", va_arg(ap, long int)));
		else if (str[*i + 1] == 'x')
			ret = ft_putstring(ft_base("0123456789abcdef", va_arg(ap, long int)));
		else if (str[*i + 1] == 'X')
			ret = ft_putstring(ft_base("0123456789ABCDEF", va_arg(ap, long int)));
		else
			ret = ft_putlnbr(va_arg(ap, long int));
	}
	else if (str[*i] == 'z')
		if (str[*i + 1] == 'u')
			ret = ft_putulnbr(va_arg(ap, unsigned long int));
		else if (str[*i + 1] == 'o' || str[*i + 1] == 'O')
			ret = ft_putstring(ft_base("01234567", va_arg(ap, long int)));
		else if (str[*i + 1] == 'x')
			ret = ft_putstring(ft_base("0123456789abcdef", va_arg(ap, long int)));
		else if (str[*i + 1] == 'X')
			ret = ft_putstring(ft_base("0123456789ABCDEF", va_arg(ap, long int)));
		else
			ret = ft_putlnbr(va_arg(ap, long int));
	else if (ft_isdigit(str[*i]))
	{
		ret = modifspace(ap, str, i);
		*i = *i - 1;
	}
	return (ret);
}
