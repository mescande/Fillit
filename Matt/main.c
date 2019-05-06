/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 12:08:33 by mescande          #+#    #+#             */
/*   Updated: 2019/05/04 20:58:25 by mescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

char	**ft_makeitprintable(char **str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	printf("bouh\n");
	while (i != 4)
	{
		while (j != 4)
		{
		   str[i][j]	+= '0';
		   write(1, str[i] + j++, 1);
		}
		write(1, "\n", 1);
		i++;
	}
	return (str);
}

int		init_fun(char *file)
{
	int		fd;
	char	**tab;

	fd = open(file, O_RDONLY);
	if (!(tab = verif_file(fd)))
		return (1);
	close(fd);
	tab = ft_makeitprintable(tab);
	if (!(tab = fillit(tab)))
		return (1);
	ft_putstrstr(tab);
	return (0);
}

int		main(int ac, char **av)
{
	if (ac != 2)
	{
		write(1, "usage: ./fillit source_file\n", 29);
		return (1);
	}
	if (init_fun(av[1]))
	{
		write(1, "error\n", 6);
		return (1);
	}
	return (0);
}
