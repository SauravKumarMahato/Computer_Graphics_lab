#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<math.h>

static int LEFT= 1, RIGHT =2, BOTTOM =4, TOP =8 ;
static int  Xwmin, Ywmin, Xwmax, Ywmax;


int code_generate( int x, int y ){
    int code = 0 ;

    if( x < Xwmin)
        code = code|LEFT ;
    if (x > Xwmax)
        code = code|RIGHT;
    if ( y > Ywmax )
        code = code|TOP;
    if (y < Ywmin)
        code = code|BOTTOM;

    return code ;
}

int main()
{

	int gd = DETECT,gm;
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");

    int x1, y1, x2, y2 ;
    float m = 0 ;

    int temp_code1 = 0, temp_code2 = 0 ;

    int flag = 0 ;

    printf("End points: \n");
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2 );

    m = float((y2-y1)/(x2-x1));

    printf("Enter the value of windows co-ordinate: \n");
    scanf("%d%d%d%d", &Xwmin, &Ywmin, &Xwmax, &Ywmax);

    temp_code1 = code_generate(x1,y1);
    temp_code2 = code_generate(x2,y2);

    rectangle(Xwmin, Ywmin, Xwmax, Ywmax);

    // making line
    line(x1,y1,x2,y2);

    while(1){
        if (temp_code1 & temp_code2 != 0 ){
            break;
        }
        else if(temp_code1== 0 && temp_code2 == 0){
            flag =1 ;
            break;
        }
        else{
            int x, y , temp;
            if (temp_code1 == 0 )
                temp  = temp_code2;
            else    
                temp = temp_code1;
            
            if ( temp & LEFT){
                x = Xwmin ;
                y = y1 + m*(x- x1);
            }
            else if ( temp & RIGHT){
                x = Xwmax ;
                y = y1 + m*(x- x1);
            }
            else if ( temp & BOTTOM){
                y = Ywmin;
                x = x1 + float((y-y1)/m);
            }
            else{
                y = Ywmax;
                x = x1 + float((y-y1)/m);
            }
        

            if (temp == temp_code1 ){
                x1 = x;
                y1 = y;

                temp_code1 = code_generate(x1, y1 );

            }
            else{
                x2 = x ;
                y2 = y ;

                temp_code2 = code_generate(x2,y2);
            }

        }
    }

    printf("After clipping");

    if(flag ==1 ){
        delay(5000);
        cleardevice();
    }



    rectangle(Xwmin, Ywmin, Xwmax, Ywmax);
    setcolor(RED);
    line(x1,y1,x2,y2);


    getch(); // Wait for a key press
	closegraph();
    return 0;
}
