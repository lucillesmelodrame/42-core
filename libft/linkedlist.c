#include "libft.h"
#include "testers.h"

#include "testers.h"

void	del_content(void *content)
{
	free(content);
}

void	print_content(void *content)
{
	printf("[%s] ", (char *)content);
}

void	*upper_content(void *content)
{
	return (ft_strdup((char *)content));
}

int	main(void)
{
	t_list	*node1 = ft_lstnew(ft_strdup("A"));

	if (node1 && node1->content && !node1->next)
		printf(GREEN);
	else
		printf(RED);
	printf("lstnew: content should say 'A', next should be NULL\n\n");
	printf(RESET);

	t_list	*list = NULL;

	if (ft_lstsize(list) == 0)
		printf(GREEN);
	else
		printf(RED);
	printf("lstsize on an empty list, expecting 0\n\n");
	printf(RESET);

	ft_lstadd_back(&list, ft_lstnew(ft_strdup("B")));
	ft_lstadd_front(&list, ft_lstnew(ft_strdup("A")));
	ft_lstadd_back(&list, ft_lstnew(ft_strdup("C")));
	if (ft_lstsize(list) == 3)
		printf(GREEN);
	else
		printf(RED);
	printf("added 3 nodes, size should be 3\n\n");
	printf(RESET);

	printf("order should be A B C: ");
	ft_lstiter(list, print_content);
	printf("\n\n");

	t_list	*last = ft_lstlast(list);

	if (last && ft_strncmp((char *)last->content, "C", 2) == 0)
		printf(GREEN);
	else
		printf(RED);
	printf("lstlast, expecting C\n\n");
	printf(RESET);

	t_list	*mapped = ft_lstmap(list, upper_content, del_content);

	if (mapped && ft_lstsize(mapped) == 3)
		printf(GREEN);
	else
		printf(RED);
	printf("lstmap, size should stay 3\n\n");
	printf(RESET);

	t_list	*single = ft_lstnew(ft_strdup("Solo"));

	if (ft_lstsize(single) == 1 && ft_lstlast(single) == single)
		printf(GREEN);
	else
		printf(RED);
	printf("one node list, size 1 and last should be itself\n\n");
	printf(RESET);

	ft_lstclear(&list, del_content);
	if (list == NULL)
		printf(GREEN);
	else
		printf(RED);
	printf("lstclear should reset the pointer to NULL\n\n");
	printf(RESET);

	ft_lstclear(&mapped, del_content);
	ft_lstdelone(single, del_content);
	free(node1->content);
	free(node1);
	return (0);
}
