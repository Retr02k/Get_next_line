/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psilva-p <psilva-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 19:18:21 by psilva-p          #+#    #+#             */
/*   Updated: 2025/12/05 15:12:43 by psilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
#  define MAX_FD 1024
# endif

int	linelen(char *s);
char	*ft_strjoin(char *s1, char *s2);
void	buffer_move(char *buffer);


#endif