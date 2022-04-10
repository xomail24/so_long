/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icheri <icheri@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 20:23:46 by icheri            #+#    #+#             */
/*   Updated: 2022/04/09 23:54:49 by icheri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_error(char *str)
{
	ft_putendl_fd("Error", 2);
	if (str)
		ft_putendl_fd(str, 2);
	else
		perror(0);
	exit (-1);
}

static int	check_map_name(char *map_name)
{
	int	fd;

	if (ft_strncmp(map_name + (ft_strlen(map_name) - 4), ".ber", 4))
		ft_error("Invalid map file");
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		ft_error(NULL);
	if (read(fd, NULL, 0) < 0)
		ft_error(NULL);
	return (fd);
}

static size_t	count_string(int fd)
{
	size_t	i;
	char	*s;

	i = 0;
	while (1)
	{
		s = get_next_line(fd);
		if (!s)
			break ;
		free(s);
		i++;
	}
	return (i);
}

static void	make_map(char *map_name, t_slg *slg, int fd)
{
	size_t	i;

	slg->heigth = count_string(fd);
	close(fd);
	slg->map = malloc(sizeof(char *) * (slg->heigth + 1));
	if (!slg->map)
		ft_error(NULL);
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		ft_error(NULL);
	i = 0;
	slg->map[0] = NULL;
	while (i < slg->heigth)
	{
		slg->map[i] = get_next_line(fd);
		if (slg->map[i] == NULL)
			ft_error("invalid Map");
		i++;
	}
	slg->map[i] = NULL;
}

void	parsing(char *map_name, t_slg *slg)
{
	int	fd;

	fd = check_map_name(map_name);
	make_map(map_name, slg, fd);
	is_rectangular(slg);
	is_boarder(slg);
	is_has_player_coolect_exit(slg);
	map_errors(slg);
}
