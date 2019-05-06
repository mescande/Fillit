/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 12:08:56 by mescande          #+#    #+#             */
/*   Updated: 2019/05/04 19:17:07 by mescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"
# include "get_next_line.h"

void	ft_putstrstr(char **str);
int		init_fun(char *file);
int		main(int ac, char **av);

char	**verif_file(int fd);

char	**fillit(char **tab);

#endif
