/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <fgabler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:23:50 by fgabler           #+#    #+#             */
/*   Updated: 2023/04/12 17:25:55 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_checkfront(char const *str, char const *set)
{
	unsigned int	i;

	i = 0;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_strchr(set, str[i]))
			break ;
		i++;
	}
	return (i);
}

static int	ft_checkback(char const *str, char const *set)
{
	unsigned int	len;
	unsigned int	i;

	len = ft_strlen(str);
	i = ft_strlen(str);
	if (!str[0])
		return (0);
	while (len)
	{
		if (!ft_strchr(set, str[len]))
			break ;
		len--;
	}
	len = len + 1;
	return (i - len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int			start;
	unsigned int			end;

	start = ft_checkfront(s1, set);
	end = ft_checkback(s1, set);
	if (start == ft_strlen((char *) s1))
		return (ft_strdup(""));
	return (ft_substr(s1, start, ft_strlen(s1) - end - start));
}
