
#include "libft.h"
#include "get_next_line.h"

int		main(void)
{
	char	*cmd;

	ft_putstr("$> ");
	get_next_line(0, &cmd);
	ft_putstr(cmd);
	ft_putchar('\n');
	return (0);
}
