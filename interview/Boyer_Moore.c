/*
 * BM（Boyer-Moore）算法
 */
static void suffix(char *pattern, int m, int suff[])
{
    int i, j;
    int k;

    suff[m - 1] = m;

    for(i = m - 2; i >= 0; i--)
    {
        j = i;
        while(j >= 0 && pattern[j] == pattern[m - 1 - i + j]) j--;

        suff[i] = i - j;
    }
}
static void PreBmBc(char *pattern, int m, int bmBc[])
{
    int i;

    for(i = 0; i < 256; i++)
    {
        bmBc[i] = m;
    }

    for(i = 0; i < m - 1; i++)
    {
        bmBc[pattern[i]] = m - 1 - i;
    }
}
static void PreBmGs(char *pattern, int m, int bmGs[])
{
    int i, j;
    int suff[SIZE]; 

    // 计算后缀数组
    suffix(pattern, m, suff);

    // 先全部赋值为m，包含Case3
    for(i = 0; i < m; i++)
    {
        bmGs[i] = m;
    }

    // Case2
    j = 0;
    for(i = m - 1; i >= 0; i--)
    {
        if(suff[i] == i + 1)
        {
            for(; j < m - 1 - i; j++)
            {
                if(bmGs[j] == m)
                    bmGs[j] = m - 1 - i;
            }
        }
    }

    // Case1
    for(i = 0; i <= m - 2; i++)
    {
        bmGs[m - 1 - suff[i]] = m - 1 - i;
    }
}

int BoyerMoore(char *pattern, int m, char *text, int n)
{
    int i, j, bmBc[MAX_PATH], bmGs[SIZE];

    //Preprocessing
    PreBmBc(pattern, m, bmBc);
    PreBmGs(pattern, m, bmGs);

    // Searching
    j = 0;
    while(j <= n - m)
    {
        for(i = m - 1; i >= 0 && pattern[i] == text[i + j]; i--);
        if(i < 0)
        {
            //logprintfl (EUCAINFO, "BoyerMoore():Find it, the position is %d\n", j);
            j += bmGs[0];
            return OK;
        }
        else
        {
            j += MAX(bmBc[text[i + j]] - m + 1 + i, bmGs[i]);
        }
    }

    //logprintfl (EUCAINFO, "BoyerMoore():No find.\n");
    return ERROR;
}

static int save_json(param_list *head, char *json, int len, 
                     char *instance, char *localhost)
{
    int rc = ERROR, size;
