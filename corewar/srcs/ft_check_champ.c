/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_champ.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 22:24:16 by kgricour          #+#    #+#             */
/*   Updated: 2018/06/05 22:33:07 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int		ft_check_magic(int fd, t_header *header)
{
	unsigned int	*magic_cmp;
	unsigned char	tmp[4];

	read(fd, &tmp[3], 1);
	read(fd, &tmp[2], 1);
	read(fd, &tmp[1], 1);
	read(fd, &tmp[0], 1);
	magic_cmp = (unsigned int *)tmp;
	header->magic = *magic_cmp;
	if (header->magic == COREWAR_EXEC_MAGIC)
		return (1);
	return (0);
}

void	ft_check_nbr_inst(int fd, t_header *header)
{
	unsigned int	*nbr_inst_cmp;
	unsigned char	tmp[4];

	lseek(fd, 4, SEEK_CUR);
	read(fd, &tmp[3], 1);
	read(fd, &tmp[2], 1);
	read(fd, &tmp[1], 1);
	read(fd, &tmp[0], 1);
	nbr_inst_cmp = (unsigned int *)tmp;
	header->prog_size = *nbr_inst_cmp;
}

void	ft_check_name(int fd, t_header *header)
{
	unsigned char tmp[PROG_NAME_LENGTH + 1];

	read(fd, &tmp, PROG_NAME_LENGTH);
	ft_strcpy(header->prog_name, (const char *)tmp);
}

void	ft_check_comment(int fd, t_header *header)
{
	unsigned char tmp[COMMENT_LENGTH + 1];

	read(fd, &tmp, COMMENT_LENGTH);
	ft_strcpy(header->comment, (const char *)tmp);
}

void	ft_check_inst(int fd, t_header *header)
{
	unsigned char	tmp[1];
	int				i;

	i = 0;
	lseek(fd, 4, SEEK_CUR);
	while (i < header->prog_size)
	{
		read(fd, &tmp[0], 1);
		header->data[i] = tmp[0];
		i++;
	}
}
