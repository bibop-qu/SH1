/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/14 16:58:56 by basle-qu          #+#    #+#             */
/*   Updated: 2015/04/22 15:12:46 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_put(long int n, int ret)
{
	if (n < 0)
	{
		n = -n;
		ft_putchar('-');
		ret++;
	}
	if (n >= 0 && n <= 9)
	{
		ft_putchar(n + '0');
		ret++;
	}
	if (n > 9)
	{
		ret += ft_putlnbr(n / 10);
		ft_putchar(n % 10 + '0');
		ret++;
	}
	return (ret);
}

int		ft_putlnbr(long int n)
{
	int		ret;

	ret = 0;
	if ((unsigned long int)n == -9223372036854775808U)
	{
		write(1, "-9223372036854775808", 20);
		ret += 20;
	}
	else
		ret = ft_put(n, ret);
	return (ret);
}
