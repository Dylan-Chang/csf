
/*strcat����: ���ַ���t���ӵ��ַ���s��β��;s�������㹻��Ŀռ�*/
void strcat(char s[], char t[])
{
    int i, j;

    i = j = 0; 
    while (s[i] != '\0')
    {
        i++;
    }
    while ((s[i++] = t[j++]) != '\0')
        ;
}

