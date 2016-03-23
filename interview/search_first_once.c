#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( int argc, char **argv)
{
    char *str;
    char one;
    int len;

    argc--;
    argv++;
    str = *argv;
    printf ("char=%s\n", str);
    len = find (str, &one);
    printf ("address=%d, char=%c\n", len, one);

    return 0;
}

int find ( char *str, char *one )
{
    int len, i;
    char *s, ch, *min, *tmp;
    int AZ[26];

    if( str == NULL )return -1;
    memset(AZ, 0, sizeof(AZ));
    s = str;
    while (*s) {
        i = (int)(*s - 'a');
        AZ[i]++;
        s++;
    }
    min = str + (int)strlen(str);
    for (i=0; i<26; i++)
    {
        if(AZ[i] == 1){
            s = str;
            ch = (char) (&AZ[i] - AZ + 'a');
            while (*s) {
                if(ch == *s) {
                    min = min<s?min:s;
                    break;
                }
                s++;
            }
            printf("%c = %c\n", ch, *min);
        }
    }
    len = min - str + 1;
    *one = str[len - 1];

    return len;
}
