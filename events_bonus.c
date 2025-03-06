/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 21:53:01 by vpogorel          #+#    #+#             */
/*   Updated: 2025/03/06 23:49:05 by vpogorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	key_arrow(int key, t_data *data)
{
	if (key == 65363)
	{
		data->real_min += 0.1 * data->zoom;
		data->real_max += 0.1 * data->zoom;
	}
	if (key == 65362)
	{
		data->imag_min += 0.1 * data->zoom;
		data->imag_max += 0.1 * data->zoom;
	}
	if (key == 65361)
	{
		data->real_min -= 0.1 * data->zoom;
		data->real_max -= 0.1 * data->zoom;
	}
	if (key == 65364)
	{
		data->imag_min -= 0.1 * data->zoom;
		data->imag_max -= 0.1 * data->zoom;
	}
}

int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free(data->s[0]);
	free(data->s[1]);
	free(data->s[2]);
	free(data->s);
	exit(1);
	return (0);
}

void	click_button(int x, int y, int button, t_data *data)
{
	data->fixed_x = data->real_min
		+ (data->real_max - data->real_min)
		* (x / (double)data->win_width);
	data->fixed_y = data->imag_max
		- (data->imag_max - data->imag_min)
		* (y / (double)data->win_height);
	data->fixated = 1;
	if (button == 3)
		data->t = style(data);
}

int	mouse_click(int button, int x, int y, t_data *data)
{
	long double	zoom_factor;
	long double	width;
	long double	height;

	click_button(x, y, button, data);
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
		data->zoom *= zoom_factor;
	}
	return (0);
}

int	key_press(int key, t_data *data)
{
	if (65307 == key)
	{
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_image(data->mlx, data->img);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		free(data->s[0]);
		free(data->s[1]);
		free(data->s[2]);
		free(data->s);
		exit(0);
	}
	key_arrow(key, data);
	return (0);
}
