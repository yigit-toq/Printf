/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytop <ytop@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:11:47 by ytop              #+#    #+#             */
/*   Updated: 2024/01/10 14:11:47 by ytop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>

int	ft_printf(const char *string, ...);

int	ft_putchar(char character, int *lenght);
int	ft_putstr(char *string, int	*lenght);

int	ft_signed_int(long number, int *lenght);

int	ft_pointer(size_t pointer, int *lenght);
int	ft_hexademical(size_t number, int *lenght, char c);
#endif