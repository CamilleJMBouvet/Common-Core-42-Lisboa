/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 00:37:05 by cbouvet           #+#    #+#             */
/*   Updated: 2024/03/18 22:15:05 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTER_H
# define EXECUTER_H

// - LIBRARIES -
# include "../minishell.h"
# include "../shell_handler/shell_handler.h"
# include "../tokenizer/tokenizer.h"
# include "../ast/ast.h"

// - FUNCTIONS -
//-Executer-
void	execute_ast(void);
void	set_in_out(t_ast *node);
void	launch_pid(int builtin, t_ast *node);
void	parent_pid(void);
//-Command execution-
void	cmd_exec(t_ast *node);
char	*get_path(char *cmd);
//-Builtin-
int		is_builtin(char *cmd);
void	builtin_exec(t_ast *node, int builtin);
int		is_pipe(void);
//-echo-
void	builtin_echo(t_ast *node);
int		find_n_flag(char **args);
char	**merge_args(t_ast *node);
//-cd-
void	builtin_cd(t_ast *node);
int		cd_errors(t_ast *node);
void	edit_pwd_oldpwd(void);
//pwd
void	builtin_pwd(t_ast *node);
//export
void	builtin_export(t_ast *node);
void	print_export(t_ast *node);
int		valid_identifier(char *arg);
char	**update_env(char **new_env, char *arg);
void	edit_export(char *arg, int flag);
//unset
void	builtin_unset(t_ast *node);
int		remove_vars(void);
//env
void	builtin_env(t_ast *node);
//exit
void	builtin_exit(t_ast	*node);
int		exit_arg_err(t_ast *node);
int		arg_is_digit(char *str);
//Utils

int		valid_keyname(char *key);
int		find_index(char *key);
char	**add_env(char **new_env, char *arg);
void	cpy_env(char **new_env);

#endif
