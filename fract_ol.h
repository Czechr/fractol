/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czak </var/mail/czak>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 21:00:41 by czak              #+#    #+#             */
/*   Updated: 2021/12/19 19:55:17 by czak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# define WIDTH 500
# define HEIGHT 500
# define MAX 1000
# define MENU "- Mandelbrot\n- julia\n"
# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include<stdio.h>
# include <unistd.h>
# include "keys.h"

typedef struct s_data {
	void	*img;
	int		*addr;
	double	zoom;
	void	*mlx;
	void	*mlx_win;
	int		x;
	int		y;
	double	a;
	double	b;
	int		type;
	int		julia;
	int		couleur;
}				t_data;

void	draw(t_data img, int x, int y, int color);
int		zoom(int keycode, int x, int y, t_data *img);
void	render(t_data img);
t_data	init(int zid);
float	*render_julia(int type);
int	    check(int ac, char **av, t_data *img);

#endif
