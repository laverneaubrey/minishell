#include "minishell.h"

int	ft_built_in_cmd(char **argv, char **env)
{
	if (!ft_strncmp(argv[0], "echo\0", 5))
		ft_echo(argv);
//	if (!ft_strncmp(argv[0], "pwd\0", 4))
//		ft_pwd(env);
	else if (!ft_strncmp(argv[0], "env\0", 4))
		ft_env(argv, env);
	if (!ft_strncmp(argv[0], "export\0", 7))
		ft_export(argv, env);
	if (!ft_strncmp(argv[0], "unset\0", 6))
		ft_unset(argv, env);
	if (!ft_strncmp(argv[0], "cd\0", 3))
		ft_cd(argv, env);
	if (!ft_strncmp(argv[0], "exit\0", 5))
		ft_exit(argv, env);
	else
		return (0);
	return (0);
}
