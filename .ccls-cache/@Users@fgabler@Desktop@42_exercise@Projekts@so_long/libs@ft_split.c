/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <fgabler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 13:54:00 by fgabler           #+#    #+#             */
/*   Updated: 2023/04/12 15:35:45 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_sublen(const char *s, char c, unsigned int start)
{
	unsigned int	len;

	len = 0;
	if (!ft_strchr(s, c))
		return (len = ft_strlen(s));
	while (s[start + len] && s[start + len] != c)
	{
		len++;
	}
	return (len);
}

static int	ft_getword(const char *s, char c)
{
	unsigned int	i;
	unsigned int	word;
	int				guard;

	i = 0;
	word = 0;
	guard = 0;
	while (s[i])
	{
		if (s[i] != c && guard == 0)
		{
			word++;
			guard = 1;
		}
		else if (s[i] == c && guard == 1)
		{
			guard = 0;
		}
		i++;
	}
	return (word);
}

static void	ft_free(char **ret, int len)
{
	int	freeit;

	freeit = 0;
	while (freeit < len)
	{
		free (ret[freeit]);
		freeit++;
	}
	free (ret);
}

static void	ft_allocate(const char *s, char c, char **ret)
{
	unsigned int	start;
	unsigned int	sublen;
	unsigned int	loc;
	unsigned int	len;

	loc = 0;
	len = ft_getword(s, c);
	start = 0;
	while (len--)
	{
		while (s[start] == c)
			start++;
		if (s[start] != c || s[start] == '\0')
			sublen = ft_sublen(s, c, start);
		ret[loc] = ft_substr(s, start, sublen);
		if (!ret[loc])
		{
			ft_free(ret, ft_getword(s, c));
			return ;
		}
		if (s[start])
				start = start + sublen;
		loc++;
	}
}

char	**ft_split(char const *s, char c)
{
	char			**ret;

	if (!s)
		return (NULL);
	ret = (char **)ft_calloc (ft_getword(s, c) + 1, sizeof (char *));
	if (!ret)
		return (NULL);
	ft_allocate(s, c, ret);
	return (ret);
}
