
#ifndef FRACT_OL_H
# define FRACT_OL_H

# define MENU "- Mandelbrot\n- Julia\n"
# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include<stdio.h>
# include <unistd.h>

#define ESC 53
#define LMB 4


# define MAX_ITER 1000
# define H 1000
# define W 1000


typedef struct s_data {
	void	*img;
	int		*addr;
	double	zoom;
	void	*mlx;
	void	*mlx_win;
	int		x;
	int		y;
	int		type;
	int		julia_set;
	int		couleur;
}				t_data;

void	my_pixelput(t_data img, int x, int y, int color);
int		zoom(int keycode, int x, int y, t_data *img);
void	render(t_data img);
t_data	init(int zid);
int 	close(int keys);
float	*render_julia(int type);
int	    check(int argc, char **argv, t_data *img);

#endif
