/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icheri <icheri@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 15:48:18 by icheri            #+#    #+#             */
/*   Updated: 2022/04/10 11:52:31 by icheri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	draw_map(t_slg *slg, size_t x, size_t y)
{
	mlx_put_image_to_window(slg->mlx, \
	slg->mlx_win, slg->field, x * 64, y * 64);
	if (slg->map[y][x] == '1')
		mlx_put_image_to_window(slg->mlx, \
		slg->mlx_win, slg->wall, x * 64, y * 64);
	if (slg->map[y][x] == 'P')
		mlx_put_image_to_window(slg->mlx, \
		slg->mlx_win, slg->player, x * 64, y * 64);
	if (slg->map[y][x] == 'C')
		mlx_put_image_to_window(slg->mlx, \
		slg->mlx_win, slg->coll, x * 64, y * 64);
	if (slg->map[y][x] == 'E')
	{
		if (slg->count_collect)
			mlx_put_image_to_window(slg->mlx, \
			slg->mlx_win, slg->closed_ex, x * 64, y * 64);
		else if (!slg->count_collect)
			mlx_put_image_to_window(slg->mlx, \
			slg->mlx_win, slg->ex, x * 64, y * 64);
	}
}

void	render_map(t_slg *slg)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < slg->heigth)
	{
		x = 0;
		while (x < slg->width)
		{
			draw_map(slg, x, y);
			x++;
		}
		y++;
	}
}
