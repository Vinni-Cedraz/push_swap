/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 19:08:45 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/04/22 17:13:34 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

t_instruction	*create_hash_table(void)
{
	t_instruction	*cmd_table;

	cmd_table = ft_calloc(sizeof(t_instruction), 2000);
	cmd_table[hash_function("pa\n")] = &pa;
	cmd_table[hash_function("pb\n")] = &pb;
	cmd_table[hash_function("sa\n")] = &sa;
	cmd_table[hash_function("sb\n")] = &sb;
	cmd_table[hash_function("ss\n")] = &ss;
	cmd_table[hash_function("ra\n")] = &ra;
	cmd_table[hash_function("rb\n")] = &rb;
	cmd_table[hash_function("rr\n")] = &rr;
	cmd_table[hash_function("rra\n")] = &rra;
	cmd_table[hash_function("rrb\n")] = &rrb;
	cmd_table[hash_function("rrr\n")] = &rrr;
	return (cmd_table);
}

size_t	hash_function(char *end)
{
	char	*start;
	size_t	hash;

	hash = 5381;
	start = end;
	while (*end != '\n')
	{
		hash = ((hash << 5) + hash) + *end;
		end++;
	}
	if (end - start > 3)
		return (0);
	return (hash & 0b11111111111);
}

//
// #include <assert.h>
// #include <stdio.h>
// void next_permutation(char str[]) {
//     if (str[1] < 'z') {
//         str[1]++;
//     } else {
//         str[1] = 'a';
//         if (str[0] < 'z') {
//             str[0]++;
//         } else {
//             str[0] = 'a';
//         }
//     }
//     str[2] = '\n';
// }
//
// void next_permutation_3(char str[]) {
//     if (str[2] != 'z') {
//         str[2]++;
//     } else {
//         str[2] = 'a';
//         if (str[1] != 'z') {
//             str[1]++;
//         } else {
//             str[1] = 'a';
//             if (str[0] != 'z') {
//                 str[0]++;
//             } else {
//                 str[0] = 'a';
//             }
//         }
//     }
//     str[3] = '\n';
// }
//
// int main(void) {
//     char *str;
//     int counter;
//
//     str = malloc(4 * sizeof(char));
//     str[0] = 'a';
//     str[1] = 'a';
//     str[2] = 'a';
//     str[3] = '\0';
//     counter = 0;
// 	FILE *fp = fopen("hashes.txt", "w");
//
//     while (str[0] != 'z'|| str[1] != 'z' || str[2] != 'z') {
// 		counter++;
//         next_permutation_3(str);
// 		printf("%s", str);
//         fprintf(fp, "%zu\n", hash_function(str));
// 		if (strcmp(str, "rra\n") || strcmp(str, "rrb\n") || strcmp(str, "rrr\n")
// 				|| strcmp(str, "pa\b") || strcmp(str, "pb\n") 
// 				|| strcmp(str, sa\n")
// 				|| strcmp(str, "sb\b") || strcmp(str, "ss\n") 
//				|| strcmp(str, ra\n")
// 				|| strcmp(str, "rb\b") || strcmp(str, "rr\n"))
// 			continue ;
//         if (hash_function("pa") == hash_function(str)) break ;
//         if (hash_function("pb") == hash_function(str)) break ;
//         if (hash_function("sa") == hash_function(str)) break ;
//         if (hash_function("sb") == hash_function(str)) break ;
//         if (hash_function("ss") == hash_function(str)) break ;
//         if (hash_function("ra") == hash_function(str)) break ;
//         if (hash_function("rb") == hash_function(str)) break ;
//         if (hash_function("rr") == hash_function(str)) break ;
//         if (hash_function("rra\n") == hash_function(str)) break ;
//         if (hash_function("rrb\n") == hash_function(str)) break ;
//         if (hash_function("rrr\n") == hash_function(str)) break ;
// 	}
//
//     printf("%s\n", str);
//     printf("counter: %d\n", counter);
//     free(str);
// }
