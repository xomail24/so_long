/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icheri <icheri@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 21:06:57 by icheri            #+#    #+#             */
/*   Updated: 2022/04/09 23:59:23 by icheri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/errno.h>
# include <mlx.h>
# include "../libft/libft.h"
# include "get_next_line.h"

# define W 13
# define A 0
# define S 1
# define D 2

typedef struct s_slg {
	char		**map;
	size_t		heigth;
	size_t		width;
	size_t		count_player;
	size_t		count_exit;
	size_t		count_collect;
	size_t		player_x;
	size_t		player_y;
	void		*mlx;
	void		*mlx_win;
	void		*field;
	void		*player;
	void		*ex;
	void		*coll;
	void		*wall;
	void		*closed_ex;
	void		*gameover;
	int			img_width;
	int			img_height;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			moves;

}				t_slg;

int		ft_exit(void);
int		ft_error(char *str);
void	is_rectangular(t_slg *slg);
void	is_boarder(t_slg *slg);
void	is_has_player_coolect_exit(t_slg *slg);
void	map_errors(t_slg *slg);
void	parsing(char *map_name, t_slg *slg);
void	render_map(t_slg *slg);
void	key_move(t_slg *slg, int key_code);
#endif
