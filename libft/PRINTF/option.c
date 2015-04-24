/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 04:01:32 by basle-qu          #+#    #+#             */
/*   Updated: 2015/04/23 13:37:56 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		printo(va_list ap)
{
	int					ret;
	unsigned long int	nb;
	char				*tmp;

	tmp = NULL;
	nb = va_arg(ap, unsigned long int);
	tmp = ft_base("01234567", nb);
	ret = ft_putstring(tmp);
	return (ret);
}

int		printx(va_list ap)
{
	int					ret;
	unsigned long int	nb;
	char				*tmp;

	tmp = NULL;
	nb = va_arg(ap, unsigned long int);
	tmp = ft_base("0123456789abcdef", nb);
	ret = ft_putstring(tmp);
	return (ret);
}

int		print_x(va_list ap)
{
	int					ret;
	unsigned long int	nb;
	char				*tmp;

	tmp = NULL;
	nb = va_arg(ap, unsigned long int);
	tmp = ft_base("0123456789ABCDEF", nb);
	ret = ft_putstring(tmp);
	return (ret);
}

int		ft_optionb(va_list ap, char *str, int i)
{
	int		ret;

	ret = 0;
	if (str[i] == 'o' || str[i] == 'O')
		ret += printo(ap);
	else if (str[i] == 'X')
		ret += print_x(ap);
	else if (str[i] == 'x')
		ret += printx(ap);
	else if (str[i] == 'c')
	{
		ft_putchar(va_arg(ap, int));
		ret++;
	}
	else if (str[i] == 'C')
		ret = print_c(ap);
	return (ret);
}

int		ft_option(va_list ap, char *str, int i)
{
	int		ret;

	ret = 0;
	if (str[i] == 's')
		ret += ft_putstring(va_arg(ap, char *));
	else if (str[i] == 'S')
		ret = print_s(ap);
	else if (str[i] == 'd' || str[i] == 'i')
		ret += ft_putnbr(va_arg(ap, int));
	else if (str[i] == 'u')
		ret += ft_putlnbr(va_arg(ap, long int));
	else if (str[i] == 'U')
		ret += ft_putulnbr(va_arg(ap, long int));
	else if (str[i] == 'D')
		ret += print_d(ap);
	else if (str[i] == 'p')
		ret += ft_putaddr(va_arg(ap, void *));
	else if (str[i] == '%')
		ret += ft_putstring("%");
	else
		ret += ft_optionb(ap, str, i);
	return (ret);
}
