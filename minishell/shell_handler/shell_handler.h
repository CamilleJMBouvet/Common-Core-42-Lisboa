/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_handler.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverissi <gverissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:39:25 by cbouvet           #+#    #+#             */
/*   Updated: 2024/03/26 14:33:41 by gverissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_HANDLER_H
# define SHELL_HANDLER_H

// - LIBRARIES
# include "../minishell.h"
# include "../tokenizer/tokenizer.h"
# include "../ast/ast.h"
# include "../executer/executer.h"

// - CONSTANTS -
# define LINE	"\033[1;36m-------------------- \033[0m"
# define CONFIG	"/.config"
# define RDL_SUPPR "/readline.supp"

// - FUNCTIONS -
//-Signals-
void	sig(int flag);
void	handle_sig(int sig);
void	handle_fork_sig(int sig);
void	fork_heredoc(int sig);
void	signal_intercepter(void);
int		ctrld_heredoc(char *buffer, char *delimiter);
//-Shell start-
void	shell_start(char **av, char **env);
char	*check_config(void);
void	set_config(char *config_file);
void	dlist_config(char *line, int config_fd, char flag);
//-Basic shell variables-
void	set_basic_vars(char **av);
int		vlgr_launch(char **av);
void	set_vlgr_vars(void);
//-Environment-
void	set_env(char **env, char *config_file, int env_i);
void	set_shlvl(char *config_file, int env_i);
void	edit_start_env(int env_i);
int		index_nb(char **arr);
//-dlist management-
t_dlist	*new_dlist_node(char *str, int op);
void	addback_dlist(t_dlist **dlist, t_dlist *new);
void	addascii_dlist(t_dlist **dlist, t_dlist *new);
void	insert_dlist(t_dlist **dlist, t_dlist *ptr, t_dlist *new);
void	rm_dlist(t_dlist **dlist, t_dlist *ptr);
//-History & export lists-
void	add_hist(char *cmd);
int		count_hist(void);
void	set_export(char *config_file);
char	*export_str(char *str);
int		first_occur(char *str, char c);
//-Reboot-
void	shell_reboot(void);
void	launch_reboot(char **new_env);
void	write_config(void);
void	reboot_err(int error);
//-Cleaning-
void	clean_all(int code);
void	free_dlist(t_dlist **dlist);
void	free_ast(t_ast **ast);
void	free_matrix(char **args);
void	close_fds(int in, int out);

#endif
