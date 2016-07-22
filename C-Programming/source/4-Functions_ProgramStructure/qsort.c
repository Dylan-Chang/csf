
/*swap函数:交换v[i]与v[j]的值*/
void swap(int v[], int i, int j)
{
    int temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}


/*qsort函数:以递增顺序对v[left] ... v[right]进行排序*/
void qsort(int v[], int left, int right)
{
    int i, last;

    /*若数组包含的元素数少于两个则不执行任何操作*/
    if (left >= right)
        return ;

    /*将划分子集的元素移动到v[0]*/
    swap(v, left, (left+right)/2);
    last = left;

    /*划分子集*/
    for (i = left + 1;i <= right; i++)
    {
        if (v[i] < v[left])
            swap(v, ++last, i);
    }

    /*恢复划分子集的元素*/
    swap(v, left, last);

    qsort(v, left, last-1);
    qsort(v, last+1, right);
    
}
