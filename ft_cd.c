#include "minishell.h"

int ft_cd(char **arg, char **env)
{
	int	i;
	int j;
	char *sup;
	char *old_pwd;
	char *fut_pwd;

	i = 0;
	if (!ft_strncmp(arg[1], "..\0", 3))
	{
		i = env_search_same("PWD\0", env);
		sup = ft_substr(env[i], 4, ft_strlen(&env[i][4]) - ft_strlen(ft_strchr(env[i], '/')));
		env[i] = old_pwd;
	}
	else if (!ft_strncmp(arg[1], "-\0", 2))
	{
		i = env_search_same("OLDPWD\0", env);
		sup = ft_substr(env[i], 7, ft_strlen(&env[i][7]));
		write(1, sup, ft_strlen(sup));
	}
	else if (!arg[1])
	{
		i = env_search_same("HOME\0", env);
		sup = ft_substr(env[i], 5, ft_strlen(&env[i][5]));
	}
	else
	{
		sup = arg[1];
	}
	j = env_search_same("PWD\0", env);
	i = env_search_same("OLDPWD\0", env);
	if (!chdir(sup))
	{
		free(env[i]);
		env[i] = ft_strjoin("OLDPWD=\0", &env[j][4]);
		free(env[j]);
		getcwd(env[j], 1024);
	}
	else
	{
		error_nsfod(arg[1]);
		return (1);
	}
	free(sup);
	return (0);
}