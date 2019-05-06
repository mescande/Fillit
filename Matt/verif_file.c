/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 14:00:25 by mescande          #+#    #+#             */
/*   Updated: 2019/05/06 12:05:38 by mescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static char	**free_n_return(void *buff, char **i)
{
	free(buff);
	return (i);
}

static int	something_else(char *line)
{
	int	count;

	count = 0;
	if (ft_strlen(line) != 4)
		return (-1);
	while (*line != '\0')
	{
		if (*line != '.' && *line != '#')
			return (-1);
		if (*line == '#')
			count++;
		line++;
	}
	return (count);
}

/*
**static int	count_#(char *line)
**{
**	int res;
**
**	while (*line)
**		if (*(line++) == #
**}
**
**
**static char	**translate(char **src, int len)
**{
**	char **dst;
**
**	if (!(dst = (char **)ft_memalloc(len / 4)))
**		return (free_n_return(src, NULL));
**	return (src);
**}
*/

char		**verif_file(int fd)
{
	char	**res;
	int		i;
	int		val;
	int		count;

	if (!(res = (char **)ft_memalloc(sizeof(char *) * 5)))
		return (NULL);
	i = 0;
	count = 0;
	while ((val = get_next_line(fd, res + count)) == 1)
	{
		if ((i == 0 || i % 5 != 4) && (res[count][i % 5] =
					something_else(res[count])) == -1)
			return (free_n_return(res, NULL));
		if (i != 0 && i % 5 == 4 && (!(res[count++ + 1] =
			(char *)ft_memalloc(5)) || ft_strlen(res[count]) != 0))
			return (free_n_return(res, NULL));
		else if (count % 4 == 0)
			res = (char **)ft_memrealloc(res, count + 5, count);
		i++;
	}
	if (val == -1)
		return (free_n_return(res, NULL));
	res[count + 1] = NULL;
	return (res);
}
