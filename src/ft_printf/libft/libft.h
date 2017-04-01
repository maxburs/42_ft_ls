/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 10:04:47 by mburson           #+#    #+#             */
/*   Updated: 2016/12/15 17:30:40 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdint.h>
# include <wchar.h>

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/*
** for lstr_add and lstr_finish
*/
typedef struct		s_lstr
{
	char			*str;
	_Bool			constant;
	struct s_lstr	*next;
}					t_lstr;

/*
** ./bool/
*/
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);

/*
** ./convert/
*/
uintmax_t			ft_absolute(intmax_t n);
int					ft_atoi(const char *str);
char				*ft_itoa(int n);
char				*ft_itoa_base(uintmax_t n, uintmax_t base, \
							_Bool uppercase);
int					ft_tolower(int c);
int					ft_toupper(int c);
wint_t				ft_utf_16_32(wchar_t **c);
unsigned char		*ft_utf_16_8(wchar_t **c);
unsigned char		*ft_utf_32_8(wint_t c);

/*
** ./list/
*/
void				lstadd(t_list **alst, t_list *new);
void				lstpush(t_list **alst, t_list *new);
void				lstdel(t_list **alist, void (*del)(void *));
void				lstdelone(t_list **alst, void (*del)(void *));
void				lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*lstnew(void *content);
void				lstprint(t_list *link);
void				lstreverse(t_list **alst);
void				lstsort(t_list **dir_lst, _Bool (compare)(void*, void*));

/*
** ./lstr/
*/
_Bool				lstr_add(t_lstr **start, char *str, _Bool constant);
char				*lstr_finish(t_lstr **start);
t_lstr				*lstr_new(char *str, _Bool constant);
void				lstr_print(t_lstr *link);

/*
** ./memory/
*/
void				*ft_bzero(void *s, size_t len);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dst, const void *src, \
							int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memdup(const void *item, size_t size);
void				*ft_memmove(void *dst, const void *src, size_t n);
void				*ft_memset(void *b, int c, size_t len);

/*
** ./other/
*/
int					ft_numlen(long n, long base);
int					ft_numlen_un(uintmax_t n, uintmax_t base);

/*
** ./put/
*/
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(const char *s);
void				ft_putendl_fd(const char *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr(const char *s);
void				ft_putstr_fd(const char *s, int fd);
void				ft_putstrw(const wchar_t *str);

/*
** ./string/
*/
char				*ft_strplace(char *dst, const char *src);
size_t				ft_wrdcnt(const char *str, char split);
int					ft_strchri(const char *str, char c);
char				*ft_strnchr(const char *s, int c, size_t n);
size_t				ft_strlen(const char *s);
size_t				ft_strlenw(const wchar_t *str);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t len);
char				*ft_strndup(const char *str, size_t n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *s1, const char *s2, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big, const char *little, \
							size_t len);
int					ft_strcmp(char *s1, char *s2);
int					ft_strncmp(char *s1, char *s2, size_t n);
char				*ft_strnew(size_t size);
void				ft_strdel(char **s);
char				*ft_strdup(const char *str);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char *s, char (*f)(char));
char				*ft_strmapi(char *s, char (*f)(unsigned int, char));
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);

#endif
