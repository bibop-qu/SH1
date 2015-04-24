/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/14 16:58:56 by basle-qu          #+#    #+#             */
/*   Updated: 2015/02/18 01:13:51 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putulnbr(unsigned long int n)
{
	int		ret;

	ret = 0;
	if (n <= 9)
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
