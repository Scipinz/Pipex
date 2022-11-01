/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_striteri.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/16 19:38:35 by kblok         #+#    #+#                 */
/*   Updated: 2021/11/16 19:38:44 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *str, void (*f)(unsigned int, char*))
{
	int	idx;

	idx = 0;
	if (!str)
		return ;
	while (str[idx])
	{
		(*f)(idx, &str[idx]);
		idx++;
	}
}
