/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarouf <amaarouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:40:09 by amaarouf          #+#    #+#             */
/*   Updated: 2022/03/07 18:21:05 by amaarouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen(const char *s);
char	*ft_alloc(int size);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *s1, char *s2);
int		new_line_exist(char *buffer, int size);
char	*get_next_line(int fd);

#endif