/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaad <isaad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 07:35:36 by isaad             #+#    #+#             */
/*   Updated: 2022/02/05 08:20:49 by isaad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*ft_line(char *str)
{
	int		i;
	char	*s;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	s = (char *)malloc(i + 2);
	if (!s)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		s[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		s[i] = str[i];
	i++;
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
	if (!str)
	{
		free (str);
		return (NULL);
	}
	s = (char *)malloc(ft_strlen(str) - i + 1);
	if (!s)
		return (NULL);
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
	free (s);
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*final;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_read(fd, str);
	if (!str)
		return (NULL);
	final = ft_line(str);
	str = ft_next(str);
	return (final);
}
