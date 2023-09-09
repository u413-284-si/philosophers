/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_err_handling.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 12:30:29 by sqiu              #+#    #+#             */
/*   Updated: 2023/09/09 12:44:46 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOD_ERR_HANDLING_H
# define MOD_ERR_HANDLING_H

/* ====== LIBRARIES ====== */

# include <stdlib.h>
# include <stdio.h>
# include <errno.h>

# include "metadata.h"

/* ====== DEFINITIONS ====== */

typedef enum e_err{
	SUCCESS,
	ERR_ARGCOUNT,
	ERR_EMPTYSTR,
	ERR_NONNUMERIC,
	ERR_OVERFLOW,
	ERR_NEGATIVINPUT,
	ERR_ZEROINPUT,
	ERR_MALLOC,
	ERR_MUTEX_INIT,
	ERR_MUTEX_DESTROY,
	ERR_THREAD_CREATE
}	t_err;

/* ====== DECLARATIONS ====== */

void	ft_print_err_and_exit(t_err err, char *msg);
void	ft_err_malloc(t_meta *data);
void	ft_err_mutex_init(t_meta *data);
void	ft_err_thread_create(t_meta *data);


//import from module cleanup
void	ft_cleanup(t_meta *data);

#endif
