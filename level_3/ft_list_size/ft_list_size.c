#include <stdio.h>
#include <stdlib.h>
#include "ft_list_size.h"

t_list	*create_node(char *content)
{
	t_list	*node;
	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->data = content;
	node->next = NULL;
	return (node);
}

void	add_node(t_list **headRef, t_list *new)
{
	t_list	*lst;

	if (*headRef == NULL)
	{
		*headRef = new;
		return ;
	}
	lst = *headRef;
	while (lst->next)
		lst = lst->next;
	lst->next = new;
}

void	print_lst(t_list *lst)
{
	while (lst)
	{
		printf("%s\n", (char *)lst->data);
		lst = lst->next;
	}
}

int	ft_list_size(t_list *begin_list)
{
	int	count;

	count = 0;
	while (begin_list)
	{
		count++;
		begin_list = begin_list->next;
	}
	return (count);
}

void	free_lst(t_list *lst)
{
	t_list	*temp;

	if (!lst)
		return ;
	while (lst)
	{
		temp = lst->next;
		free(lst);
		lst = temp;
	}
	free(lst);
}

int	main(void)
{
	t_list	*head;
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;

	head = NULL;
	node1 = create_node("Hello");
	node2 = create_node("Good morning!");
	node3 = create_node("Goodbye!");
	add_node(&head, node1);
	add_node(&head, node2);
	add_node(&head, node3);
	print_lst(head);
	int	count = ft_list_size(head);
	printf("%d\n", count);
	free_lst(head);
	return (0);
}
