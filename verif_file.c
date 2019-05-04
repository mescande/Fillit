/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 14:00:25 by mescande          #+#    #+#             */
/*   Updated: 2019/05/04 12:55:20 by mescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	**free_n_return(void *buff, char **i)
{
	free(buff);
	return (i);
}

char		**verif_file(int fd)
{
	char	**res;
	char	*buff;
	int		i;
	int		val;

	if (!(buff = (char *)ft_memalloc(sizeof(char) * 6)))
		return (NULL);
	if (!(res = (char **)ft_memalloc(sizeof(char *) * 10)))
		return (free_n_return(buff, NULL));
	buff[5] = 0;
	i = 0;
	while ((val = read(fd, buff, 5)))
	{
		if (val == -1)
			return (free_n_return(buff, NULL));
		res[i++] = ft_strdup(buff);
		ft_bzero(buff, 6);
		if (i % 10 = 0)
			res = ft_memrealloc(res, sizeof(char *) * (i + 10));
	}
	if (val == 0 && buff[0] == 0)
		return (free_n_return(buff, res));
	res[i++] = ft_strdup(buff);
	return (free_n_return(buff, (res = ft_memrealloc(res,
						sizeof(char *) * i))));
}
