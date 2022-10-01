#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*add;

	if (!lst)
		return (NULL);
	new = ft_lstnew(f(lst->content));
	add = NULL;
	if (!new)
		return (NULL);
	lst = lst->next;
	while (lst)
	{
		add = ft_lstnew(f(lst->content));
		if (!add)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, add);
		lst = lst->next;
	}
	return (new);
}
