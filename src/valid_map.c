/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icheri <icheri@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 17:20:54 by icheri            #+#    #+#             */
/*   Updated: 2022/04/10 11:47:05 by icheri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	is_rectangular(t_slg *slg)
{
	size_t	i;

	if (slg->heigth == 0)
		ft_error("empty map");
	slg->width = ft_strlen(slg->map[0]);
	i = 0;
	while (i < slg->heigth)
	{
		if (ft_strlen(slg->map[i]) != slg->width)
			ft_error("invalid map");
		i++;
	}
}

void	is_boarder(t_slg *slg)
{
	size_t	i;
	size_t	j;
	size_t	last_line;
	size_t	last_column;

	slg->width--;
	last_line = slg->heigth - 1;
	last_column = slg->width - 1;
	i = 0;
	while (i < slg->heigth)
	{
		j = 0;
		while (j < slg->width)
		{
			if (slg->map[0][j] != '1' || slg->map[last_line][j] != '1'
			|| slg->map[i][0] != '1' || slg->map[i][last_column] != '1')
				ft_error("wrong border");
			j++;
		}
		i++;
	}
}

void	count_pce(t_slg *slg, size_t i, size_t j)
{
	if (slg->map[i][j] == 'P')
	{
		slg->count_player++;
		slg->player_x = j;
		slg->player_y = i;
	}
	else if (slg->map[i][j] == 'C')
		slg->count_collect++;
	else if (slg->map[i][j] == 'E')
		slg->count_exit++;
}

void	is_has_player_coolect_exit(t_slg *slg)
{
	size_t	i;
	size_t	j;

	slg->count_exit = 0;
	slg->count_player = 0;
	slg->count_collect = 0;
	i = -1;
	while (++i < slg->heigth)
	{
		j = -1;
		while (++j < slg->width)
		{
			if (slg->map[i][j] == '1' || slg->map[i][j] == '0'
			|| slg->map[i][j] == 'P' || slg->map[i][j] == 'C'
			|| slg->map[i][j] == 'E' )
				count_pce(slg, i, j);
			else
				ft_error("invalid map");
		}
	}
}

void	map_errors(t_slg *slg)
{
	if (slg->count_player != 1 || slg->count_exit < 1)
		ft_error("incorrect number of players or exits");
	if (slg->count_collect < 1)
		ft_error("incorrect number of collection");
}
