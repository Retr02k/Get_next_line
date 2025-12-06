/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psilva-p <psilva-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 21:22:54 by psilva-p          #+#    #+#             */
/*   Updated: 2025/12/06 21:44:20 by psilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_fdnode
{
	int				fd;
	char			*buf;
	struct s_fdnode	*next;
}				t_fdnode;

char		*get_next_line(int fd);
t_fdnode	*get_node(int fd);
void		free_node(int fd);
char		*ft_strjoin(char *s1, char *s2);
void		buffer_move(char *buffer);
int			linelen(char *s);

#endif