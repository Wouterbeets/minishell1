/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 17:14:51 by wbeets            #+#    #+#             */
/*   Updated: 2013/12/26 20:21:58 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include "libft.h"
# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <sys/stat.h>

typedef struct	s_ex
{
	char	**argv;
	char	**env;
	char	*name_ex;
}				t_ex;

int	ft_get_command(t_ex *ex_info, char **input);
int		ft_ex_command(t_ex *ex_info);
int	ft_execute(t_ex *ex_info);
char	**ft_get_paths(char **tab);
int		ft_count_c(char *str, char c);

#endif /* HEADER_H */
