/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_err_handling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 12:29:56 by sqiu              #+#    #+#             */
/*   Updated: 2023/09/04 19:31:01 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file mod_err_handling.c
 * @brief Functions to react to errors and exceptions.
 */

#include "mod_err_handling.h"

/**
 * @brief Prints the provided error message and exits with the given error code.
 * 
 * Optionally prints out instruction on program usage in case of user errors.
 * @param err 	Given error code.
 * @param msg 	Given error message.
 */
void	ft_print_err_and_exit(t_err err, char *msg)
{
	printf("%s\n", msg);
	if (err == ERR_ARGCOUNT || err == ERR_EMPTYSTR || err == ERR_NONNUMERIC
		|| err == ERR_NEGATIVINPUT)
		printf("Correct input: ./philo \tnumber_of_philosophers \n\
			time_to_die \n\
			time_to_eat \n\
			time_to_sleep \n\
			[number_of_times_each_philosopher_must_eat] 🐥\n");
	exit (err);
}

/**
 * @brief Handles error case when malloc failed.
 * 
 * Prints error message.
 * Calls cleanup function to free reserved memory.
 * @param data 	Struct with metadata of the program.
 */
void	ft_err_malloc(t_meta *data)
{
	printf("Malloc encountered an error. System reset initialised.\n")
	ft_cleanup(data);
	exit(ERR_MALLOC);
}
