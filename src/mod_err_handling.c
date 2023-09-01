/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_err_handling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 12:29:56 by sqiu              #+#    #+#             */
/*   Updated: 2023/09/01 15:19:23 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod_err_handling.h"

void	ft_print_err_and_exit(t_err err, char *msg)
{
	printf("%s\n", msg);
	if (err == ERR_ARGCOUNT || err == ERR_EMPTYSTR || err == ERR_NONNUMERIC)
		printf("Correct input: ./philo \tnumber_of_philosophers \n\
			time_to_die \n\
			time_to_eat time_to_sleep \n\
			[number_of_times_each_philosopher_must_eat] 🐥\n");
	exit (err);
}
