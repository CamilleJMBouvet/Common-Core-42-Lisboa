/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverissi <gverissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:32:50 by cbouvet           #+#    #+#             */
/*   Updated: 2024/03/26 14:33:18 by gverissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// - LIBRARIES -
//-External-
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <string.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>
# include "libft/libft.h"

// - GLOBAL VARIABLE -
extern int	g_exitv;

// - CONSTANTS -
# define PS1			"\001\033[1;36m\002> GC-Shell~$\001\033[0m\002"
# define VAR_LEN		10000

// - STRUCTS -
//-Node type struct-
typedef enum e_etype
{
	AST_COMMAND,
	AST_FILE,
	AST_PIPE,
	AST_REDIR_IN,
	AST_REDIR_OUT,
	AST_REDIR_APPEND,
	AST_REDIR_HEREDOC,
	ERR,
}	t_etype;

typedef struct s_dlist
{
	t_etype			type;
	char			*content;
	struct s_dlist	*prev;
	struct s_dlist	*next;
}	t_dlist;

typedef struct s_redir
{
	t_etype	type;
	char	**filename;
	int		fd;
}	t_redir;

typedef struct s_ast
{
	t_etype			type;
	char			*value;
	char			**args;
	int				pid;
	int				pipe[2];
	int				in_out[2];
	t_redir			*in;
	t_redir			*out;
	struct s_ast	*prev;
	struct s_ast	*next;
}	t_ast;

//-General variables & data struct-
typedef struct s_var
{
	char	pgr[8][10000];
	char	*input;
	char	shell_path[10000];
	char	**env;
	t_dlist	*exp;
	t_dlist	*hist;
	t_dlist	*tokens;
	t_ast	*ast;
}	t_var;

// - FUNCTIONS -
t_var	*var(void);
int		set_exit(int i, int flag);
#endif
