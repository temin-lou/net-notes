/******************************************
 * Give a column title as appear in an Excel
 * sheet, return its corresponding column
 * number.
 *
 * A -> 1
 * B -> 2
 * C -> 3
 * ...
 * Z -> 26
 * AA -> 27
 * AB -> 28
 *
 */
#include <stdio.h>
#include <string.h>

int get_col_number( char *str )
{
    int len, i;
    int col, sum;

    col = 0;
    sum = 0;
    len = strlen( str );
    for (i=0; i<len; i++)
    {
        col = str[i] - 'A' + 1;
        sum = sum * 26 + col; 
    }
    return sum;
}

int main( int argc, char **argv )
{
    char s[10];
    int col;

    strcpy (s, "A");
    col = get_col_number(s);
    printf("%s -> %d\n", s, col);
    strcpy (s, "AB");
    col = get_col_number(s);
    printf("%s -> %d\n", s, col);
    
    strcpy (s, "AZZB");
    col = get_col_number(s);
    printf("%s -> %d\n", s, col);

    return 0;
}
