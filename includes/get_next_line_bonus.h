/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 23:54:52 by isaad             #+#    #+#             */
/*   Updated: 2022/02/07 23:54:56 by isaad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include<unistd.h>
# include<stdlib.h>
# include<stdio.h>
# include<limits.h>
# include<sys/select.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 999999999
# endif

size_t	ft_strlen(const char *s);

char	*ft_strjoin(char *s1, char *s2);

char	*ft_strchr(const char *s, int c);

char	*get_next_line(int fd);

#endif
