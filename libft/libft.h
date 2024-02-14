/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: gbelange <gbelange@student.42quebec.com    +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2022/04/05 18:32:52 by gbelange          #+#    #+#             */
/*   Updated: 2022/05/11 19:45:39 by gbelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <fcntl.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

# define X_BASE "0123456789abcdef"
# define XX_BASE "0123456789ABCDEF"
# define DEC_BASE "0123456789"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3000
# endif

int		ft_printf(const char *toprint, ...);
int		ft_atoi(const char *str);
int		ft_arrlen(char **a);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t n);
void	*ft_memset(void *str, int c, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *s, int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
t_list	*ft_lstnew(void *content);
t_list	*ft_lstcreate(void *content, size_t size_of);
void	ft_lstinsert(t_list **lst, unsigned int index, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	*ft_lstpop(t_list **lst, unsigned int index);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void	ft_lstprint_int(t_list *lst);
void	ft_lstprint_str(t_list *lst);
void	ft_lstprint_float(t_list *lst);
void	ft_arrfree(char **arr);
char	*ft_strndup(const char *src, size_t l);
int		ft_isdigit_str(const char *str);

//ft_printf files -- Ne pas utiliser
void	printf_vartypefinder(char c, va_list args, int *ptrret);
void	printf_writechar(char c, int *ptrret);
void	printf_writestring(char *s, int *ptrret);
void	printf_putnbr_base(long nbr, char *base, int *ptrret, char flag);
void	printf_writeptr(unsigned long nbr, char *base, int *ptrret);

//get_next_line
char	*get_next_line(int fd);

#endif
