/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_form.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 13:19:35 by tbouder           #+#    #+#             */
/*   Updated: 2015/12/17 10:55:18 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** It is the launcher for the functions in ft_extract_form.c. All the forms
** will be put in the 2D char forms
*/

void			ft_extract_forms(char **str, int nb_tetribox, char **forms)
{
	int		i;
	char	c;

	i = 0;
	c = 'A';
	while (i <= nb_tetribox)
	{
		forms[i] = (char *)ft_forme(str[i], c);
		i++;
		c++;
	}
	free(str[i]);
}

/*
** This function will, detect the tetrominos and extract it as a string on
** the top left (if the tetrominos is on the bottom right, this will cut
** all the [.]) before the start of the tetrominos, to keep only this one
*/

char			*ft_forme(char *str, char c)
{
	int		i;
	char	*form;

	i = 0;
	if (str[i + 2] == '#' && str[i + 3] == '#' && str[i + 4] == '#')
		form = (char *)ft_strdup("..#.###.");
	else if (str[i + 3] == '#' && str[i + 4] == '#' && str[i + 5] == '#')
		form = (char *)ft_strdup(".#..###.");
	else if (str[i + 3] == '#' && str[i + 4] == '#' && str[i + 7] == '#')
		form = (char *)ft_strdup(".#..##..#");
	else if (str[i + 3] == '#' && str[i + 4] == '#' && str[i + 8] == '#')
		form = (char *)ft_strdup(".#..##...#");
	else if (str[i + 4] == '#' && str[i + 7] == '#' && str[i + 8] == '#')
		form = (char *)ft_strdup(".#...#..##");
	else if (str[i + 1] == '#' && str[i + 3] == '#' && str[i + 4] == '#')
		form = (char *)ft_strdup(".##...##");
	else
		form = ft_strtrim_char(str, '.');
	i = 0;
	while (form[i])
	{
		form[i] == '#' ? form[i] = c : 0;
		i++;
	}
	return (form);
}
