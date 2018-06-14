/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 16:46:43 by kgricour          #+#    #+#             */
/*   Updated: 2018/06/05 23:03:02 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"


int		ft_nb_player(int argc)
{
	return (argc - 1);
}

t_header	*ft_create_new_header(t_header *header)
{
	t_header *new_header;

	new_header = (t_header *)malloc(sizeof(t_header));
	new_header->next = NULL;
	new_header->magic = 0;
	new_header->prog_name[0] = '\0';
	new_header->comment[0] = '\0';
	new_header->prog_size = 0;
	new_header->data = NULL;
	new_header->num_player = 0;
	new_header->addr_start = 0;
	return (new_header);
}

void	ft_free_header(t_header *header)
{
	t_header *header_tmp;

	header_tmp = NULL;
	while (header)
	{
		header_tmp = header->next;
		free(header->data);
		free(header);
		header = header_tmp;
	}

}

void	ft_check_player(int fd, t_header *header, int i)
{
	int	j;

	j = 0;
	ft_check_name(fd, header);
	ft_check_nbr_inst(fd, header);
	header->data = (unsigned char *)malloc(sizeof(unsigned char) * (header->prog_size + 1));
	header->data[header->prog_size] = '\0';
	ft_check_comment(fd, header);
	ft_check_inst(fd, header);
	j = 0;
	while (j < header->prog_size)
	{
		printf("[%d]", header->data[j]);
		j++;
	}
	printf("\n");

}

void	ft_free(t_header *header, t_header *header_first, t_param *param)
{
	ft_free_header(header_first);
	free(header);
}

t_header	*ft_init(t_param *param, t_header **header, int argc)
{
	t_header	*header_first;

	param->nb_player = ft_nb_player(argc);
	*header = ft_create_new_header(*header);
	header_first = *header;
	param->i = 0;
	param->fd = 0;
	return (header_first);
}

int		main(int argc, char **argv)
{
	t_header	*header;
	t_header	*header_first;
	t_param		param;

	header_first = ft_init(&param, &header, argc);
	while (param.i < param.nb_player)
	{
		param.fd = open(argv[param.i + 1], O_RDONLY);
		if (ft_check_magic(param.fd, header))
			ft_check_player(param.fd, header, param.i);
		else
		{
			printf("Error ! Player %d not valide.", param.i + 1); // a modif par la suite quand option -n, pour numero du joueur.
			break ;
		}
		if (param.i + 1 != param.nb_player)
			header->next = ft_create_new_header(header);
		close(param.fd);
		param.i++;
		header = header->next;
	}
	ft_free(header, header_first,  &param);
	return (0);
}
