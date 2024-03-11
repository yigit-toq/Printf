/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_words.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytop <ytop@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:11:55 by ytop              #+#    #+#             */
/*   Updated: 2024/01/10 14:11:55 by ytop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putchar(char character, int *lenght)
{
	int	error;

	error = write(1, &character, 1);
	if (error == 1)
		*lenght += 1;
	return (error);
}

int	ft_putstr(char *string, int	*lenght)
{
	int	index;
	int	error;

	index = 0;
	if (!string)
	{
		error = write(1, "(null)", 6);
		if (error > 0)
			*lenght += 6;
		return (error);
	}
	while (string[index])
	{
		if (ft_putchar(string[index++], lenght) == -1)
			return (-1);
	}
	return (1);
}

int	ft_signed_int(long number, int *lenght)
{
	if (number < 0)
	{
		if (ft_putchar(45, lenght) == -1)
			return (-1);
		number = -number;
	}
	if (number < 10)
	{
		if (ft_putchar(number + 48, lenght) == -1)
			return (-1);
	}
	if (number >= 10)
	{
		if (ft_signed_int(number / 10, lenght) == -1)
			return (-1);
		ft_signed_int(number % 10, lenght);
	}
	return (1);
}

int	ft_hexademical(size_t number, int *lenght, char c)
{
	char	string[25];
	char	*character;
	int		index;

	index = 0;
	if (c == 'x')
		character = "0123456789abcdef";
	else
		character = "0123456789ABCDEF";
	if (!number)
	{
		if (ft_putchar('0', lenght) == -1)
			return (-1);
	}
	while (number)
	{
		string[index++] = character[number % 16];
		number /= 16;
	}
	while (index--)
	{
		if (ft_putchar(string[index], lenght) == -1)
			return (-1);
	}
	return (1);
}

int	ft_pointer(size_t pointer, int *lenght)
{
	if (ft_putstr("0x", lenght) == -1)
		return (-1);
	return (ft_hexademical(pointer, lenght, 'x'));
}
