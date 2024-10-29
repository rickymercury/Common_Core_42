/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <ricardomedeirosx@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:09:00 by rickymercur       #+#    #+#             */
/*   Updated: 2024/10/28 22:38:31 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst == NULL || del == NULL)
		return ;
	del(lst->content);
	free(lst);
}

/*
t_list	*ft_lstnew(void *content)
{
	t_list *new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

void	del(void *content)
{
	free(content);
}

int	main(void)
{
	t_list	*node = ft_lstnew(strdup("Content"));

	if (node == NULL || node->content == NULL)
	{
		printf("Falha ao criar o nó.\n");
		return (1);
	}
	printf("Conteúdo do nó antes de apagar: %s\n", (char *)node->content);
	ft_lstdelone(node, del);
	printf("O nó foi apagado com sucesso.\n");

	return (0);
}
*/