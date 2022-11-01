/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/16 19:23:58 by kblok         #+#    #+#                 */
/*   Updated: 2021/11/16 19:53:33 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *src, int c, size_t num)
{
	unsigned char	*ptr;
	size_t			idx;

	ptr = src;
	idx = 0;
	while (idx < num)
	{
		ptr[idx] = c;
		idx++;
	}
	return (src);
}
