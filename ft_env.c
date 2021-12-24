#include "minishell.h"

int ft_env(char **argv, char **env)
{
	int i;

	i = 0;
	if (argv[1] && argv[1][0] == '=')
	{
		write(1, "env: setenv ", 12);
		write(1, argv[1], ft_strlen(argv[i + 1]));
		write(1, ": Invalid argument\n", 19);
		exit_status = 1;
		return (0);
	}
	else if (argv[1])
	{
		write(1, "env: ", 5);
		write(1, argv[1], ft_strlen(argv[i + 1]));
		write(1, ": No such file or directory\n", 28);
		exit_status = 127;
		return (0);
	}
	else
	{
		while (env[i])
		{
			if (ft_strchr(env[i], '='))
			{
				write(1, env[i], ft_strlen(env[i]));
				write(1, "\n", 1);
			}
			i++;
		}
	}
	return (1);
}