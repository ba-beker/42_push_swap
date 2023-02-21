/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobabeke <mobabeke@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 11:38:48 by mobabeke          #+#    #+#             */
/*   Updated: 2023/02/20 19:32:06 by mobabeke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "src/libft/libft.h"
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

void	serverinfo(int n, siginfo_t *info, void *ucontext);
int		conversion(char c, int pid, int i);
void	signal_recive(int n);
#endif
