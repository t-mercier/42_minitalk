/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/29 14:46:30 by tmercier      #+#    #+#                 */
/*   Updated: 2021/11/29 14:46:31 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(long n, int radix, int fd)
{
	unsigned char	c;

	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n / radix)
		ft_putnbr_fd(n / radix, radix, fd);
	if ((n % radix) < 10)
		c = (n % radix) + '0';
	else
		c = (n % radix) + 'a' + 10;
	write(fd, &c, 1);
}

void	ft_putulong_fd(unsigned long n, int radix, int fd)
{
	unsigned char	c;

	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n / radix)
		ft_putulong_fd(n / radix, radix, fd);
	if ((n % radix) < 10)
		c = (n % radix) + '0';
	else
		c = (n % radix) + 'a' + 10;
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	len;

	if (!s)
		return ;
	len = ft_strlen(s);
	write(fd, s, len);
}

void	ft_putstr_color(char *s, int c)
{
	int				i;
	const t_color	clr[6] = {
	{'r', RED},
	{'g', GREEN},
	{'b', BLUE},
	{'y', YELLOW},
	{'c', CYAN},
	{'m', MAGENTA}};

	if (!s)
		exit_message("ERROR [ empty string ]\n", 1);
	i = 6;
	while (i--)
	{
		if (clr[i].color == c)
			ft_printf("%s%s", clr[i].code, s);
	}
}
