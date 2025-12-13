/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psilva-p <psilva-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:31:07 by psilva-p          #+#    #+#             */
/*   Updated: 2025/12/13 18:26:34 by psilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	linelen(char *s)
{
	int	ctd;

	ctd = 0;
	if (!s)
		return (0);
	while (s[ctd] && s[ctd] != '\n')
		ctd++;
	if (s[ctd] == '\n')
		ctd++;
	return (ctd);
}

char	*append_to_line(char *s1, char *s2)
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
	free(s1);
	return (str);
}

void	buffer_shift(char *buffer)
{
	int	line;
	int	stash;

	line = 0;
	stash = 0;
	while (buffer[line] && buffer[line] != '\n')
		buffer[line++] = '\0';
	if (buffer[line] == '\n')
		buffer[line++] = '\0';
	while (buffer[line])
	{
		buffer[stash++] = buffer[line];
		buffer[line++] = '\0';
	}
	buffer[stash] = '\0';
}
