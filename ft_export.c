#include "minishell.h"
//
//int	check_exp(char **arg, char **env)
//{
//	int i;
//	int	j;
//
//	i = 1;
//	while (arg[i])
//	{
//		if (arg[i][0] == '=' || ft_isdigit(arg[i][0]))
//		{
//			write(1, " export: \'", 10);
//			write(1, arg[i], ft_strlen(arg[i]));
//			write(1, "\': not a valid identifier\n", 26);
//			exit_status = 1;
//		}
//		else
//		{
//
//		}
//		i++;
//		}
//}

char	**env_sort(char **env)
{
	int		i;
	int 	j;
	int 	k;
	char	**env_sap;
	char	*check;

	i = 0;
	while ((*env)[i])
		i++;
	env_sap = malloc(sizeof(char **) * (i + 1));
	i = -1;
	while ((*env)[++i])
	{
		check = env[i];
		k = -1;
		j = 0;
		while ((*env)[++k])
			if (ft_strncmp(check, env[k], ft_strlen(env[i]) + 1) > 0)
				j++;
		env_sap[j] = check;
	}
	return (env_sap);
}

void	print_quotes(char *str)
{
	while (str && *str != '=')
	{
		write(1, str, 1);
		str++;
	}
	if (str && *str == '=')
	{
		write(1, "=\"", 2);
		str++;
		while (str)
		{
			write(1, str, 1);
			str++
		}
		write(1, "\"", 1);
	}
	write(1, "\n", 1);
}

int	ft_export(char **arg, char **env)
{
	int i;
	int j;
	char **sup;

	i = -1;
	j = 1;
	if (!arg[1])
	{
		sup = env_sort(env);
		while (sup[++i])
		{
			write(1, "declare -x ", 11);
			print_quotes(sup[i]);
		}
		free_mass(sup);
		return (0);
	}
	while (arg[++i])
	{
		if (!ft_isalpha(arg[i][0]))
			error_nvi(arg[0], arg[i]);
		else
		{
			j = env_search_same(arg[i], env);
			if (j)
				if (ft_strchr(arg[i], '='))
				{
					free(env[j]);
					env[j] = arg[i];
				}
			else
				one_mas_fr_two(env, &arg[i]);
		}
	}
}
