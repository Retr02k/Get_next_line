/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invencao.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psilva-p <psilva-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 17:05:10 by psilva-p          #+#    #+#             */
/*   Updated: 2025/12/05 18:07:45 by psilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INVENCAO_H
# define INVENCAO_H

# include "/home/psilva-p/github/get_next_line/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

# ifndef MAX_FD
#  define MAX_FD 1024
# endif

typedef struct s_fdstruct
{
	int				fd;
	char			*buf;
	struct s_fdnode	*next;
}					t_fdstruct;

char	*get_next_line(int fd);
int		linelen(char *s);
char	*ft_strjoin(char *s1, char *s2);
void	buffer_move(char *buffer);
// t_fdnode	*get_node(int fd);
// void		remove_node(int fd);
#endif