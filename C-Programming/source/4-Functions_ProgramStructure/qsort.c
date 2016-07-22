
/*swap����:����v[i]��v[j]��ֵ*/
void swap(int v[], int i, int j)
{
    int temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}


/*qsort����:�Ե���˳���v[left] ... v[right]��������*/
void qsort(int v[], int left, int right)
{
    int i, last;

    /*�����������Ԫ��������������ִ���κβ���*/
    if (left >= right)
        return ;

    /*�������Ӽ���Ԫ���ƶ���v[0]*/
    swap(v, left, (left+right)/2);
    last = left;

    /*�����Ӽ�*/
    for (i = left + 1;i <= right; i++)
    {
        if (v[i] < v[left])
            swap(v, ++last, i);
    }

    /*�ָ������Ӽ���Ԫ��*/
    swap(v, left, last);

    qsort(v, left, last-1);
    qsort(v, last+1, right);
    
}
