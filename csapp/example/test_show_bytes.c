#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, int len){
	int i;
	for (i=0; i<len; i++){
	   printf("%.2x",start[i]); //C格式化指令“%.2x”表明整数必须用至少两个数字的十六进制格式输出
	}
	printf("\n");
}

void show_int(int x){
    show_bytes((byte_pointer) &x,sizeof(int));
}

void show_float(float x){
    show_bytes((byte_pointer) &x,sizeof(float));
}

void show_pointer(void *x){
    show_bytes((byte_pointer) &x,sizeof(void *));
}

void test_show_bytes(int val){
    int ival = val;
    float fval = (float)ival
    int *pval = &ival;
    
}



