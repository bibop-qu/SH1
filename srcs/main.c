/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/29 11:35:01 by basle-qu          #+#    #+#             */
/*   Updated: 2015/04/29 14:06:54 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <signal.h>
#include "get_next_line.h"

int		main(void)
{
	char	*cmd;

	cmd = NULL;
	while (42)
	{
		ft_putstr("$> ");
		get_next_line(0, &cmd);
		if (!ft_strcmp(cmd, "exit"))
			exit(0);
		else
			ft_putstr(cmd);
		ft_putchar('\n');
	}
	return (0);
}
