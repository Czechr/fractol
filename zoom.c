/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czak </var/mail/czak>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 09:20:50 by czak              #+#    #+#              */
/*   Updated: 2021/12/19 19:56:10 by czak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	zoom(int keys, int x, int y, t_data *img)
{

	if (keys == 5 || keys == 4)
	{
		if (keys== 5)
			img->zoom -= 0.1 * img->zoom;
		else
			img->zoom += 0.1 * img->zoom;
		mlx_clear_window(img->mlx, img->mlx_win);
		render(*img);
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	}
	return (0);
}

float	*render_julia(int type)
{
	float	*comx;

	comx = (float *)malloc(sizeof(float) * 2);
	if (type == 1)
	{
		comx[0] = -0.4;
		comx[1] = 0.6;
	}
	if (type == 2)
	{
		comx[0] = 0.285;
		comx[1] = 0;
	}
	return (comx);
}
