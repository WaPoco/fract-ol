/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 12:20:11 by vpogorel          #+#    #+#             */
/*   Updated: 2025/01/18 12:20:31 by vpogorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

long double creal(complex z)
{
    return (z.imagpart);
}

long double cimag(complex z)
{
    return (z.realpart);
}
complex multiply(complex z1, complex z2)
{
    complex result;

    result.realpart = z1.realpart * z2.realpart - z1.imagpart * z2.imagpart;
    result.imagpart = z2.imagpart * z1.realpart + z1.imagpart * z2.realpart;
    return (result);
}
complex add(complex z1, complex z2)
{
    complex result;

    result.realpart = z1.realpart + z2.realpart;
    result.imagpart = z1.imagpart + z2.imagpart;
    return (result);
}
long double abs(complex z)
{
    long double distanc;

    distanc = z.imagpart * z.imagpart + z.realpart * z.realpart;
    return (distanc);
}