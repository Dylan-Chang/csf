
/*squeezeº¯Êý:´Ó×Ö·û´®sÖÐÉ¾³ý×Ö·ûc*/
int squeeze(char s[], int c)
{
    int i, j;

    for (i = j = 0; s[i] != '\0'; ++i)
    {
        if (s[i] != c)
        {
            s[j++] = s[i];
        }
    }
    s[j] = '\0';
}

