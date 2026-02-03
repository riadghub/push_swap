/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:32:46 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/02/03 10:02:27 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <ctype.h>
# include <limits.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct pile
{
	int			content;
	int			index;
	int			cost;
	struct pile	*next;
	struct pile	*target;
}				t_pile;

void			costing(t_pile **lst);
void			add_to_lst(int argc, char *argv[], t_pile **lst);
void			adding_arg(int argc, char *argv[], t_pile **lst);
void			adding_str(int argc, char *argv[], t_pile **lst);
void			ft_lstadd_front(t_pile **lst, t_pile *new);
void			ft_lstadd_back(t_pile **lst, t_pile *new);
void			free_list(t_pile **lst);
void			free_all(char **str);
void			init(t_pile **a, t_pile **b);
void			init_all(t_pile **a, t_pile **b);
void			init_target(t_pile **a, t_pile **b);
void			indexing(t_pile **lst);
void			swap(t_pile **a);
void			push(t_pile **a, t_pile **b);
void			push_to_b(t_pile **a, t_pile **b);
void			rotate(t_pile **a);
void			reverse_rotate(t_pile **a);
void			sort(t_pile **a);
void			sort_a(t_pile **a);
void			sort_all(t_pile **a, t_pile **b);
void			sort_two(t_pile **lst);
void			sort_three(t_pile **lst);
void			sorting(t_pile **a, t_pile **b, int size);
void			sa(t_pile **a);
void			sb(t_pile **a);
void			ss(t_pile **a, t_pile **b);
void			pa(t_pile **a, t_pile **b);
void			pb(t_pile **a, t_pile **b);
void			ra(t_pile **a);
void			rb(t_pile **b);
void			rr(t_pile **a, t_pile **b);
void			rra(t_pile **a);
void			rrb(t_pile **b);
void			rrr(t_pile **a, t_pile **b);
void			targeting(t_pile **a, t_pile **b);

char			**ft_split(char const *s, char c);
char			*get_word(char const *str, char c, int *index);

int				calc_mid(t_pile **a);
int				calculate_cost(t_pile *node);
int				count_words(const char *str, char c);
int				ft_lstsize(t_pile *lst);
int				ft_strlen(char *str);
int				ft_tablen(char **str);
int				ft_isdigit(char c);
int				ft_is_space(const char c);
int				in_lim(t_pile **a, int lim);
int				is_valid(int argc, char *argv[]);
int				is_valid_str(int argc, char *argv[]);
int				is_double(int argc, char *argv[]);
int				is_double_str(int argc, char *argv[]);
int				is_sorted(t_pile **lst);
int				parsing(int argc, char *argv[]);
int				sub_valid_str(int argc, char *argv[]);

long			ft_atoi(const char *nptr);

t_pile			*ft_lstnew(int content, int index);
t_pile			*ft_lstlast(t_pile *lst);
t_pile			*find_next_max(t_pile *lst, t_pile *b);
t_pile			*find_smallest(t_pile *lst);
t_pile			*find_cheapest(t_pile **b);
t_pile			*find_max(t_pile *lst);
t_pile			*get_target(t_pile **a, t_pile *b);

#endif