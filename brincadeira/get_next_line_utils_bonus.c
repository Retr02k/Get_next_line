/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psilva-p <psilva-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 21:22:41 by psilva-p          #+#    #+#             */
/*   Updated: 2025/12/06 21:43:55 by psilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdlib.h>

static t_fdnode	*g_head = NULL;

t_fdnode	*get_node(int fd)
{
	t_fdnode	*cur;

	cur = g_head;
	while (cur)
	{
		if (cur->fd == fd)
			return (cur);
		cur = cur->next;
	}
	cur = malloc(sizeof(*cur));
	if (!cur)
		return (NULL);
	cur->fd = fd;
	cur->buf = malloc(BUFFER_SIZE + 1);
	if (!cur->buf)
		return (free(cur), NULL);
	cur->buf[0] = '\0';
	cur->next = g_head;
	g_head = cur;
	return (cur);
}

void	free_node(int fd)
{
	t_fdnode	*cur;
	t_fdnode	*prev;

	cur = g_head;
	prev = NULL;
	while (cur)
	{
		if (cur->fd == fd)
		{
			if (prev)
				prev->next = cur->next;
			else
				g_head = cur->next;
			return (free(cur->buf), free(cur));
		}
		prev = cur;
		cur = cur->next;
	}
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	str = malloc(sizeof(char) * (linelen(s1) + linelen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
	{
		str[i + j] = s2[j];
		if (s2[j++] == '\n')
			break ;
	}
	str[i + j] = '\0';
	return (free(s1), str);
}

void	buffer_move(char *buffer)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!buffer)
		return ;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		buffer[0] = '\0';
		return ;
	}
	i++;
	while (buffer[i])
		buffer[j++] = buffer[i++];
	buffer[j] = '\0';
}

int	linelen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		++i;
	return (i);
}
