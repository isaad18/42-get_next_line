/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaad <isaad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 04:11:14 by isaad             #+#    #+#             */
/*   Updated: 2022/02/05 08:03:23 by isaad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include<unistd.h>
# include<stdlib.h>
# include<stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 999999
# endif

size_t	ft_strlen(const char *s);

char	*ft_strjoin(char *s1, char *s2);

char	*ft_strchr(const char *s, int c);

char	*get_next_line(int fd);

#endif
