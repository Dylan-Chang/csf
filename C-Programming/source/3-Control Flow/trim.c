/*trimº¯Êı:É¾³ı×Ö·û´®Î²²¿µÄ¿Õ¸ñ·û¡¢ÖÆ±í·ûÓë»»ĞĞ·û*/
void trim(int s[])
{
    int n;

    for (n = strlen(s) - 1; n >= 0; n--)
    {
        if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
            break;
    }

    s[n+1] = '\0';

    return n;
}
