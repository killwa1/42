/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 06:28:55 by kicausse          #+#    #+#             */
/*   Updated: 2018/11/08 06:28:55 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

int			get_next_line(const int fd, char **line)
{
	char	*npos;
	char	*output;
	char	buffer[BUFF_SIZE + 1];
	static char	*linebuffer;
	int		read_chars;

	output = NULL;
	buffer[BUFF_SIZE] = '\0';
	while ((read_chars = read(fd, buffer, BUFF_SIZE - 1)) > 0)
	{
		if ((npos = ft_strchr(buffer, '\n')) != NULL)
		{
			if (output == NULL) {
				output = ft_strsub(buffer, 0, (size_t)(npos - buffer));
				linebuffer = ft_strdup(npos);
			}
			break;
		}
	}
	*line = output;
	return (0);
}
