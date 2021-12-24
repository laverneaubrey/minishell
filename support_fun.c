#include "minishell.h"

void	error_nsfod(char *comm, char *arg)
{
	write(1, comm, ft_strlen(comm));
	write(1, ": ", 2);
	write(1, arg, ft_strlen(arg));
	write(1, ": No such file or directory\n", 28);
}

void	error_nva(char *comm, char *arg)
{
	write(1, comm, ft_strlen(comm));
	write(1, ": \'", 3);
	write(1, arg, ft_strlen(arg));
	write(1, "\': not a valid identifier\n", 26);
}

void free_mass(char **mass)
{
	int i;
	int j;

	i = 0;
	j = 0;

	while (mass[i])
		i++;
	while (i >= 0)
	{
		free(mass[i]);
		mass[i] = "\0";
		i--:
	}
}

void	*one_mas_fr_two(char **str, char **from)
{
	int 	i;
	int 	j;
	char	**mass;

	i = 0;
	j = 0;
	while(str[i])
		i++;
	while(from[j])
		j++;
	mass = malloc(sizeof(char *) * (i + j + 1));
	i = -1;
	j = -1;
	while (str[++i])
		mass[i] = str[i];
	while (from[++j])
		mass[i + j] = from[j];
	mass[i + j] = "\0";
	free(str);
	free(from);
	str = mass;
}

int	env_search_same(char *arg, char **env)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	while (arg[k] != '=' && arg[k])
		k++;
	while ((*env)[i])
	{
		j = 0;
		while (env[i][j] != '=' && env[i][j])
			j++;
		if (!ft_memcmp(arg, env[i], j) && k == j)
			return (i);
		i++;
	}
	return (0);
}

//char	*env_search_value(char *arg, char **env)
//{
//	int i;
//	int j;
//	int k;
//
//	i = 0;
//	k = 0;
//	while (arg[k] != '=' && arg[k])
//		k++;
//	while ((*env)[i])
//	{
//		j = 0;
//		while (env[i][j] != '=' && env[i][j])
//			j++;
//		if (k == j && !ft_memcmp(arg, env[i], j))
//			return(&env[i][j]);
//		i++;
//	}
//	return (0);
//}