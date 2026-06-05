/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuluaga <czuluaga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 08:49:51 by czuluaga          #+#    #+#             */
/*   Updated: 2026/04/21 16:38:46 by czuluaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_num_words(char const *s, char c)
{
	int		num_words;
	size_t	i;

	i = 0;
	num_words = 0;
	if (!s[i])
		return (0);
	if (s[i] != c)
		num_words++;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			num_words++;
		i++;
	}
	return (num_words);
}

static char	*ft_get_word(const char *s, char c, size_t *pos)
{
	char	*word;
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
	while (s[len] != c && s[len])
		len++;
	word = (char *)malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = 0;
	*pos += (len - 1);
	return (word);
}

static void	ft_free_split(char **split, size_t n)
{
	while (n--)
		free(split[n]);
	free(split);
}

/*
	DESCRIPTION
	Allocates memory and returns an array of strings obtained
	by splitting 's' using the character 'c' as a delimiter.
	The array must end with a NULL pointer.

	On allocation failure, this function frees any memory
	allocated previous to the failure of allocation.

	RETURN
	The array of new strings resulting from the split.
	NULL if the allocation fails.
*/
char	**ft_split(char const *s, char c)
{
	char	**split_words;
	int		num_words;
	size_t	i;
	size_t	wcnt;

	i = 0;
	wcnt = 0;
	num_words = ft_get_num_words(s, c);
	split_words = (char **)malloc((num_words + 1) * sizeof(char *));
	if (!split_words)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			split_words[wcnt] = ft_get_word(&s[i], c, &i);
			if (!split_words[wcnt])
				return (ft_free_split(split_words, wcnt - 1), NULL);
			wcnt++;
		}
		i++;
	}
	split_words[wcnt] = NULL;
	return (split_words);
}
