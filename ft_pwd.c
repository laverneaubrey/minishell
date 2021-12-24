#include "minishell.h"

int ft_pwd(char **env)
{
	char *path;

	getcwd(path, 1024);
	write(1, path, ft_strlen(path));
	write(1, "\n", 1);
	free(path);
	return (0);
}