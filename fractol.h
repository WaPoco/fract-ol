/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 10:30:17 by vpogorel          #+#    #+#             */
/*   Updated: 2025/01/19 15:31:34 by vpogorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include </home/vasili/Documents/minilibx-linux/mlx.h>
# include <stdio.h>

typedef struct s_data {
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			win_width;
	int			win_height;
	long double	Zoom;
	long double	real_min;
	long double	real_max;
	long double	imag_max;
	long double	imag_min;
	long double	fixed_x;
	long double	fixed_y;
	int			fixated;
}              t_data;

typedef struct s_complex
{
	long double	realpart;
	long double	imagpart;	
}	t_complex;

long double	complex_real(t_complex z);
long double	complex_imag(t_complex z);
t_complex		multiply(t_complex z1, t_complex z2);
t_complex		add(t_complex z1, t_complex z2);
long double complex_abs(t_complex z);
int	create_trgb(int t, int r, int g, int b);

#endif