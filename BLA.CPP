// BLA ALGORITHM TO DRAW LINE

#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<math.h>


int main()
{

    int x0, y0, x1, y1, dx, dy ; 
    int p0 = 0 , k = 0, a= 0 , b = 0 ;

	int gd = DETECT,gm;
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");

    printf("Enter two points for line: ");
    scanf("%d%d%d%d", &x0, &y0, &x1, &y1);

    dx = abs(x1 - x0) ;
    dy = abs(y1 - y0) ;

    if (x1>x0){
        a = 1 ;
    }else{
        a = -1 ;
    }

    if(y1>y0){
        b = 1; 
    }else{
        b = -1 ;
    }


    if (dx >= dy){
        p0 = 2*dy - dx ;

        while(k <= dx ){
            putpixel(x0, y0, 5 ); 
            if(p0<=0){
                x0 = x0 + a ;
                y0 = y0 ;
            }else{
                x0 = x0 + a; 
                y0 = y0 + b ;
            }
            k++ ;
        }
    }else{
        p0 = 2*dx - dy ;
        k = 0 ;
        while(k <= dy ){
            putpixel(x0, y0, 5 ); 
            if(p0<=0){
                x0 = x0 ;
                y0 = y0 + b ;
            }else{
                x0 = x0 + a; 
                y0 = y0 + b ;
            }
            k++ ;
        }
    }

    getch(); 
	closegraph();
    return 0;
}
