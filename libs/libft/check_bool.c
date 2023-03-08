/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_bool.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/29 14:43:49 by tmercier      #+#    #+#                 */
/*   Updated: 2022/12/18 16:38:00 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	is_negative(int n)
{
	if ((long int)n < 0)
		return (true);
	return (false);
}

bool	is_space(int c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

bool	char_is_found(int c, char const *s)
{
	while (*s)
	{
		if (c == *s)
			return (true);
		s++;
	}
	return (false);
}

bool	is_odd(int i)
{
	return (i & 1);
}

/* 

If the least significant bit of a binary 
number is 1 then it is odd; for 0 it will be even. 
So, by doing AND with 1 we are removing all other 
bits except for the least significant bit, i.e.:

     55  ->  0 0 1 1 0 1 1 1     input
(&)   1  ->  0 0 0 0 0 0 0 1      mask
---------------------------------------
      1  <-  0 0 0 0 0 0 0 1    output

*/
