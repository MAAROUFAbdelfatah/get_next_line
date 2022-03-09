/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarouf <amaarouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:40:05 by amaarouf          #+#    #+#             */
/*   Updated: 2022/03/07 16:46:27 by amaarouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	char	*ft_strjoin_free(char *s1, char *s2, int ptr_free)
{
	char	*ptr;

	ptr = ft_strjoin(s1, s2);
	if (ptr_free)
		return (free(s1), free(s2), ptr);
	else
		return (free(s1), ptr);
}

static	char	*get_text(int fd)
{
	char	*text;
	char	*buffer;
	size_t	read_len;

	text = ft_alloc(1);
	buffer = ft_alloc(BUFFER_SIZE + 1);
	read_len = read(fd, buffer, BUFFER_SIZE);
	while (read_len)
	{
		if (read_len == (size_t)(-1) || text == NULL)
			return (free(text), free(buffer), NULL);
		buffer[read_len] = '\0';
		text = ft_strjoin_free(text, buffer, 0);
		if (new_line_exist(buffer, read_len))
			break ;
		read_len = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	if (text[0] == '\0')
	{
		free(text);
		text = NULL;
	}
	return (text);
}

static	char	*get_line(char *s, int *size)
{
	char	*line;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	*size = i;
	if (s[i] == '\0')
		return (ft_strdup(s));
	line = ft_alloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (s[i] != '\n')
	{
		line[i] = s[i];
		i++;
	}
	line[i] = '\n';
	line[i + 1] = '\0';
	return (line);
}

static	char	*check_remainder(char **remainder, int fd)
{
	char	*text;

	if (*remainder && new_line_exist(*remainder, ft_strlen(*remainder)))
	{
		text = *remainder;
		*remainder = NULL;
	}
	else
		text = get_text(fd);
	return (text);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*line;
	char		*text;
	int			line_len;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	text = check_remainder(&remainder, fd);
	if (text)
	{
		if (remainder == NULL)
			remainder = ft_strdup("");
		line = ft_strjoin_free(remainder, get_line(text, &line_len), 1);
		remainder = NULL;
		if (line != NULL && text[line_len])
			remainder = ft_strdup(text + line_len + 1);
		return (free(text), line);
	}
	text = remainder;
	remainder = NULL;
	if (ft_strlen(text) == 0)
		return (free(text), NULL);
	return (text);
}
