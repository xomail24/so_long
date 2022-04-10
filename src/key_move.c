/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icheri <icheri@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:40:48 by icheri            #+#    #+#             */
/*   Updated: 2022/04/09 23:59:14 by icheri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	move_w(t_slg *slg)
{
	size_t	x;
	size_t	y;

	x = slg->player_x;
	y = slg->player_y;
	if (slg->map[y - 1][x] == '0' || slg->map[y - 1][x] == 'C')
	{
		if (slg->map[y - 1][x] == 'C')
			slg->count_collect--;
		slg->map[y - 1][x] = 'P';
		slg->map[y][x] = '0';
		slg->player_y--;
		slg->moves++;
		ft_putchar(ft_itoa(slg->moves));
	}
	else if ((slg->map [y - 1][x] == 'E') && (!slg->count_collect))
	{
		ft_putendl_fd("You are win", 1);
		exit(0);
	}
}

static void	move_a(t_slg *slg)
{
	size_t	x;
	size_t	y;

	x = slg->player_x;
	y = slg->player_y;
	if (slg->map[y][x - 1] == '0' || slg->map[y][x - 1] == 'C')
	{
		if (slg->map[y][x - 1] == 'C')
			slg->count_collect--;
		slg->map[y][x - 1] = 'P';
		slg->map[y][x] = '0';
		slg->player_x--;
		slg->moves++;
		ft_putchar(ft_itoa(slg->moves));
	}
	else if ((slg->map [y][x - 1] == 'E') && (!slg->count_collect))
	{
		ft_putendl_fd("You are win", 1);
		exit(0);
	}
}

static void	move_s(t_slg *slg)
{
	size_t	x;
	size_t	y;

	x = slg->player_x;
	y = slg->player_y;
	if (slg->map[y + 1][x] == '0' || slg->map[y + 1][x] == 'C')
	{
		if (slg->map[y + 1][x] == 'C')
			slg->count_collect--;
		slg->map[y + 1][x] = 'P';
		slg->map[y][x] = '0';
		slg->player_y++;
		slg->moves++;
		ft_putchar(ft_itoa(slg->moves));
	}
	else if ((slg->map [y + 1][x] == 'E') && (!slg->count_collect))
	{
		ft_putendl_fd("You are win", 1);
		exit(0);
	}
}

static void	move_d(t_slg *slg)
{
	size_t	x;
	size_t	y;

	x = slg->player_x;
	y = slg->player_y;
	if (slg->map[y][x + 1] == '0' || slg->map[y][x + 1] == 'C')
	{
		if (slg->map[y][x + 1] == 'C')
			slg->count_collect--;
		slg->map[y][x + 1] = 'P';
		slg->map[y][x] = '0';
		slg->player_x++;
		slg->moves++;
		ft_putchar(ft_itoa(slg->moves));
	}
	else if ((slg->map [y][x + 1] == 'E') && (!slg->count_collect))
	{
		ft_putendl_fd("You are win", 1);
		exit(0);
	}
}

void	key_move(t_slg *slg, int key_code)
{
	if (key_code == W)
		move_w(slg);
	if (key_code == A)
		move_a(slg);
	if (key_code == S)
		move_s(slg);
	if (key_code == D)
		move_d(slg);
	render_map(slg);
}
