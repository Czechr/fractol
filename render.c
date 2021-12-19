
#include "fract_ol.h"

void	my_pixelput(t_data img, int x, int y, int color)
{
	if (y < H && x < W)
		img.addr[y * W + x] = color;
}
