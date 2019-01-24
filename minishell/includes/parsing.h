/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 21:15:43 by kicausse          #+#    #+#             */
/*   Updated: 2019/01/23 21:15:43 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

void	read_input(char *buf);

void	ignore_chars(char **dest, char *charset);
int		look_for_chars(char *dest, char *charset);

char	**parse_input(char *input);

#endif
