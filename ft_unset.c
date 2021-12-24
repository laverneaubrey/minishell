#include "minishell.h"

int uns_rewrite(char *arg, char **env, int n)
{
	char *sup;

	while ((*env)[n])
	{
		sup = env[n + 1]
		free(env[n]);
		env[n] = sup;
	}
}

int ft_unset(char **arg, char **env)
{
	int	i;
	int j;

	i = 0;
	if (!arg[1])
		return (0);
	while(arg[i])
	{
		if (!ft_isalpha(arg[i][0]) || ft_strchr("=.\\\0", arg[1][0]))
			error_nva(arg[0], arg[i]);
		j = -1;
		while (arg[i][++j])
			if (ft_isalnum(arg[i][j]))
				error_nva(arg[0], arg[i]);
		j = env_search_same(arg[i], env);
		if (j)
			uns_rewrite(arg[i], env, j);
		i++;
	}
	return (0);
}
