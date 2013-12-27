/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 16:00:11 by wbeets            #+#    #+#             */
/*   Updated: 2013/12/26 22:14:31 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	**ft_get_paths(char **tab)
{
	char	**tmp;
	char	**paths;
	int		i;
	int		j;

	tmp = ft_strsplit(tab[0] + 5 , ':');
	i = ft_count_c(tab[0], ':') + 1;
	paths = (char**)malloc(i * sizeof(*paths));
	paths[i] = '\0';
	j = 0;
	while (j < i)
	{
		paths[j] = ft_strjoin(tmp[j], "/");
		free(tmp[j]);
		j++;
	}
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