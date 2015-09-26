
#ifndef ENV_H
# define ENV_H

#include "ft_minishell1.h"

void	ft_env(t_env *e);
t_env	*ft_setenv(t_env *e, char **cmd);
t_env	*ft_unsetenv(t_env *e, char **cmd);

#endif
