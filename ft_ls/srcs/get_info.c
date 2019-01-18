/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 13:15:16 by kicausse          #+#    #+#             */
/*   Updated: 2018/12/16 13:15:17 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_info.h"
#include "get_info_2.h"
#include "args.h"
#include "file_list.h"
#include "libft.h"
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

void	build_time_string(t_files *files)
{
	time_t			tmptime;
	char			*tmp;
	int				len;
	static time_t	currtime;

	if (!currtime)
		time(&currtime);
	tmptime = (time_t)files->time;
	if ((tmp = ctime(&tmptime)) == NULL)
		return ;
	while (*++tmp && *tmp != ' ')
		;
	len = 0;
	while (tmp[len] && tmp[len] != ':')
		++len;
	++len;
	while (tmp[len] && tmp[len] != ':')
		++len;
	if ((files->date = ft_strnew(12)) != NULL)
	{
		ft_strncpy(files->date, tmp + 1, 12);
		if (currtime - tmptime > 15552000)
			ft_strncpy(files->date + 7, tmp + 16, 5);
	}
}

void	get_list_info(t_args *args, t_files *files, struct stat *f_stat)
{
	struct passwd	*pwuid;
	struct group	*grgid;

	build_time_string(files);
	files->nlinks = f_stat->st_nlink;
	if (files->is_link)
		get_symlink_target(files);
	build_permission_string(files->permission, f_stat->st_mode,
		files->is_link);
	files->filesize = f_stat->st_size;
	pwuid = getpwuid(f_stat->st_uid);
	files->owner = (args->flags & FLAG_NUMERIC_ID) || pwuid == 0
		? ft_itoa(f_stat->st_uid) : ft_strdup(pwuid->pw_name);
	grgid = getgrgid(f_stat->st_gid);
	files->group = (args->flags & FLAG_NUMERIC_ID) || grgid == 0 ?
		ft_itoa(f_stat->st_gid) : ft_strdup(grgid->gr_name);
}

void	get_files_info(t_args *args, t_folder *folder, t_files *files)
{
	struct stat	f_stat;

	if (files == 0)
		return ;
	lstat(files->fullpath, &f_stat);
	files->is_link = S_ISLNK(f_stat.st_mode);
	files->is_dir = S_ISDIR(f_stat.st_mode);
	files->is_exec = (f_stat.st_mode & (S_IXUSR | S_IXOTH | S_IXGRP)) != 0;
	files->time = args->flags & FLAG_ACCESS_SORT ?
					f_stat.st_atime : f_stat.st_mtime;
	if (args->flags & FLAG_CREA_SORT)
		files->time = f_stat.st_ctime;
	if (args->flags & FLAG_LIST)
	{
		folder->total += f_stat.st_blocks;
		get_list_info(args, files, &f_stat);
	}
}

void	get_folders_info(t_args *args, t_folder *folders)
{
	struct stat	f_stat;

	if (folders == 0 || folders->exists == 0)
		return ;
	lstat(folders->fullpath, &f_stat);
	folders->is_link = S_ISLNK(f_stat.st_mode);
	folders->is_dir = S_ISDIR(f_stat.st_mode);
	folders->time = args->flags & FLAG_ACCESS_SORT ?
					f_stat.st_atime : f_stat.st_mtime;
	if (args->flags & FLAG_CREA_SORT)
		folders->time = f_stat.st_ctime;
	if (args->flags & FLAG_LIST)
		get_list_info(args, (t_files*)folders, &f_stat);
}
