/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 15:28:21 by sqiu              #+#    #+#             */
/*   Updated: 2023/09/15 17:42:34 by sqiu             ###   ########.fr       */
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
 * @return err		ERR_MALLOC, ERR_ZEROINPUT, ERR_OVERFLOW, ERR_NEGATIVINPUT,
 * 					ERR_MUTEX_INIT, SUCCESS
 */
t_err	ft_setup(int argc, char **argv, t_input *params, t_meta *data)
{
	t_err	err;

	err = ft_convert_str_to_num(argv[1], &params->num_philos);
	if (err != SUCCESS)
		return (err);
	err = ft_convert_str_to_num(argv[2], &params->time_to_die);
	if (err != SUCCESS)
		return (err);
	err = ft_convert_str_to_num(argv[3], &params->time_to_eat);
	if (err != SUCCESS)
		return (err);
	err = ft_convert_str_to_num(argv[4], &params->time_to_sleep);
	if (err != SUCCESS)
		return (err);
	err = ft_setup2(argc, argv, params, data);
	return (err);
}

/**
 * @brief Continuation of setup.
 * 
 * @param argc 		Amout of input arguments.
 * @param argv 		Array of strings containing the arguments.
 * @param params 	Struct to save and provide input parameters to the program.
 * @param data 		Struct with metadata of the program.
 * @return err		ERR_MALLOC, ERR_ZEROINPUT, ERR_OVERFLOW, ERR_NEGATIVINPUT,
 * 					ERR_MUTEX_INIT, SUCCESS
 */
t_err	ft_setup2(int argc, char **argv, t_input *params, t_meta *data)
{
	t_err	err;

	err = SUCCESS;
	if (argc == 6)
	{
		err = ft_convert_str_to_num(argv[5], &params->req_meals);
		if (err != SUCCESS)
			return (err);
		params->check_meals = true;
	}
	else
	{
		params->req_meals = -1;
		params->check_meals = false;
	}
	if (params->num_philos == 0 || params->time_to_die == 0
		|| params->req_meals == 0)
		return (ft_print_err(ERR_ZEROINPUT, \
		"Number of philos, time_to_die or number of eats cannot be 0. 😘\n"));
	if (ft_init_var(data, params) != SUCCESS)
		return (ERR_MALLOC);
	if (ft_init_mutexes(data) != SUCCESS)
		return (ERR_MUTEX_INIT);
	return (SUCCESS);
}

/**
 * @brief Converts input string into numerical value and performs further checks
 * on this basis.
 * 
 * @param str 		Given string.
 * @param num	 	Numerical value to be set.
 * @return t_err	ERR_OVERFLOW, ERR_NEGATIVINPUT, SUCCESS
 */
t_err	ft_convert_str_to_num(char *str, int *num)
{
	long	buf;

	buf = ft_atoi(str);
	if (buf < -2147483648 || buf > 2147483647)
		return (ft_print_err(ERR_OVERFLOW, \
		"Input value larger than int. 😩\n"));
	if (buf < 0)
		return (ft_print_err(ERR_NEGATIVINPUT, \
		"No negative values accepted. 💀\n"));
	*num = (int)buf;
	return (SUCCESS);
}

/**
 * @brief Reserves memory for program variables and
 * intialises them.
 * 
 * @param data 			Struct with metadata of the program.
 * @param params 		Struct to save and provide input parameters to the program.
 * @return err			ERR_MALLOC, SUCCESS
 */
t_err	ft_init_var(t_meta *data, t_input *params)
{
	data->philos = (t_philo *)ft_calloc(params->num_philos, \
		sizeof(t_philo));
	if (!data->philos)
		return (ft_err_malloc());
	ft_init_values(data, params);
	return (SUCCESS);
}

/**
 * @brief Sets variables to initiate values.
 * 
 * Set Boolean speak to true.
 * Assign philosopher ID starting from 1 to amount of philosophers.
 * The right forks are given the address of the left fork of the
 * following philospher (left fork already malloced inside philospher).
 * The last philosopher receives the address of the first philosophers
 * left fork.
 * Status, last_meal and meal_count are already set to 0.
 * @param data 			Struct with metadata of the program.
 * @param params 		Struct to save and provide input parameters to the program.
 */
void	ft_init_values(t_meta *data, t_input *params)
{
	int	i;

	data->speak = true;
	i = -1;
	while (++i < params->num_philos)
	{
		data->philos[i].id = i + 1;
		if (i == params->num_philos - 1)
			data->philos[i].right_fork = &data->philos[0].left_fork;
		else
			data->philos[i].right_fork = &data->philos[i + 1].left_fork;
		data->philos[i].params = params;
		data->philos[i].speak = &data->speak;
		data->philos[i].mtx_speak = &data->mtx_speak;
	}
}
