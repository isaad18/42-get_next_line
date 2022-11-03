/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaad <isaad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 04:11:27 by isaad             #+#    #+#             */
/*   Updated: 2022/11/03 13:08:05 by isaad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == (char )c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char )c)
		return ((char *)(s + i));
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	int		x;
	int		xx;

	x = 0;
	xx = 0;
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[x] = '\0';
	}
	new = (char *)malloc(sizeof (char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!new)
		return (0);
	while (s1[x] != '\0')
	{
		new[x] = s1[x];
		x++;
	}
	while (s2[xx] != '\0')
		new[x++] = s2[xx++];
	new[x] = '\0';
	free (s1);
	return (new);
}
