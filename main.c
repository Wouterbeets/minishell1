/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 16:00:11 by wbeets            #+#    #+#             */
/*   Updated: 2013/12/26 22:14:31 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



/*boooonnnnnn oublier pas de droit de acces fichier et reportoir
 * gestiondes euruer quand executable n existate pas*/

#include "header.h"

int		main(int argc, char **argv, char **env)
{
	t_ex	ex_info;
	char	*input;

	input = "";
	argc = 0;
	argv = 0;
	ex_info.env = env;
	while (ft_strcmp(input, "exit") != 0)
	{
		ft_putstr("$>");
		ft_get_command(&ex_info, &input);
		ft_ex_command(&ex_info);
		free(ex_info.name_ex);
	}
	return (0);
}

int		ft_get_command(t_ex *ex_info, char **input)
{
	int		ret;
	char	**tab;

	ret = get_next_line(0, input);
	tab = ft_strsplit(*input, ' ');
	ex_info->name_ex = tab[0];
	ex_info->argv = tab;
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
	char		**paths;
	char		*tmp;
	int			i;

	i = -1;
	paths = ft_get_paths(ex_info->env);
	while (paths[++i] != '\0')
	{
		tmp = ft_strjoin(paths[i], ex_info->name_ex);
		execve(tmp, ex_info->argv, ex_info->env);
		free(tmp);
	}
	return (0);
}