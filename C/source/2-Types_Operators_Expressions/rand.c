
unsigned long int next = 1;

/*rand����:����ȡֵ��0~32767֮���α�����*/
int rand(void)
{
    next = next * 1103515245 + 12345;
    return (unsigned int)(next/65535) % 32768;
}

/*srand����:Ϊrand()��������������*/
void srand(unsigned int seed)
{
    next = seed;
}

