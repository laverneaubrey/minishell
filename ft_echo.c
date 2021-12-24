#include "minishell.h"

void	status_writing()
{
	char *st;

	st = ft_itoa(exit_status);
	write(1, st, ft_strlen(st));
	free(st);
}

int	ft_echo(char **str)
{
	int i;
	int j;

	i = 0;
	if (str[1] && !ft_strncmp(str[1], "-n\0", 3))
		i++;
	while (str[++i])
	{
		if (!ft_strncmp(str[i], "$?\0", 3))
			status_writing();
		else
			write(1, str[i], ft_strlen(str[i]));
		write(1, " ", 1);
	}
	if (!(str[1] || ft_strncmp(str[1], "-n\0", 3)))
		write(1, "\n", 1);
	return (0);
}