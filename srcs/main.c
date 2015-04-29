/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/29 11:35:01 by basle-qu          #+#    #+#             */
/*   Updated: 2015/04/29 12:28:28 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

int		main(void)
{
	pid_t	father;
	char	*cmd;

	father = fork();
	if (father > 0)
	{

	}
	ft_putstr("$> ");
	get_next_line(0, &cmd);
	ft_putstr(cmd);
	ft_putchar('\n');
	return (0);
}
