/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psilva-p <psilva-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:31:07 by psilva-p          #+#    #+#             */
/*   Updated: 2025/11/20 19:13:39 by psilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	newline_in_buffer(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

int linelen(char *s)
{
	int	counter;

	counter = 0;
	if (!s)
		return (0);
	while (s && s[counter] && s[counter] != '\n')
		counter++;
	if (s && s[counter] == '\n')
		counter++;
	return (counter);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		size;
	int		i;
	int		j;
	
	size = linelen(s1) + linelen(s2) + 1;
	str = malloc(size * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = -1;
	while (s2[++j])
	{
		str[i] = s2[j];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	buffer_move(char *buffer)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	i += (buffer[i] == '\n');
	while (buffer[j])
	{
		buffer[j] = buffer[i];
		i++;
		j++;
	}
	buffer[j] = '\0';
}

// int main()
// {
// 	char str[] = "Hello Worldhaukd";
	
// 	buffer_move(str);
// 	printf("%s\n",str);
// 	// char	*str = ft_strjoin(NULL, "World!");
// 	// printf("%s\n", str);
// 	// free(str);

// }
