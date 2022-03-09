/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarouf <amaarouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:40:02 by amaarouf          #+#    #+#             */
/*   Updated: 2022/03/07 15:45:54 by amaarouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_alloc(int size)
{
	char	*ptr;

	ptr = (char *)malloc(size * sizeof(char));
	if (!ptr)
		return (NULL);
	*ptr = '\0';
	return (ptr);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s != NULL)
		while (s[i])
			i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*ps1;
	int		i;

	i = 0;
	ps1 = ft_alloc(ft_strlen(s1) + 1);
	if (!ps1)
		return (NULL);
	while (s1[i])
	{
		ps1[i] = s1[i];
		i++;
	}
	ps1[i] = '\0';
	return (ps1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char		*ptr_result;
	size_t		len_s1;
	size_t		len_s2;
	int			i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	ptr_result = ft_alloc(len_s1 + len_s2 + 1);
	if (!ptr_result)
		return (NULL);
	while (*s1)
		ptr_result[i++] = *s1++;
	while (*s2)
		ptr_result[i++] = *s2++;
	ptr_result[i] = '\0';
	return (ptr_result);
}

int	new_line_exist(char *buffer, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
