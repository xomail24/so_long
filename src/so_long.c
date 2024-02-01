/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icheri <icheri@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 21:06:31 by icheri            #+#    #+#             */
/*   Updated: 2022/04/16 13:30:53 by icheri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_exit(void)
{
	exit(0);
}

int	click_handling(int key_code, t_slg *slg)
{
	if (key_code == 53)
		exit (0);
	key_move(slg, key_code);
	return (0);
}

static void	open_texture(t_slg *slg)
{
	slg->ex = mlx_xpm_file_to_image(slg->mlx, \
	"./texture/ex-2.xpm", &slg->img_width, &slg->img_height);
	if (!slg->ex)
		ft_error("texture exit not found");
	slg->wall = mlx_xpm_file_to_image(slg->mlx, \
	"./texture/wall.xpm", &slg->img_width, &slg->img_height);
	if (!slg->wall)
		ft_error("texture wall not found");
	slg->coll = mlx_xpm_file_to_image(slg->mlx, \
	"./texture/collect-2.xpm", &slg->img_width, &slg->img_height);
	if (!slg->coll)
		ft_error("texture collections not found");
	slg->field = mlx_xpm_file_to_image(slg->mlx, \
	"./texture/field-2.xpm", &slg->img_width, &slg->img_height);
	if (!slg->field)
		ft_error("texture field not found");
	slg->player = mlx_xpm_file_to_image(slg->mlx, \
	"./texture/player-2.xpm", &slg->img_width, &slg->img_height);
	if (!slg->player)
		ft_error("texture player not found");
	slg->closed_ex = mlx_xpm_file_to_image(slg->mlx, \
	"./texture/closed_ex.xpm", &slg->img_width, &slg->img_height);
	if (!slg->closed_ex)
		ft_error("texture closed_ex not found");
}

int	main(int argc, char **argv)
{
	t_slg	slg;

	if (argc != 2)
		return (ft_error("Number of argument must be 2"));
	parsing(argv[1], &slg);
	slg.mlx = mlx_init();
	slg.mlx_win = mlx_new_window(slg.mlx, slg.width * 64, \
	slg.heigth * 64, "./so_long");
	open_texture(&slg);
	render_map(&slg);
	mlx_hook(slg.mlx_win, 17, 0, ft_exit, 0);
	mlx_hook(slg.mlx_win, 2, 0, click_handling, &slg);
	mlx_loop(slg.mlx);
	while(1);
	return (0);
}
