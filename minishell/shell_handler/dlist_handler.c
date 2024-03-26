/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:58:46 by cbouvet           #+#    #+#             */
/*   Updated: 2024/03/13 00:20:56 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_handler.h"

// Create new t_dlist node
t_dlist	*new_dlist_node(char *str, int quote)
{
	t_dlist	*new;

	if (!str)
		return (NULL);
	new = malloc(sizeof(t_dlist));
	if (!new)
		return (NULL);
	new->type = get_type(str, quote);
	new->content = str;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

// Adds new node to end of list
void	addback_dlist(t_dlist **dlist, t_dlist *new)
{
	t_dlist	*last;

	if (!new)
		return ;
	if (!*dlist)
	{
		*dlist = new;
		return ;
	}
	last = *dlist;
	while (last->next)
		last = last->next;
	last->next = new;
	new->prev = last;
}

// Adds new node to list according to ascii order
void	addascii_dlist(t_dlist **dlist, t_dlist *new)
{
	t_dlist	*ptr;

	if (!new)
		return ;
	if (!*dlist)
	{
		*dlist = new;
		return ;
	}
	ptr = *dlist;
	while (ptr)
	{
		if (ptr && ft_strncmp(new->content, ptr->content, VAR_LEN) <= 0)
		{
			insert_dlist(dlist, ptr, new);
			return ;
		}
		ptr = ptr->next;
	}
	if (!new->next && !new->prev)
		addback_dlist(dlist, new);
}

// inserts node in a specific list placement
void	insert_dlist(t_dlist **dlist, t_dlist *ptr, t_dlist *new)
{
	if (ptr->prev)
	{
		ptr->prev->next = new;
		new->prev = ptr->prev;
	}
	else
		*dlist = new;
	ptr->prev = new;
	new->next = ptr;
}

// Removes specific node from list
void	rm_dlist(t_dlist **dlist, t_dlist *ptr)
{
	if (ptr->prev && ptr->next)
	{
		ptr->prev->next = ptr->next;
		ptr->next->prev = ptr->prev;
	}
	else if (!ptr->prev)
	{
		*dlist = ptr->next;
		ptr->next->prev = NULL;
	}
	else if (!ptr->next)
		ptr->prev->next = NULL;
	free(ptr->content);
	free(ptr);
}
