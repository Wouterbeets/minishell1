/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 16:00:11 by wbeets            #+#    #+#             */
/*   Updated: 2013/12/26 21:56:25 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		main(int argc, char **argv, char **env)
{
	t_ex	ex_info;
	char	*input;

	input = "";
	argc = 0;
	argv = 0;
	ex_info.env = env;
	ft_putstr(env[0]);
	ft_putstr("\n");
	ft_putstr(ex_info.env[0]);
	while (ft_strcmp(input, "exit") != 0)
	{
		ft_putstr("$>");
		ft_get_command(&ex_info, &input);
		ft_ex_command(&ex_info);
		free(ex_info.name_ex);
	}
	return (0);
}

int	ft_get_command(t_ex *ex_info, char **input)
{
	int		ret;
	char	**tab;

	ret = get_next_line(0, input);
	tab = ft_strsplit(*input, ' ');
	ex_info->name_ex = tab[0];
	ex_info->argv = tab + 1;
	return (1);
}

int		ft_ex_command(t_ex *ex_info)
{
	pid_t	pid;
	int		ret;

	pid = fork();
	if (pid == 0)
	{
		ft_execute(ex_info);
		exit (0);
	}
	if (pid > 0)
	{
		wait(&ret);
	}
	return (1);
}

int	ft_execute(t_ex *ex_info)
{
	char	**paths;
	char	*tmp;
	int		i;

	i = -1;
	paths = ft_get_paths(ex_info->env);
	while (paths[++i] != '\0')
	{
		ft_putendl(paths[i]);
		tmp = ft_strjoin(paths[i], ex_info->name_ex);
		ft_putendl(tmp);
		execve(tmp, ex_info->argv, ex_info->env);
		free(tmp);
	}
	return (0);
}

char	**ft_get_paths(char **tab)
{
	char	**tmp;
	char	**paths;
	int		i;
	int		j;

	ft_putstr(tab[0]);
	tmp = ft_strsplit(tab[0] + 5 , ':');
	ft_putstr(tmp[0]);
	i = ft_count_c(tab[0], ':') + 1;
	paths = (char**)malloc(i * sizeof(*paths));
	paths[i] = '\0';
	j = 0;
	while(j < i)
	{
		paths[j] = ft_strjoin(tmp[j], "/");
		free(tmp[j]);
		ft_putnbr(j);
		ft_putstr("\n");
		ft_putendl(paths[j]);
		j++;
	}
	ft_putendl("exit while");
	free(tmp);
	return (paths);
}

int		ft_count_c(char *str, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			j++;
		i++;
	}
	return (j);
}
