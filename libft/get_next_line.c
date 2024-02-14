/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: gbelange <gbelange@student.42quebec.com    +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2022/04/30 18:28:01 by gbelange          #+#    #+#             */
/*   Updated: 2022/05/09 17:08:59 by gbelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_free_n_join(char *stash, char *buf)
{
	char	*j;

	j = ft_strjoin(stash, buf);
	free(stash);
	return (j);
}

static char	*ft_newstash(char *stash)
{
	char	*newstash;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (stash[i] != '\0' && stash[i] != '\n')
		i++;
	if (stash[i] == '\0')
	{
		free(stash);
		return ((void *)0);
	}
	newstash = malloc((ft_strlen(stash) - i + 1) * sizeof(char));
	if (!newstash)
		return ((void *)0);
	i++;
	while (stash[i] != '\0')
		newstash[j++] = stash[i++];
	newstash[j] = '\0';
	free(stash);
	return (newstash);
}

static char	*ft_line(char *stash)
{
	size_t	i;
	char	*line;

	if (!*stash)
		return ((void *)0);
	i = ft_strlen(stash);
	line = malloc((i + 1) * sizeof(char));
	if (!line)
		return ((void *)0);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*ft_readintostash(int fd, char *stash)
{
	char	*buf;
	int		bytes_read;

	if (!stash)
		stash = ft_strdup("");
	buf = calloc(BUFFER_SIZE + 1, sizeof(char));
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buf);
			return ((void *)0);
		}
		buf[bytes_read] = '\0';
		stash = ft_free_n_join(stash, buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	free(buf);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (read(fd, 0, 0) < 0 || fd < 0 || BUFFER_SIZE <= 0)
		return ((void *)0);
	stash = ft_readintostash(fd, stash);
	if (!stash)
		return ((void *)0);
	line = ft_line(stash);
	stash = ft_newstash(stash);
	return (line);
}
