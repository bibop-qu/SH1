/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifier2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/22 15:15:39 by basle-qu          #+#    #+#             */
/*   Updated: 2015/04/22 15:21:19 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		spacep(int tmp)
{
	int	ret;

	ret = 0;
	if (tmp == 0)
		ret += ft_putaddr(NULL);
	else
		ret += ft_putaddr(&tmp);
	return (ret);
}

int		modifspace(va_list ap, char *str, int *i)
{
	int		j;
	int		ret;
	char	*nbr;
	int		tmp;
	int		nb;

	j = *i;
	ret = 0;
	tmp = va_arg(ap, int);
	while (ft_isdigit(str[*i]))
		*i = *i + 1;
	nbr = ft_strsub(str, j, *i - j);
	nb = ft_atoi(nbr) - ft_strlen(ft_itoa(tmp));
	j = -1;
	if (str[*i] == 'p')
		j = 1;
	while (++j < nb)
		ret += ft_putstring(" ");
	if (str[*i] == 'd')
		ret += ft_putnbr(tmp);
	else if (str[*i] == 'p')
		ret = spacep(tmp);
	return (ret);
}

int		modifhhd(va_list ap)
{
	int	ret;
	int tmp;

	tmp = va_arg(ap, int);
	if (tmp < -128)
		ret = ft_putnbr(127 + (tmp % 129));
	else if (tmp >= -128 && tmp <= 127)
		ret = ft_putnbr(tmp);
	else
		ret = ft_putnbr(-128 + (tmp % 128));
	return (ret);
}
