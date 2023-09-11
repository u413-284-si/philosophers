/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 19:35:18 by sqiu              #+#    #+#             */
/*   Updated: 2023/09/11 17:05:07 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file main.c
 * @brief Contains initial thread executing the main routine.
 */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_input	params;
	t_meta	data;

	ft_check_input(argc, argv);
	ft_setup(argc, argv, &params, &data);
	ft_feast(&data);
	if (ft_check_for_dead(data.philos))
		printf("Another one bites the dust. 😵\n");
	if (ft_all_fed(data.philos))
		printf("Ich bin so satt, ich mag kein Blatt. 🐐 \n");
	ft_cleanup(&data);
	return (0);
}
