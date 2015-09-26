
#ifndef EXEC_H
#define EXEC_H

#include "ft_minishell1.h"

void	do_fork(char **cmd, t_env *e, char **env);
char	**listtotab(t_env *list);
int		size_list(t_env *list);

#endif
