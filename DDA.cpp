// DDA ALGORITHM TO DRAW LINE

#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<math.h>


int main()
{

    int x0, y0, x1, y1, dx, dy, steps ; 
    int x_inc , y_inc , k = 0 ;

	int gd = DETECT,gm;
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");

    printf("Enter two points for line: ");
    scanf("%d%d%d%d", &x0, &y0, &x1, &y1);

    dx = x1 - x0 ;
    dy = y1 - y0 ;

    if(abs(dx)  >= abs(dy))
        steps = abs(dx) ;
    else 
        steps = abs(dy) ;
    
    x_inc = dx/steps ;
    y_inc = dy/steps ;

    while( k <= steps ){
        putpixel(x0, y0, 5 );
        x0 = x0 + x_inc ;
        y0 = y0 + y_inc ;

        k++ ;
    }
       


    getch(); 
	closegraph();
    return 0;
}
