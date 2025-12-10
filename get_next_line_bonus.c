/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psilva-p <psilva-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 19:18:12 by psilva-p          #+#    #+#             */
/*   Updated: 2025/12/10 17:29:50 by psilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char		buffer[MAX_FD][BUFFER_SIZE + 1];
	char			*line;
	size_t			bytes_lidos;

	line = NULL;
	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	while (*buffer || read(fd, buffer, BUFFER_SIZE) > 0)
	{
		line = ft_strjoin(line, buffer);
		if (!line)
			return (NULL);
		buffer_move(buffer);
		bytes_lidos = linelen(line);
		if (!bytes_lidos || line[bytes_lidos - 1] == '\n')
			return (line);
	}
	return (line);
}

int main()
{
	int fd = open("test.txt", O_RDONLY);
	int fd1 = open("test2.txt", O_RDONLY);

	
}