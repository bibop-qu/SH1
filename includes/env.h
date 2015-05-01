
#ifndef ENV_H
# define ENV_H

void	ft_aff_env(char **e);
char	**ft_unsetenv(char **e, char **cmd);
char	**ft_setenv(char **e, char **cmd);
char	**init_env(char **env);

#endif
