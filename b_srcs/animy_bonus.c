/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 10:43:24 by mbenkhat          #+#    #+#             */
/*   Updated: 2022/01/06 19:20:11 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	check_wall(char **map, int *x, int *y)
{
	if (map[*y][*x] != '0')
	{
		if (!map[*y][(*x) + 1])
		{
			if (!map[*y + 1])
				*y = 0;
			(*y)++;
			*x = 1;
		}
		(*x)++;
		return (0);
	}
	return (1);
}

int	move_enemy(t_params *par)
{
	static int	x = 1;
	static int	y = 1;
	char		**map;
	static int	w = 0;

	map = par->map;
	if (map[y][x] == 'P')
		exit_program(par->mlx);
	if (w++ <= 3000)
		return (0);
	if (map[y][x - 1] == '0')
		put_img(par->mlx, "imgs/white.xpm", ((x - 1) * 40), (y * 40));
	if (!check_wall(map, &x, &y))
		return (0);
	put_img(par->mlx, "imgs/enemy.xpm", (x * 40), (y * 40));
	x++;
	w = 0;
	return (0);
}

void	draw_player(t_params *par, t_xy xy, int der_x, int der_y)
{
	int	x;
	int	y;

	x = (xy.x + der_x) * 40;
	y = (xy.y + der_y) * 40;
	put_img(par->mlx, "imgs/white.xpm", (xy.x * 40), (xy.y * 40));
	if (der_x == -1 && !der_y)
		put_img(par->mlx, "imgs/right.xpm", x, y);
	if (!der_x && der_y == -1)
		put_img(par->mlx, "imgs/player.xpm", x, y);
	if (der_x == 1 && !der_y)
		put_img(par->mlx, "imgs/left.xpm", x, y);
	if (!der_x && der_y == 1)
		put_img(par->mlx, "imgs/down.xpm", x, y);
}
