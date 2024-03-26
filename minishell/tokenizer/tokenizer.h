/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:26:02 by cbouvet           #+#    #+#             */
/*   Updated: 2024/03/18 22:15:30 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

# include "../minishell.h"
# include "../shell_handler/shell_handler.h"
# include "../ast/ast.h"
# include "../executer/executer.h"

// -FUNCTIONS-
//-Token handling-
t_dlist	*last_tok(void);
t_dlist	*start_segment(t_dlist *token, int flag);
t_dlist	*end_segment(t_dlist *token);
t_etype	get_type(char *content, int op);
int		tok_err(void);
//-Tokenizer-
int		token_init(void);
int		tokenize_word(int start);
int		tokenize_op(int start);
int		find_token_end(int start);
void	expanded_cmd(char *new);
//-Expansions-
char	*send_exp(char *str, char quote, int i);
int		expan(char *str, char tmp[1][VAR_LEN], int j, int end);
int		dollar_sign(char *str, int i, int end, char quote);
char	*get_var(char *sstr, int i, int end, char quote);
char	*space_rm(char *value);
//-Utils-
int		is_ifs(char c);
int		is_op(char c);
int		is_quote(char c);
char	quote_status(char quote, char c);
int		find_quote_end(char *str, int i, char quote);
#endif
