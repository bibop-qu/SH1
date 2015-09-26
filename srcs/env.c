
#include "libft.h"
#include "tools.h"
#include "tools_env.h"
#include "ft_minishell1.h"

void	ft_env(t_env *e)
{
	ft_print_env(e);
}

t_env	*ft_unsetenv(t_env *e, char **cmd)
{
	int		i;

	i = 1;
	if (!cmd[1])
		write(2, "Wrong number of arguments !!\n", 29);
	else if (char_in_tab(cmd, '='))
 		write(2, "Syntaxe error !!\n", 17);
	else
	{
		while (cmd[i])
		{
			 if (find_list(cmd[i], e))
				e = var_del(e, cmd[i], find_list(cmd[i], e));
			i++;
		}
	}
	return (e);
}

t_env	*ft_setenv(t_env *e, char **cmd)
{
	int		arg;
	int		a;
	t_env	*tmp;

	arg = tab_size(cmd);
	a = 0;
	tmp = e;
	if (arg > 3 || !cmd[1])
		write(2, "Wrong number of arguments !!\n", 29);
	else if (char_in_tab(cmd, '='))
 		write(2, "Syntaxe error !!\n", 17);
	else
	{
		while (tmp)
		{
			if (!ft_strcmp(cmd[1], tmp->name))
			{
				if (cmd[2])
				{
					if (tmp->value)
						free(tmp->value);
					tmp->value = ft_strdup(cmd[2]);
				}
				else
					ft_strclr(tmp->value);
				a = 1;
			}
			tmp = tmp->next;
		}
		if (a == 0 && cmd[2])
			e = ft_add_link(e, cmd[1], cmd[2]);
		else if (a == 0 && !cmd[2])
			e = ft_add_link(e, cmd[1], "");
	}
	return (e);
}
