/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 22:37:41 by kicausse          #+#    #+#             */
/*   Updated: 2018/12/06 22:37:42 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGS_H
# define ARGS_H

# include "args_struct.h"

# define ARGS_H
# define FLAGS 				"AGRaflnort"
# define FLAG_UPPER_A		(1 << 0)
# define FLAG_COLOR			(1 << 1)
# define FLAG_RECURSIVE		(1 << 2)
# define FLAG_ALL			(1 << 3)
# define FLAG_NON_SORT		(1 << 4)
# define FLAG_LIST			(1 << 5)
# define FLAG_NUMERIC_ID	(1 << 6)
# define FLAG_OMIT_GID		(1 << 7)
# define FLAG_REVERSE		(1 << 8)
# define FLAG_TIME_SORT		(1 << 9)

int			validate_parameters(t_args *args, char *str);
void		complete_arguments(t_args *args);
int			validate_arguments(t_args *args, int ac, char **av);

#endif
