/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_err_handling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 12:29:56 by sqiu              #+#    #+#             */
/*   Updated: 2023/09/15 17:57:47 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file mod_err_handling.c
 * @brief Functions to react to errors and exceptions.
 */

#include "mod_err_handling.h"

/**
 * @brief Prints the provided error message.
 * 
 * Optionally prints out instruction on program usage in case of user errors.
 * @param err 			Given error code.
 * @param msg 			Given error message.
 * @return err
 */
t_err	ft_print_err(t_err err, char *msg)
{
	printf("%s\n", msg);
	if (err == ERR_ARGCOUNT || err == ERR_EMPTYSTR || err == ERR_NONNUMERIC
		|| err == ERR_NEGATIVINPUT)
		printf("Correct input: ./philo \tnumber_of_philosophers \n\
			time_to_die \n\
			time_to_eat \n\
			time_to_sleep \n\
			[number_of_times_each_philosopher_must_eat] 🐥\n");
	return (err);
}

/**
 * @brief Handles error case when malloc failed.
 * 
 * Prints error message.
 * Calls cleanup function to free reserved memory.
 * @param data 	Struct with metadata of the program.
 * @return err	ERR_MALLOC
 */
t_err	ft_err_malloc(void)
{
	printf("Malloc encountered an error. System reset initialised.\n");
	return (ERR_MALLOC);
}

/**
 * @brief Handles error case when mutex init failed.
 * 
 * Prints error message.
 * Calls cleanup function to free reserved memory.
 * @param data 	Struct with metadata of the program.
 * @return err	ERR_MUTEX_INIT
 */
t_err	ft_err_mutex_init(t_meta *data)
{
	printf("Mutex init encountered an error. System reset initialised.\n");
	ft_cleanup(data);
	return (ERR_MUTEX_INIT);
}

/**
 * @brief Handles error case when thread creation failed.
 * 
 * Prints error message.
 * Calls cleanup function to free reserved memory.
 * @param data 			Struct with metadata of the program.
 * @param curr_index	Index of the thread whose creation failed.
 * @return err	ERR_THREAD_CREATE
 */
t_err	ft_err_thread_create(t_meta *data, int curr_index)
{
	printf("Thread creation encountered an error. System reset initialised.\n");
	ft_stop_join_threads(data, curr_index);
	ft_cleanup(data);
	return (ERR_THREAD_CREATE);
}

/**
 * @brief Set the status of created philos to DEAD and afterwards join them.
 * 
 * @param data 			Struct with metadata of the program.
 * @param curr_index 	Index of the thread whose creation failed.
 */
void	ft_stop_join_threads(t_meta *data, int curr_index)
{
	int	tmp;

	tmp = curr_index;
	while (--tmp >= 0)
		ft_set_status(&data->philos[tmp], DEAD);
	while (--curr_index >= 0)
		if (pthread_join(data->philos[curr_index].thread, NULL) != 0)
			printf("Failed to join thread %d.\n", data->philos[curr_index].id);
}
