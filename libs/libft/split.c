/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/29 14:46:42 by tmercier      #+#    #+#                 */
/*   Updated: 2021/12/01 19:22:58 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* Allocates (with malloc) and returns an array
 * of strings obtained by splitting ’s’ using the
 * character ’c’ as a delimiter.  The array must be
 * i_ended by a NULL pointer.
 * Returns the array of new strings resulting from the split. */

#include "libft.h"

static char	**free_split(char **c)
{
	char	**s;

	s = c;
	while (*s)
		free(*s++);
	free(c);
	return (0);
}

static char	**alloc_split(const char *s, char c)
{
	int			i;
	const char	*tmp;

	if (!s)
		return (0);
	i = 0;
	tmp = s;
	while (*s)
	{
		tmp = s;
		while (*tmp && *tmp != c)
			tmp++;
		if (tmp != s)
		{
			i++;
			s = tmp;
		}
		while (*s && *s == c)
			s++;
	}
	return (ft_calloc(i + 1, sizeof(char *)));
}

char	**ft_split(char const *s, char c)
{
	char		**arr;
	char		**split;
	const char	*tmp;

	arr = alloc_split(s, c);
	if (!arr)
		return (0);
	split = arr;
	while (*s)
	{
		tmp = s;
		while (*tmp && *tmp != c)
			tmp++;
		if (tmp != s)
		{
			*arr = ft_substr(s, 0, tmp - s);
			if (!*arr++)
				return (free_split(split));
			s = tmp;
		}
		while (*s && *s == c)
			s++;
	}
	return (split);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s1)
		exit(EXIT_FAILURE);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (s1[end - 1] && ft_strchr(set, s1[end - 1]) && end > start)
		end--;
	return (ft_substr(s1, start, end - start));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*sub_str;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if (start > s_len)
		return (ft_strdup(""));
	if (len > s_len)
		len = s_len;
	sub_str = ft_malloc(sizeof(char *) * (len + 1));
	ft_strlcpy(sub_str, s + start, len + 1);
	return (sub_str);
}
