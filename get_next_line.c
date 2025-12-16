/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psilva-p <psilva-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:22:21 by psilva-p          #+#    #+#             */
/*   Updated: 2025/12/13 20:23:20 by psilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE + 1];
	char			*line;
	size_t			line_len;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (*buffer || read(fd, buffer, BUFFER_SIZE) > 0)
	{
		line = append_to_line(line, buffer);
		if (!line)
			return (NULL);
		buffer_shift(buffer);
		line_len = linelen(line);
		if (!line_len || line[line_len - 1] == '\n')
			return (line);
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
