/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 19:26:49 by vlegros           #+#    #+#             */
/*   Updated: 2019/04/16 23:41:53 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include "get_next_line.h"
# include "ft_printf.h"

# define START_CAP 1000
# define HT_START_CAP 1000
# define USE_GC 	  0

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef	struct		s_vec
{
	void			*data;
	size_t			length;
	size_t			capacity;
}					t_vec;

typedef struct		s_pvec
{
	void			**data;
	void			**start_data;
	size_t			length;
	size_t			capacity;
}					t_pvec;

typedef struct		s_cvec
{
	char			*data;
	char			*start_data;
	size_t			length;
	size_t			capacity;
}					t_cvec;

typedef	struct		s_ivec
{
	int				*data;
	size_t			length;
	size_t			capacity;
}					t_ivec;

typedef struct		s_ht
{
	size_t			size;
	size_t			capacity;
	t_list			**table;
	t_ivec			*loaded;
}					t_ht;

size_t				ft_strlen(const char *s);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *stc, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack,
										const char *needle, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *src);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_isspace(int c);

void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
int					ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char*));
void				ft_striteri(char *s, void (*f)(unsigned int, char*));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
char				*ft_strjoin(char const *s1, char const *s2);
void				ft_del_twodem_arr(void ***p_arr);
char				**ft_crt_chmatrix(int height, int lenght);

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lst_addback(t_list *head, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

t_ivec				*ft_int_vec_init(void);
int					ft_int_vec_pushback(t_ivec *vec, int value);
int					ft_int_vec_pushfront(t_ivec *vec, int value);
int					ft_int_vec_popfront(t_ivec *vec);
int					ft_int_vec_enlarge(t_ivec *vec);
void				ft_int_vec_del(t_ivec **vec);
int					ft_int_vec_popback(t_ivec *vec);

t_pvec				*ft_ptr_vec_init(void);
int					ft_ptr_vec_enlarge(t_pvec *vec);
int					ft_ptr_vec_pushback(t_pvec *vec, void *value);
int					ft_ptr_vec_pushfront(t_pvec *vec, void *value);
void				*ft_ptr_vec_popfront(t_pvec *vec);
void				ft_ptr_vec_del(t_pvec **vec, void (*del)(void**));
void				*ft_ptr_vec_popback(t_pvec *vec);

void				ft_chr_vec_del(t_cvec **vec_ptr);
int					ft_chr_vec_enlarge(t_cvec *vec, size_t len);
t_cvec				*ft_chr_vec_init(size_t size);
int					ft_chr_vec_pushback(t_cvec *vec, char *value);
char				ft_chr_vec_popfront(t_cvec *vec);

unsigned long		ft_hash(unsigned char *str, int capacity);
t_ht				*ft_ht_init(void);

t_vec				*ft_vec_init(size_t size);
int					ft_vec_enlarge(t_vec *vec);
void				ft_vec_clear(t_vec **vec);

int					get_next_line(int fd, char **line);
int					ft_abs(int x);
int					ft_atoi_base(const char *src, int src_base);
void				ft_swap(int *x, int *y);

t_pvec				*ft_put_in_gc(void *value);
void				find_and_del(t_pvec *garbage, void *value);
char				*ft_find_word(const char *str, int i, char c);

int					ft_printf(const char *restrict format, ...);

#endif
