/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psilva-p <psilva-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 21:22:30 by psilva-p          #+#    #+#             */
/*   Updated: 2025/12/06 21:41:49 by psilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <unistd.h>

char	*get_next_line(int fd)
{
	t_fdnode	*node;
	char		*line;
	ssize_t		bytes;
	size_t		len;

	line = NULL;
	bytes = 0;
	len = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	node = get_node(fd);
	if (!node)
		return (NULL);
	while ((node->buf[0] != '\0') || ((bytes = read(fd, node->buf, BUFFER_SIZE)) > 0))
	{
		if (bytes > 0)
			node->buf[bytes] = '\0';
		if (bytes < 0)
			return (free(line), free_node(fd), NULL);
		line = ft_strjoin(line, node->buf);
		if (!line)
			return (free_node(fd), NULL);
		buffer_move(node->buf);
		len = linelen(line);
		if (!len || line[len - 1] == '\n')
		{
			if (bytes == 0 && node->buf[0] == '\0')
				free_node(fd);
			return (line);
		}
	}
	return (free_node(fd), line);
}
