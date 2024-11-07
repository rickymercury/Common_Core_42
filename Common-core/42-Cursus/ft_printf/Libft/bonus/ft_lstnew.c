/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rickymercury <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:53:41 by rickymercur       #+#    #+#             */
/*   Updated: 2024/11/06 00:26:11 by rickymercur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

/*
void	ft_print_result(char const *s) 
{
	int		len = 0;

	while (s[len])
		len++;
	write(1, s, len);
}

void	ft_print_result2(int n) {
	char c;

	if (n >= 10)
		ft_print_result2(n / 10);
	c = n % 10 + '0';
	write (1, &c, 1);
}

void	ft_lstclear(t_list **lst, void (*del)(void *)) 
{
	t_list	*temp;

	if (!lst)
		return;
	while (*lst) {
		temp = (*lst)->next;
		if (del && (*lst)->content)
			del((*lst)->content);
		free(*lst);
		*lst = temp;
	}
}

void	ft_del(void *content) 
{
	if (content != NULL)
		free(content);
}

int main(int argc, const char *argv[]) 
{
	t_list		*elem;
	int			arg;

	if (argc == 1)
		return (0);
	else if ((arg = atoi(argv[1])) == 1) {
		char	str [] = "lorem ipsum dolor sit";

		if (!(elem = ft_lstnew(str)))
			ft_print_result("NULL");
		else {
			if (!(elem->content))
				ft_print_result("NULL");
			else
				ft_print_result(elem->content);
			
			if (!(elem->next)) 
            {
				write(1, "\n", 1);
				ft_print_result("NULL");
			}
			ft_lstclear(&elem, NULL);
		}
	}
	else if (arg == 2) 
    {
		int		i = 42;

		if (!(elem = ft_lstnew(&i)))
			ft_print_result("NULL");
		else {
			if (!(elem->content))
				ft_print_result("NULL");
			else
				ft_print_result2(*(int *)(elem->content));
			
			if (!(elem->next)) 
            {
				write(1, "\n", 1);
				ft_print_result("NULL");
			}
			ft_lstclear(&elem, NULL);
		}
	}
	else if (arg == 3) 
    {
		if (!(elem = ft_lstnew(NULL)))
			ft_print_result("NULL");
		else {
			if (!(elem->content))
				ft_print_result("NULL");
			else
				ft_print_result(elem->content);
			
			if (!(elem->next)) 
            {
				write(1, "\n", 1);
				ft_print_result("NULL");
			}
			ft_lstclear(&elem, NULL);
		}
	}
	return (0);
}
*/

/*
OUTPUT: 

cc -Wall -Werror -Wextra -g3 -fsanitize=address ft_lstnew.c -o ft_lstnew
sh-5.2$ ./ft_lstnew 1
lorem ipsum dolor sit
NULL
sh-5./ft_lstnew 2
42
NULL
sh-5.2$ ./ft_lstnew 3
NULL
NULL
*/