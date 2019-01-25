/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 02:47:07 by kicausse          #+#    #+#             */
/*   Updated: 2019/01/25 02:47:08 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "shell.h"
#include "libft.h"
#include "constants.h"

void	log_input(t_shell *shell)
{
	int	fd;

	if (shell->no_log)
		return ;
	fd = open(LOG_FILE, O_RDWR | O_CREAT | O_APPEND, 448);
	if (fd < 0)
	{
		shell->no_log = 1;
		ft_putstr_fd(SHELL_NAME": error: could not write logs to file "LOG_FILE
		". Disabling logs.\n", 2);
		return ;
	}
	write(fd, shell->buf, ft_strlen(shell->buf));
	write(fd, "\n", 1);
	close(fd);
}