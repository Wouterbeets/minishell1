/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:15:00 by wbeets            #+#    #+#             */
/*   Updated: 2013/12/04 12:19:36 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	int		i;

	i = 0;
	dup = (char*)malloc(ft_strlen(s1) * sizeof(dup));
	while (s1[i] != '\0')
	{
		dup[i] = s1[i];
		i++;
	}
	return (dup);
}
