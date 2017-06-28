#include <stdio.h>

main(){
  float fah,cel;
  float upper,lower,step;

  lower = 0;
  step = 20;
  upper = 300;

  while(fah <= upper){

    cel = (5.0/9.0) * (fah - 32.0);
    printf("%3.0f %6.1f\n",fah,cel);
    fah = fah + step;
  }
}
