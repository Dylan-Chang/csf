//6.1 结构基本知识
//6.2 结构与函数

#include <stdio.h>

//坐标
struct point{
  int x;
  int y;
};

//矩形
struct rect{
  struct point pt1;
  struct point pt2;
};

//struct point origin,*pp;

struct point makepoint(int,int);

void main(){
   struct point pt = {10,10};
   struct point maxpt = {320,200};
   printf("%d %d\n",pt.x,pt.y);
   printf("%d %d\n",maxpt.x,maxpt.y);

   //计算原点的距离
   double dist,sqrt(double);
   dist = sqrt((double)pt.x * pt.x + (double)pt.y * pt.y);
   printf("%f \n",dist);

   struct rect screen;
   //screen.pt1.x;
   
   struct point middle;
  // struct point makepoint(int int);
 
  //动态初始化
  screen.pt1 = makepoint(0,0);
  screen.pt2 = makepoint(XMAX,YMAX);
  
  middle = makepoint((screen.pt1.x + screen.pt2.x)/2,
                     (screen.pt2.y + screen.pt2.y)/2);

  printf("%d %d \n",screen.pt1,screen.pt2);
  printf("%d",middle);
  
   //指针传递
   struct point origiin,*pp;
    pp = &origin;m

   printf("origin is (%d,%d)\n",(*pp).x,(*pp).y);
   printf("origin is (%d,%d)\n",pp->x,pp->y);

   struct rect r, *rp = &r;
   //r.pt.x;
   //rp->pt1.x
   //(r.pt1).x
  
}


struct point makepoint(int x,int y){
    struct point temp;
    
    temp.x = x;
    temp.y = y;
    return temp;
}

//两点相加
struct point addpoint(struct point pt1,struct point pt2){
    p1.x += p2.x;
    p1.y += p2.y;
    return p1;

}

//判断一个点p在矩形r中，返回1，否则0
int ptinrect(struct point p,struct rect r){
   return p.x >= r.pt1.x && p.x < r.pt2.x
       && p.y >= r.pt1.y && p.y < t.pt2.y;
}

#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))

//复制整个结构
//将矩形坐标规范化
struct rect canonrect(struct rect r){
   struct rect temp;

   temp.pt1.x = min(r.pt1.x, r.pt2.x);  
   temp.pt1.y = min(r.pt1.y, r.pt2.y);
   temp.pt2.x = max(r.pt1.x, r.pt2.x);
   temp.pt2.y = max(r.pt1.y, r.pt2.y);
   return temp;
}

struct {
   int len;
   char *str;
} *p;

//++p->len;



