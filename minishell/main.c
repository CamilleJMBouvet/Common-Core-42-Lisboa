/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverissi <gverissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:16:26 by gverissi          #+#    #+#             */
/*   Updated: 2024/03/26 15:27:27 by gverissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "shell_handler/shell_handler.h"
#include "tokenizer/tokenizer.h"
#include "ast/ast.h"
#include "executer/executer.h"

// all-encompassing struct initiation
t_var	*var(void)
{
	static t_var	var;

	return (&var);
}

int	set_exit(int i, int flag)
{
	static int	code;

	if (flag == 1)
		code = i;
	return (code);
}

// main function
int	main(int ac, char **av, char **env)
{
	(void)ac;
	shell_start(av, env);
	signal_intercepter();
	while (1)
	{
		sig(0);
		var()->input = readline(PS1" ");
		if (!var()->input)
			break ;
		if (var()->input && *var()->input)
		{
			add_hist(var()->input);
			if (token_init() != -1)
			{
				ast_builder();
				execute_ast();
			}
			clean_all(0);
		}
	}
	clean_all(1);
	return (set_exit(1, 0));
}
