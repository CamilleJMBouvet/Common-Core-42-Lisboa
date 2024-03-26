/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 20:41:00 by cbouvet           #+#    #+#             */
/*   Updated: 2024/03/18 22:14:44 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

// - LIBRARIES-
# include "../minishell.h"
# include "../shell_handler/shell_handler.h"
# include "../tokenizer/tokenizer.h"
# include "../executer/executer.h"

// -CONSTANTS -
# define HDOC	"/.heredoc"

// - FUNCTIONS -
//-AST builder-
void	ast_builder(void);
t_ast	*new_node(t_dlist *token, int flag);
t_ast	*last_node(void);
void	insert_node(t_ast *new);
void	insert_lone_node(t_dlist *token);
//-Redir nodes-
void	search_back(t_dlist *token, t_ast *node, int fifo);
void	search_front(t_dlist *token, t_ast *node, int fifo);
t_redir	*new_redir(t_dlist *token, t_ast *node);
t_redir	*del_redir(t_redir *redir);
//-Fds opening-
void	open_fds(t_ast *node, t_redir *new);
void	open_in_fd(t_redir *new);
void	set_heredoc(t_redir *new, char *heredoc);
//-Utils
int		init_fds(t_dlist *token, t_ast *new, int flag);
void	make_args(t_dlist *token, t_ast *new, int flag);
int		filename_size(t_dlist *token);
void	multiple_files(t_ast *node, t_redir *new);
void	populate_args(t_dlist *token, t_ast *new);
#endif
