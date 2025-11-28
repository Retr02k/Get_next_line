/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psilva-p <psilva-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:22:21 by psilva-p          #+#    #+#             */
/*   Updated: 2025/11/21 21:52:03 by psilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
int 	linelen(char *s);
char	*ft_strjoin(char *s1, char *s2);
void	buffer_move(char *buffer);
int		newline_in_buffer(char *str);

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE + 1];
	char			*line;
	size_t			bytes_lidos;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (*buffer || read(fd, buffer, BUFFER_SIZE) > 0)
	{
		// bytes_lidos = read(fd, buffer, BUFFER_SIZE);
		// write(1, buffer, newline_in_buffer(buffer));
		line = ft_strjoin(line, buffer);
		if (!line)
			return (free(line), NULL);
		buffer_move(buffer);
		bytes_lidos = linelen(line);
		if (line[bytes_lidos - 1] == '\n')
			return (line);
		// if (buffer[newline_in_buffer(buffer)] == '\n')
			// break;
		// if (bytes_lidos == 0)
			// break;
		// else if (bytes_lidos < 0)
			// return(NULL);
	}
	return (line);
}


int main()
{
	int fd;

	fd = open("test.txt", O_RDONLY);
	printf("%s\n", get_next_line(fd));
	// get_next_line(fd);
	return (0);
}