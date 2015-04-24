/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 11:35:00 by basle-qu          #+#    #+#             */
/*   Updated: 2015/04/22 15:13:22 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_putnbr(int n)
{
	int			ret;
	long int	nb;

	ret = 0;
	nb = n;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
		ret++;
	}
	if (nb >= 0 && nb <= 9)
	{
		ft_putchar(nb + '0');
		ret++;
	}
	if (nb > 9)
	{
		ret += ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + '0');
		ret++;
	}
	return (ret);
}
