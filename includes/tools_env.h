
#ifndef TOOLS_ENV_H
# define TOOLS_ENV_H

char	**recup_name(char **e);
char	**ft_realloc(char **map, char *line);
int		find_tab(char *str, char **tab);
char	**var_replace(char **e, char *name, char *rep);

#endif