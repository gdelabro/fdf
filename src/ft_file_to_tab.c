/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 14:51:22 by gdelabro          #+#    #+#             */
/*   Updated: 2016/12/09 17:56:52 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	ft_count(char *file)
{
	int i;
	int nb;

	nb = 0;
	i = -1;
	while (file[++i])
		if (file[i] == '\n')
			nb++;
	return (nb);
}

char		***ft_file_to_tab(char *file)
{
	int		fd;
	char	***tab;
	char	*file2;
	char	*line;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	ft_cpyfile(fd, &file2);
	tab = (char***)malloc(sizeof(**tab) * ft_count(file2) + 1);
	tab[ft_count(file2)] = NULL;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) == 1)
		tab[i++] = ft_strsplit(line, ' ');
	return (tab);
}
