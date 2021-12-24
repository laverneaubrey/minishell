#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
//# include <dir.h>
//# include <direct.h>
//# include "libft/libft.h"


typedef struct s_msh
{
	int     argc;
	char    **argv;
	char    op;   // '|'   NULL
	int     fdin;
	int     fdout;
	int 	pid;
	struct s_msh *next;
}   t_msh;

//typedef struct	s_pars{
//	char **arguments;
//	char *operator;
//}				t_pars;

typedef struct s_valu
{
	char	**env;
	t_msh	*op;
	int		(*fd)[2];
	int 	pipe_fd;
	int 	pipe_cou;
}				t_valu;

int exit_status;

int		ft_env(char **arg, char **env);
int		ft_built_in_cmd(char **arg, char **env);
int		ft_strncmp(const char *s1, const char *s2, size_t	n);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t	n);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t	dstsize);
char	*ft_strchr(const char *s, int c);
int		ft_echo(char **str);
void	status_writing();
char	*ft_itoa(int n);
char	*vnos(char *rev, int n, int i);
int		size(int num);

#endif
