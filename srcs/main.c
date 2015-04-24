
#include "libft.h"
#include "get_next_line.h"

int		main(void)
{
	char	*cmd;

	get_next_line(0, &cmd);
	ft_printf("$> %s\n", cmd);
	return (0);
}
