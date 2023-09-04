/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 15:28:21 by sqiu              #+#    #+#             */
/*   Updated: 2023/09/04 19:23:01 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file mod_setup.c
 * @brief Functions to prepare the program for its task to simulate the table
 * of philosphers.
 */

#include "mod_setup.h"

/**
 * @brief Sets input parameters and verifies their validity.
 * 
 * @param argc 		Amout of input arguments.
 * @param argv 		Array of strings containing the arguments.
 * @param params 	Struct to save and provide input parameters to the program.
 * @param data 		Struct with metadata of the program.
 */
void	ft_setup(int argc, char **argv, t_input *params, t_meta *data)
{
	params->num_philos = ft_convert_str_to_num(argv[1]);
	params->time_to_die = ft_convert_str_to_num(argv[2]);
	params->time_to_eat = ft_convert_str_to_num(argv[3]);
	params->time_to_sleep = ft_convert_str_to_num(argv[4]);
	if (argc == 6)
		params->req_meals = ft_convert_str_to_num(argv[5]);
	if (params->num_philos == 0 || params->time_to_die == 0)
		ft_print_err_and_exit(ERR_ZEROINPUT, \
		"Number of philosophers and time_to_die cannot be 0. 😘 \n");
	ft_initiate(data, params->num_philos);
}

/**
 * @brief Converts input string into numerical value and performs further checks
 * on this basis.
 * 
 * @param str 	Given string.
 * @return int 	Numerical value to be returned.
 */
int	ft_convert_str_to_num(char *str)
{
	long	buf;

	buf = ft_atoi(str);
	if (buf < -2147483648 || buf > 2147483647)
		ft_print_err_and_exit(ERR_OVERFLOW, \
		"Input value larger than int. 😩\n");
	if (buf < 0)
		ft_print_err_and_exit(ERR_NEGATIVINPUT, \
		"No negative values accepted. 💀\n");
	return ((int)buf);
}

void	ft_initiate(t_meta *data, int num_philos)
{
	data->philos = ft_calloc(num_philos, sizeof(t_philo));
	if (!data->philos)
		ft_err_malloc(data);
}