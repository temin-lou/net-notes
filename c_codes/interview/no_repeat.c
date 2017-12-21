/*
 * Given a string, find the first non-repeating character in it and 
 * return it's index. If it doesn't exit, return -1;
 * 
 * s = "leetcode"
 * return 0.
 * s = "loveleetcode"
 * return 2.
 *
 */
#include <stdio.h>
#include <string.h>

int first_no_repeat(char *s, int size)
{
    int count['z' - 'a' + 1] = {0};
    int i;
    int index;
    for (i=0; i < size; i++)
    {
        index = tolower(*(s+i)) - 'a';
        ++count[index];
    }

    for (i=0; i<size; i++)
    {
        char c = *(s+i);
        index = tolower(c) - 'a';
        if (count[index] == 1) {
            return i;
        }
    }
    return -1;
}

int main (int argc, char **argv)
{
    char s[100];
    int len;

    strcpy(s, "leetcode");
    len = strlen(s);
    printf( "%s, %d\n", s, first_no_repeat(s, len) );

    strcpy(s, "loveleetcode");
    len = strlen(s);
    printf( "%s, %d\n", s, first_no_repeat(s, len) );

    strcpy(s, "loveleetcodevtdc");
    len = strlen(s);
    printf( "%s, %d\n", s, first_no_repeat(s, len) );

    return 0;
}
