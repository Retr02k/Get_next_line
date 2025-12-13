/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psilva-p <psilva-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 19:18:12 by psilva-p          #+#    #+#             */
/*   Updated: 2025/12/13 19:09:19 by psilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char		buffer[MAX_FD][BUFFER_SIZE + 1];
	char			*line;
	int				bytes_read;
	size_t			line_len;

	line = NULL;
	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_read = read(fd, buffer[fd], BUFFER_SIZE);
	while (*buffer[fd] || bytes_read > 0)
	{
		if (bytes_read > 0)
			buffer[fd][bytes_read] = '\0';
		line = append_to_line(line, buffer[fd]);
		if (!line)
			return (NULL);
		buffer_shift(buffer[fd]);
		line_len = linelen(line);
		if (line_len > 0 && line[line_len - 1] == '\n')
			return (line);
		bytes_read = read(fd, buffer[fd], BUFFER_SIZE);
	}
	return (line);
}

// int main(void)
// {
// 	int fd = open("test.txt", O_RDONLY);
// 	int fd2 = open("test2.txt", O_RDONLY);
// 	char *line;
// 	int		i = 0;
// 	int		j = 0;

// 	if (fd == -1)
// 	{
// 		printf("Error opening file");
// 		return 1;
// 	}
// 	while (i < 1)
// 	{
// 		line = get_next_line(fd);
// 		if (line != NULL)
// 		{
// 			printf("line: %s", line);
// 			free(line);
// 		}
// 		i++;
// 	}
// 	while (i < 5)
// 	{
// 		line = get_next_line(fd2);
// 		if (line != NULL)
// 		{
// 			printf("line: %s", line);
// 			free(line);
// 		}
// 		i++;
// 	}
// 	while (i < 10)
// 	{
// 		line = get_next_line(fd);
// 		if (line != NULL)
// 		{
// 			printf("line: %s", line);
// 			free(line);
// 		}
// 		i++;
// 	}
// 	close(fd);
// 	close(fd2);
// 	return 0;
// }
