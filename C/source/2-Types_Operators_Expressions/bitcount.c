
/*bitcount����: ͳ��x��ֵΪ1�Ķ�����λ��*/
unsigned bitcount(unsigned x)
{
    int b;
    for (b = 0; x != 0; x >>= 1)
        if (x & 01)
            b++;

    return b;
}

