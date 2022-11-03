/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaad <isaad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 23:54:42 by isaad             #+#    #+#             */
/*   Updated: 2022/11/03 13:07:40 by isaad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/get_next_line_bonus.h"

char	*freeme(char *s, char *str)
{
	free (s);
	free (str);
	return (NULL);
}

char	*ft_line(char *str)
{
	int		i;
	char	*s;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	s = (char *)malloc(i + 2);
	if (!s)
		return (NULL);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		s[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_next(char *str)
{
	int		i;
	char	*s;
	int		j;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\0')
	{
		free (str);
		return (NULL);
	}
	s = (char *)malloc(ft_strlen(str) - i + 1);
	if (!s)
		return (NULL);
	i++;
	while (str[i])
		s[j++] = str[i++];
	s[j] = '\0';
	free (str);
	return (s);
}

char	*ft_read(int fd, char *new)
{
	int		i;
	char	*s;

	i = 1;
	s = (char *)malloc(BUFFER_SIZE + 1);
	if (!s)
		return (NULL);
	while (!ft_strchr(new, '\n') && i != 0)
	{
		i = read (fd, s, BUFFER_SIZE);
		if (i == -1)
		{
			free (s);
			return (NULL);
		}
		s[i] = '\0';
		new = ft_strjoin(new, s);
	}
	if (new[0] == '\0')
	{
		freeme(s, new);
		return (NULL);
	}
	free (s);
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*str[OPEN_MAX];
	char		*final;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	str[fd] = ft_read(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	final = ft_line(str[fd]);
	if (!str[fd])
		return (final);
	str[fd] = ft_next(str[fd]);
	return (final);
}
