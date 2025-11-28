/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psilva-p <psilva-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:31:07 by psilva-p          #+#    #+#             */
/*   Updated: 2025/11/28 21:39:50 by psilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	linelen(char *s)
{
	int	ctd;

	ctd = 0;
	if (!s)
		return (0);
	while (s && s[ctd] && s[ctd] != '\n')
		ctd++;
	if (s && s[ctd] == '\n')
		ctd++;
	return (ctd);
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
	while (s2 && s2[j] && s2[j] != '\n')
	{
		str[i + j] = s2[j];
		j++;
	}
	if (s2 && s2[j] == '\n')
		str[i + j++] = '\n';
	str[i + j] = '\0';
	free(s1);
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
	while (buffer[i])
		buffer[j++] = buffer[i++];
	buffer[j] = '\0';
}
