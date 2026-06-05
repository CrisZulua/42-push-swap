*This project has been created as part of the 42 curriculum by czuluaga*

# libft

## Description

**libft** is the first project from the 42 Cursus.

The goal is to create a custom library that will serve as a foundational tool for all future C projects. This library includes a comprehensive set of functions, recreating standard `libc` behavior as well as implementing additional utility functions.

## Instructions 

Inside this repository you will find a Makefile that compiles the entire library and creates an .a object.

After library compilation you can reference it inside any other project.

## Resources

Here is a list of resources used on this project:

- [GNU documentation](https://www.gnu.org/)

`Use of AI` : The use of ai was focus on repetitive tasks such as generating unit tests for all of the implementations.


## Content

Inside every function .c file there is a fully explanation of what it does.

### Part 1 and Part 2

These functions are primarily designed for character, string, and memory manipulation.

### `string.h`

- `ft_strlen`
- `ft_strlcpy`
- `ft_strlcat`
- `ft_strchr`
- `ft_strrchr`
- `ft_strncmp`
- `ft_strnstr`
- `ft_memset`
- `ft_memcpy`
- `ft_memmove`
- `ft_memchr`
- `ft_memcmp`
- `ft_strdup`

### `strings.h`

- `ft_bzero`

### `ctype.h`

- `ft_isalpha` | `ft_isdigit` | `ft_isalnum`
- `ft_isascii` | `ft_isprint`
- `ft_toupper` | `ft_tolower`

### `stdlib.h`

- `ft_atoi`
- `ft_calloc`

#### Additional Functions (Non-standard)

- `ft_substr` | `ft_strjoin` | `ft_strtrim` | `ft_split`
- `ft_itoa` | `ft_strmapi` | `ft_striteri`
- `ft_putchar_fd` | `ft_putstr_fd` | `ft_putendl_fd` | `ft_putnbr_fd`


### Part 3 - lists

This section focuses on implementing a set of functions to manipulate **Singly Linked Lists**.

- `ft_lstnew`
- `ft_lstadd_front`
- `ft_lstsize`
- `ft_lstlast`
- `ft_lstadd_back`
- `ft_lstdelone`
- `ft_lstclear`
- `ft_lstiter`
- `ft_lstmap`
