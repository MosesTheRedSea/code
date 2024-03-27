/**
 * @file my_string.c
 * @author Moses Adewolu
 * @brief Your implementation of the famous string.h library functions!
 *
 * NOTE: NO ARRAY NOTATION IS ALLOWED IN THIS FILE
 *
 * @date 2024-03-25
 */

#include "my_string.h"

/* Note about UNUSED_PARAM
*
* UNUSED_PARAM is used to avoid compiler warnings and errors regarding unused function
* parameters prior to implementing the function. Once you begin implementing this
* function, you can delete the UNUSED_PARAM lines.
*/

/**
 * @brief Calculate the length of a string
 *
 * @param s a constant C string
 * @return size_t the number of characters in the passed in string
 */
size_t my_strlen(const char *s)
{
    UNUSED_PARAM(s);
    size_t string_size = 0;

    while(*s != '\0') {
        string_size++;
        s++;
    }
    return string_size;
}

/**
 * @brief Compare two strings
 *
 * @param s1 First string to be compared
 * @param s2 Second string to be compared
 * @param n First (at most) n bytes to be compared
 * @return int representing the difference between the strings:
 *          - 0 if the strings are equal
 *          - arbitrary positive number if s1 > s2
 *          - arbitrary negative number if s1 < s2
 */
int my_strncmp(const char *s1, const char *s2, size_t n)
{
    UNUSED_PARAM(s1);
    UNUSED_PARAM(s2);
    UNUSED_PARAM(n);

    int diff = 0;
    
    for (size_t i = 0; i < n-1; ++i) {
        if (*s1 != '\0' && *s2 != '\0') {
            if (*s1 == *s2) {
                s1++;
                s2++;
                continue;
            }
        }
        break;
    }

    if (*s1 < *s2) {
        diff = -1;
    } else if (*s1 > *s2) {
        diff = 1;
    } else {
        diff = 0;
    }

    return diff;
}

/**
 * @brief Copy a string
 *
 * @param dest The destination buffer
 * @param src The source to copy from
 * @param n maximum number of bytes to copy
 * @return char* a pointer same as dest
 */
char *my_strncpy(char *dest, const char *src, size_t n)
{

    UNUSED_PARAM(dest);
    UNUSED_PARAM(src);
    UNUSED_PARAM(n);

    char *start = dest;

    while (n --> 0) {
        *dest = *src;
         dest++;
         src++;
    }
    return start;
}

/**
 * @brief Concatenates two strings and stores the result
 * in the destination string
 *
 * @param dest The destination string
 * @param src The source string
 * @param n The maximum number of bytes (or characters) from src to concatenate
 * @return char* a pointer same as dest
 */
char *my_strncat(char *dest, const char *src, size_t n)
{
    UNUSED_PARAM(dest);
    UNUSED_PARAM(src);
    UNUSED_PARAM(n);

    char *start = dest;

    while (*dest != '\0') {
        dest++;
    }

    while (n --> 0) {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    
    return start;
}

/**
 * @brief Copies the character c into the first n
 * bytes of memory starting at *str
 *
 * @param str The pointer to the block of memory to fill
 * @param c The character to fill in memory
 * @param n The number of bytes of memory to fill
 * @return char* a pointer same as str
 */
void *my_memset(void *str, int c, size_t n)
{
    UNUSED_PARAM(str);
    UNUSED_PARAM(c);
    UNUSED_PARAM(n);

    char *start = (char *) str;
    
    for (size_t i = 0; i < n; ++i) {
        *start = (char)c;
        start++;
    }

    return str;
}

/**
 * @brief Checks whether the string is a palindrome
 * (i.e., reads the same forwards and backwards)
 * assuming that the case of letters is irrelevant.
 * 
 * @param str The pointer to the string
 * @return 1 if the string is a palindrome,
 * or 0 if the string is not
*/
int is_palindrome_ignore_case(const char *str) {
    UNUSED_PARAM(str);
    const char *start = str;
    const char *end = str;

    while (*end != '\0') {
        // Just changing the pointer to the end
        end++;
    } // Here we are at '\0'
    end--;  // Now we are at the last char

    while (start <= end) {

        /*
        if (((*start >= 'a' && *start <= 'z') || (*start >= 'A' && *start <= 'Z')) && ((*end >= 'a' && *end <= 'z') || (*end >= 'A' && *end <= 'Z'))) {
            if (*start >= 'A' && *start <= 'Z') {
                start_char = *start + ('a' - 'A');
            } else {
                start_char = *start;
            }

            if (*end >= 'A' && *end <= 'Z') {
                end_char = *end + ('a' - 'A');
            } else {
                end_char = *end;
            }
        }
        */
        char start_char = (*start >= 'A' && *start <= 'Z') ? (*start + ('a' - 'A')) : *start;
        char end_char = (*end >= 'A' && *end <= 'Z') ? (*end + ('a' - 'A')) : *end;

        if (start_char != end_char) {
            return 0;
        }

        start++;
        end--;
    }
    return 1;
}

/**
 * @brief Apply a Caesar shift to each character
 * of the provided string in place.
 * 
 * @param str The pointer to the string
 * @param shift The amount to shift by
*/
void caesar_shift(char *str, int shift) 
{
    UNUSED_PARAM(str);
    UNUSED_PARAM(shift);
    size_t len = my_strlen(str);

    for (size_t i = 0; i < len; ++i) {
        if ((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z') ){
            // Check if char is lowerCase
            if (*str >= 'a' && *str <= 'z') {
                // Caedar Cipher = index + shift % 26 - Except for Upper Case
                *str = (*str - 'a' + shift) % 26 + 'a';
            // Check if char is upperCase
            } else if (*str >= 'A' && *str <= 'Z') {
                *str = (*str - 'A' + shift) % 26 + 'A';
            }
        } 
        str++; 
    }
    return;
}

/**
 * @brief Mutate the string in-place to
 * remove duplicate characters that appear
 * consecutively in the string.
 * 
 * @param str The pointer to the string
*/
void deduplicate_str(char *str) 
{
    UNUSED_PARAM(str);

    char *read = str;
    char *edit = str;
    char last = '\0';

    // mississippi
     while (*read != '\0') {
        if (*read != last) {
            *edit = *read;
            edit++;
        } 
        last = *read;
        read++;
    }
    // Null-terminate the new string
    *edit = '\0';
    return;
}

/**
 * @brief Swap the position of
 * two strings in memory.
 * 
 * @param s1 The first string
 * @param s2 The second string
*/
void swap_strings(char **s1, char **s2) 
{
    UNUSED_PARAM(s1);
    UNUSED_PARAM(s2);

    char *holder = *s1;
    *s1 = *s2;
    *s2 = holder;

    return;
}