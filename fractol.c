/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czak </var/mail/czak>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 23:52:32 by czak              #+#    #+#             */
/*   Updated: 2021/12/19 20:00:02 by czak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "fract_ol.h"

int	mandel_brot(float x_axis, float y_axis)
{
	int		iteration;
	float	x;
	float	y;
	float	x_new;
	float	y_new;

	iteration = 0;
	x = 0;
	y = 0;
	x_new = (x * x) - (y * y) + x_axis;
	y_new = (2 * x * y) + y_axis;
	while (x * x + y * y < 4 && iteration < MAX)
	{
		iteration++;
		x = x_new;
		y = y_new;
		x_new = (x * x) - (y * y) + x_axis;
		y_new = (2 * x * y) + y_axis;
	}
	if (iteration == MAX)
		return (0x000000);
	else
		return (0x53371 + iteration * exp(15));
}

int	julia(float x_axis, float y_axis, float *c)
{
	int		iteration;
	float	x;
	float	y;
	float	x_new;
	float	y_new;

	iteration = 0;
	x = x_axis;
	y = y_axis;
	while (x * x + y * y < 4 && iteration < MAX)
	{
		iteration++;
		x_new = (x * x) - (y * y) + c[0];
		y_new = (2 * x * y) + c[1];
		x = x_new;
		y = y_new;
	}
	if (iteration == MAX)
		return (0x000000 * 10);
	else
		return (0x727760 + iteration * exp(10));
}

void	render(t_data img)
{
	int		i;
	int		j;
	float	x;
	float	y;
	float	*c;

	i = -1;
	c = render_julia(img.julia);
	while (++i < WIDTH)
	{
		j = -1;
		while (++j < HEIGHT)
		{
			x = (((float)i * img.zoom) / WIDTH) - (img.zoom / 2) + img.a;
			y = (((float)j * img.zoom) / HEIGHT) - (img.zoom / 2) + img.b;
			if (img.type == 2)
				draw(img, i, j, mandel_brot(x, y));
			if (img.type == 1)
				draw(img, i, j, julia(x, y, c));
		}
	}
	free(c);
}

int	main(int ac, char **av)
{
	int		add;
	t_data	img;

	add = 0;
	img = init(add);
	if (check(ac, av, &img))
		return (printf(MENU));
	mlx_mouse_hook(img.mlx_win, zoom, &img);
	render(img);
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	mlx_loop(img.mlx);
	return (1);
}
