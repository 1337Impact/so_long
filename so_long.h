/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 13:22:59 by mbenkhat          #+#    #+#             */
/*   Updated: 2022/01/02 19:24:30 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <mlx.h>
# include "libft/libft.h"

typedef struct s_data
{
	void	*mlx_ptr;
	void	*mlx_win;
}			t_data;

typedef struct s_xy
{
	int	x;
	int	y;
}			t_xy;

typedef struct s_params {
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
	t_data	*mlx;
}			t_params;

char	**get_map(char *file);
int		check_map(char **map);
int		map_height(char **map);
t_xy	get_char(char **map, char c);
int		exit_program(t_data *mlx);

#endif