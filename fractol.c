/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 10:30:13 by vpogorel          #+#    #+#             */
/*   Updated: 2025/01/21 19:31:45 by vpogorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
	return (0);
}

static int	mouse_click(int button, int x, int y, t_data *data)
{
	long double	zoom_factor;
    long double	width;
    long double	height;

    if (button == 1) // Left Click to Fix Point
    {
        data->fixed_x = data->real_min + (data->real_max - data->real_min) * (x / (double)data->win_width);
        data->fixed_y = data->imag_max - (data->imag_max - data->imag_min) * (y / (double)data->win_height);
        data->fixated = 1;
    }
	/*
	if (button == 2)
	{
		mat	
	}*/
	ft_printf("%d\n", button);
    if ((button == 4 || button == 5) && data->fixated)
    {
        if (button == 4)
			zoom_factor = 0.9;
		else
			zoom_factor = 1.1;
        width = (data->real_max - data->real_min) * zoom_factor;
        height = (data->imag_max - data->imag_min) * zoom_factor;
        data->real_min = data->fixed_x - width / 2;
        data->real_max = data->fixed_x + width / 2;
        data->imag_min = data->fixed_y - height / 2;
        data->imag_max = data->fixed_y + height / 2;
        data->Zoom *= zoom_factor;
    }
    return (0);
}
static int	key_press(int key, t_data *data)
{
	if(65307 == key)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	if (key == 65361)
		data->c.realpart -= 0.01;
	if (key == 65362)
		data->c.imagpart += 0.01;
	if (key == 65363)
		data->c.realpart += 0.01;
	if (key == 65364)
		data->c.imagpart -= 0.01;
	return (0);
}
int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
static void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

static int iteration(t_complex z_0, t_complex c)
{
    int     i;

    i = 0;
    if (complex_abs(z_0)>= 4.0)
        return create_trgb(0, (i * 2) % 256, (i * 2) % 256, (i * 20) % 256);
    while (i < 50)
    {
        z_0 = add(multiply(z_0, z_0), c);
        if (complex_abs(z_0)>= 4.0)
            return create_trgb(0, (i * 1) % 256, (i * 20) % 256, (i * 20) % 256);
        i++;
    }
    return create_trgb(0, 0, 0, 0);
}

static void	create_img(t_data *data, t_complex p, int x, int y)
{
	int			color;

	if (data->option == '1')
	{
		data->c.realpart = 0;
		data->c.imagpart = 0;
		color = iteration(data->c, p);
		my_mlx_pixel_put(data, x, y, color);
		return ;
	} 
	color = iteration(p, data->c);
	my_mlx_pixel_put(data, x, y, color);
}

static int	render_next_frame(t_data *data)
{
	long double	d[2];
	int			i;
	int			k;
	t_complex		p;

	mlx_clear_window(data->mlx, data->win);
	d[0] = (data->real_max - data->real_min) / data->win_width;
	d[1] = (data->imag_max - data->imag_min) / data->win_height;
	i = 0;
	while (i < data->win_width)
	{
		k = 0;
		while (k < data->win_height)
		{
			p.realpart = data->real_min + d[0] * i;
			p.imagpart = data->imag_max - d[1] * k;
			create_img(data, p, i, k);
			k++;
		}
		i++;
	}
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}

static void	show_options(t_data *data, int args0, char **args)
{
	if ((args0 == 2 ) && (ft_strlen(args[1]) == 1) && (args[1][0] == '1' || args[1][0] == '2' || args[1][0] == '3'))
	{
		data->option = args[1][0];
		if (data->option == '1')
		{
			data->c.realpart = 0;
			data->c.imagpart = 0;
		} else if (data->option == '2')
		{
			data->c.realpart = 0.5;
			data->c.imagpart = 0.55;
		} else if (data->option == '3')
		{
			data->c.realpart = 0;
			data->c.imagpart = -1;		
		}
		return ;
	}
	ft_printf("Choose a fractal!\n1: Mandelbrot \n2: Julia c=(0.5,0.55)\n3: Julia c=(0,-1)\n");
	exit(0);
}

int	main(int args0, char **args)
{
	t_data data;

	show_options(&data, args0, args);
	data.win_height = 1000;
	data.win_width  = 1000;
	data.imag_min = -2;
	data.imag_max = 2;
	data.real_min = -2;
	data.real_max = 2;
	data.Zoom = 1;
	data.fixated = 0;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, data.win_width, data.win_height, "Fractol");
	data.img = mlx_new_image(data.mlx, data.win_width, data.win_height);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
	mlx_hook(data.win, 2, 1L<<0, key_press, &data);
	mlx_hook(data.win, 4, 1L<<2, mouse_click, &data);
	mlx_hook(data.win, 17, 1L<<17, close_window, &data);
	mlx_loop_hook(data.mlx, render_next_frame, &data);
	mlx_loop(data.mlx);
	return (0);
}
