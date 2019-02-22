/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_mod.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 17:08:38 by minakim           #+#    #+#             */
/*   Updated: 2018/05/15 19:40:47 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin_mod(char *s1, char **s2)
{
	int		len_s1;
	int		len_s2;
	char	*str;
	char	*tmp;

	tmp = *s2;
	if (s1 && tmp)
	{
		len_s1 = ft_strlen(s1);
		len_s2 = ft_strlen(tmp);
		str = (char *)malloc(len_s1 + len_s2 + 1);
		if (!str)
			return (NULL);
		if (s1)
			ft_strcpy(str, s1);
		if (tmp)
			ft_strcat(str, tmp);
		free(tmp);
		return (str);
	}
	return (NULL);
}
