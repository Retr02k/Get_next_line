/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psilva-p <psilva-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:22:21 by psilva-p          #+#    #+#             */
/*   Updated: 2025/12/13 18:35:49 by psilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE + 1];
	char			*line;
	int				bytes_read;
	size_t			line_len;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (*buffer || bytes_read > 0)
	{
		if (bytes_read > 0)
			buffer[bytes_read] = '\0';
		line = append_to_line(line, buffer);
		if (!line)
			return (NULL);
		buffer_shift(buffer);
		line_len = linelen(line);
		if (line_len > 0 || line[line_len - 1] == '\n')
			return (line);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	return (line);
}

// int main(void)
// {
// 	int fd = open("multiple_line_with_nl", O_RDONLY);
// 	char *line;
// 	int i = 0;
// 	while ((line = get_next_line(fd)))
// 	{
// 		printf("%s", line);
// 		free(line);
// 		i++;
// 	}
// 	close(fd);
// 	return 0;
// }
