/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psilva-p <psilva-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 19:18:12 by psilva-p          #+#    #+#             */
/*   Updated: 2025/12/05 15:15:57 by psilva-p         ###   ########.fr       */
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

// int main()
// {
//     printf("Maximum open files allowed: %d\n", FOPEN_MAX);
//     return 0;

// 	int fd = open("test.txt", O_RDONLY);
// 	int fd1 = open("test.txt", O_RDONLY);
// 	int fd2 = open("test.txt", O_RDONLY);
// 	int fd3 = open("test.txt", O_RDONLY);
// 	int fd4 = open("test.txt", O_RDONLY);
// 	int fd5 = open("test.txt", O_RDONLY);
// 	int fd6 = open("test.txt", O_RDONLY);
// 	int fd7 = open("test.txt", O_RDONLY);
// 	int fd8 = open("test.txt", O_RDONLY);
// 	int fd9 = open("test.txt", O_RDONLY);
// 	int fd10 = open("test.txt", O_RDONLY);
// 	int fd11 = open("test.txt", O_RDONLY);
// 	int fd12 = open("test.txt", O_RDONLY);
// 	int fd13 = open("test.txt", O_RDONLY);
// 	int fd14 = open("test.txt", O_RDONLY);
// 	int fd15 = open("test.txt", O_RDONLY);
// 	int fd16 = open("test.txt", O_RDONLY);
// 	char *line;

	

// 	close(fd);
// 	return 0;
	


// }