/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 19:34:02 by mbenkhat          #+#    #+#             */
/*   Updated: 2022/01/06 12:06:07 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	put_img(t_data	*mlx, char *path, int x, int y)
{
	int		width;
	int		height;
	void	*img;

	width = 40;
	height = 40;
	img = mlx_xpm_file_to_image(mlx->mlx_ptr, path, &width, &height);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, img, x, y);
}

void	draw_map(char **map, t_data *mlx)
{
	int	i;
	int	x;
	int	y;

	y = 0;
	while ((*map))
	{
		i = 0;
		x = -40;
		while ((*map)[i])
		{
			if ((*map)[i] == '1')
				put_img(mlx, "imgs/wall1.xpm", (x += 40), y);
			if ((*map)[i] == '0')
				put_img(mlx, "imgs/white.xpm", (x += 40), y);
			if ((*map)[i] == 'P')
				put_img(mlx, "imgs/player.xpm", (x += 40), y);
			if ((*map)[i] == 'C')
				put_img(mlx, "imgs/collect.xpm", (x += 40), y);
			if ((*map)[i++] == 'E')
				put_img(mlx, "imgs/exit.xpm", (x += 40), y);
		}
		map++;
		y += 40;
	}
}

void	move_player(t_params *par, t_xy xy, int der_x, int der_y)
{
	static int	x;
	t_xy		check;
	char		**map;

	map = par->map;
	check = get_char(map, 'C');
	if (map[xy.y + der_y][xy.x + der_x] == 'E')
	{
		if (!check.x)
		{
			exit_program(par->mlx);
		}
		return ;
	}
	draw_player(par, xy, der_x, der_y);
	map[xy.y][xy.x] = '0';
	map[xy.y + der_y][xy.x + der_x] = 'P';
	x++;
	put_img(par->mlx, "imgs/wall1.xpm", 0, 0);
	mlx_string_put(par->mlx->mlx_ptr, par->mlx->mlx_win, 10,
		10, 0x0000FF, ft_itoa(x));
}

int	key_press(int keycode, t_params *par)
{
	t_xy		xy;
	char		**map;
	t_data		*mlx;

	if (keycode == 53)
		exit_program(par->mlx);
	map = par->map;
	mlx = par->mlx;
	xy = get_char(par->map, 'P');
	if ((keycode == 0) && (map[xy.y][(xy.x - 1)] != '1'))
		move_player(par, xy, -1, 0);
	if ((keycode == 13) && (map[xy.y - 1][xy.x] != '1'))
		move_player(par, xy, 0, -1);
	if ((keycode == 2) && (map[xy.y][(xy.x + 1)] != '1'))
		move_player(par, xy, 1, 0);
	if ((keycode == 1) && (map[(xy.y + 1)][xy.x] != '1'))
		move_player(par, xy, 0, 1);
	return (1);
}

int	main(int ac, char **av)
{
	char		**map;
	t_data		mlx;
	t_params	par;

	if (ac < 2)
		return (1);
	if (!ft_strnstr(av[1], ".ber", ft_strlen(av[1])))
	{
		ft_putstr_fd("Name of map is not valid\n", 1);
		return (0);
	}
	map = get_map(av[1]);
	if (!check_map(map))
		return (0);
	mlx.mlx_ptr = mlx_init();
	mlx.mlx_win = mlx_new_window(mlx.mlx_ptr, (ft_strlen(map[0]) * 40),
			(map_height(map) * 40), "So_long");
	draw_map(map, &mlx);
	par.map = map;
	par.mlx = &mlx;
	mlx_key_hook(mlx.mlx_win, key_press, &par);
	mlx_hook(mlx.mlx_win, 17, 0, exit_program, &mlx);
	mlx_loop_hook(mlx.mlx_ptr, move_enemy, &par);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
