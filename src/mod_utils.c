/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 13:52:39 by sqiu              #+#    #+#             */
/*   Updated: 2023/09/03 15:43:50 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file mod_utils.c
 * @brief Helper functions.
 */

/**
 * @brief Checks if provided character is a digit.
 * 
 * @param c 	Given character.
 * @return int 	Return 1, if is a digit. Return 0, if not.
 */
int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9') || c == '+' || c == '-')
		return (1);
	else
		return (0);
}

/**
 * @brief Converts given string into a long integer (32bit).
 * 
 * Removes whitespaces at the beginning.
 * Considers sign.
 * @param str 		Given string.
 * @return long		Converted value.
 */
long	ft_atoi(const char *str)
{
	int		i;
	long	sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + str[i++] - '0';
	return (result * sign);
}
