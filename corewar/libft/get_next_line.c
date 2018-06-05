/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 07:42:05 by kgricour          #+#    #+#             */
/*   Updated: 2018/05/15 18:04:37 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_getstr(const int fd, char *buf, char *tmp[fd])
{
	int		ret;
	char	*temp;

	while (!ft_strchr(buf, '\n') && (ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		temp = tmp[fd];
		buf[ret] = '\0';
		tmp[fd] = ft_strjoin(tmp[fd], buf);
		ft_strdel(&temp);
	}
	ft_strdel(&buf);
	if (ret == -1)
		return (-1);
	return (1);
}

static int	ft_iserror(const int fd, char **line, char **buf)
{
	if (fd < 0 || fd > OPEN_MAX || BUFF_SIZE < 1 || line == NULL)
		return (-1);
	if (!(*buf = ft_strnew(BUFF_SIZE)))
		return (-1);
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char	*tmp[OPEN_MAX];
	char		*buf;
	char		*str;
	char		*temp;

	if (ft_iserror(fd, line, &buf) == -1)
		return (-1);
	if (!tmp[fd])
		tmp[fd] = ft_strnew(1);
	if (ft_getstr(fd, buf, tmp) == -1)
		return (-1);
	if ((str = ft_strchr(tmp[fd], '\n')))
	{
		temp = tmp[fd];
		*line = ft_strsub(tmp[fd], 0, str - tmp[fd], 0);
		tmp[fd] = ft_strdup(str + 1);
		ft_strdel(&temp);
		return (1);
	}
	*line = ft_strdup(tmp[fd]);
	ft_strdel(&tmp[fd]);
	if (*line[0] == '\0')
		return (0);
	return (1);
}
