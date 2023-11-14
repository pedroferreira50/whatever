#include "libft.h"
/*
static int	countwords(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			count++;
			while (str[i] != c)
				i++;
		}
		i++;
	}
	return (count);
}
*/
static int	countwords(const char *str, const char c)
{
	int	i;
	int	is_word;

	i = 0;
	if (ft_isprint(c))
	{
		is_word = 0;
		while (*str)
		{
			if ((*str == c) == is_word)
			{
				is_word = 1 - is_word;
				if (is_word)
					i++;
			}
			str++;
		}
	}
	else
		i = 1;
	return (i);
}

static char **free_on_error(char **tab, unsigned int i)
{
    while (i > 0)
    {
        free(tab[i - 1]);
        i--;
    }
    free(tab);
    return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	**splitstr;

	i = 0;
	k = 0;
	//splitstr = calloc((countwords((char *)s, c)), sizeof(char *));
	splitstr = (char **)ft_calloc(countwords(s, c), sizeof(char *));
	if (!splitstr)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			j = i;
			while (s[j] != c)
				j++;
			splitstr[k] = malloc(sizeof(char) * ((j - i) + 1));
			if (!splitstr[k])
				return (free_on_error(splitstr, k + 1));
			j = 0;
			while (s[i] != c)
				splitstr[k][j++] = s[i++];
			splitstr[k][j] = '\0';
			k++;
		}
		i++;
	}
	return (splitstr);
}
/*
int	main(void)
{
	char	**array;
	int	num;

	array = ft_split("                  olol", ' ');
	num = 0;
	while (array[num] != NULL) 
    	num++;
	for (int i = 0; i < num; i++) {
        printf("%s\n", array[i]);
    }
	free_on_error(array, num +1);
	return (0);
}
*/
/*
int main(void)
{
	printf("%d", countwords("hello!", 32:' '));
}*/