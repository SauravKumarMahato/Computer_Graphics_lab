// RELECTION ABOUT Y = X AND Y = -X 
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<math.h>

struct Triangle{
	int x1, y1;
	int x2, y2; 
	int x3, y3 ;
};

void reflection_x(struct Triangle tri){
	struct Triangle temp_tri;

	int trans_vect[3][3] = {0,1,0,1,0,0,0,0,1}; // about y = x ( y= mx + c)


	temp_tri.x1 = trans_vect[0][0]*(tri.x1-320) + trans_vect[0][1]*(240-tri.y1) + trans_vect[0][2]*1;
	temp_tri.y1 = trans_vect[1][0]*(tri.x1-320) + trans_vect[1][1]*(240-tri.y1) + trans_vect[1][2]*1;

	temp_tri.x2 = trans_vect[0][0]*(tri.x2-320) + trans_vect[0][1]*(240-tri.y2) + trans_vect[0][2]*1;
	temp_tri.y2 = trans_vect[1][0]*(tri.x2-320) + trans_vect[1][1]*(240-tri.y2) + trans_vect[1][2]*1;

	temp_tri.x3 = trans_vect[0][0]*(tri.x3-320) + trans_vect[0][1]*(240-tri.y3) + trans_vect[0][2]*1;
	temp_tri.y3 = trans_vect[1][0]*(tri.x3-320) + trans_vect[1][1]*(240-tri.y3) + trans_vect[1][2]*1;


	temp_tri.x1 += 320;
	temp_tri.y1 = 240-temp_tri.y1;

	temp_tri.x2 += 320;
	temp_tri.y2 = 240-temp_tri.y2;

	temp_tri.x3 += 320;
	temp_tri.y3 = 240 - temp_tri.y3;


    // rotated triangle plot 
	printf("%s\n","Reflection about y = x");
	setcolor(GREEN);
	line(temp_tri.x1,temp_tri.y1,temp_tri.x2, temp_tri.y2 );
	line(temp_tri.x2,temp_tri.y2,temp_tri.x3, temp_tri.y3 );
	line(temp_tri.x3,temp_tri.y3,temp_tri.x1, temp_tri.y1 );

}

void reflection_y(struct Triangle tri){
	struct Triangle temp_tri;

	int trans_vect[3][3] = {0,-1,0,-1,0,0,0,0,1}; // about y = -x ( y= mx + c)


	temp_tri.x1 = trans_vect[0][0]*(tri.x1-320) + trans_vect[0][1]*(240-tri.y1) + trans_vect[0][2]*1;
	temp_tri.y1 = trans_vect[1][0]*(tri.x1-320) + trans_vect[1][1]*(240-tri.y1) + trans_vect[1][2]*1;

	temp_tri.x2 = trans_vect[0][0]*(tri.x2-320) + trans_vect[0][1]*(240-tri.y2) + trans_vect[0][2]*1;
	temp_tri.y2 = trans_vect[1][0]*(tri.x2-320) + trans_vect[1][1]*(240-tri.y2) + trans_vect[1][2]*1;

	temp_tri.x3 = trans_vect[0][0]*(tri.x3-320) + trans_vect[0][1]*(240-tri.y3) + trans_vect[0][2]*1;
	temp_tri.y3 = trans_vect[1][0]*(tri.x3-320) + trans_vect[1][1]*(240-tri.y3) + trans_vect[1][2]*1;


	temp_tri.x1 += 320;
	temp_tri.y1 = 240-temp_tri.y1;

	temp_tri.x2 += 320;
	temp_tri.y2 = 240-temp_tri.y2;

	temp_tri.x3 += 320;
	temp_tri.y3 = 240 - temp_tri.y3;


    // rotated triangle plot 
	printf("%s\n","Reflection about  y = -x ");
	setcolor(GREEN);
	line(temp_tri.x1,temp_tri.y1,temp_tri.x2, temp_tri.y2 );
	line(temp_tri.x2,temp_tri.y2,temp_tri.x3, temp_tri.y3 );
	line(temp_tri.x3,temp_tri.y3,temp_tri.x1, temp_tri.y1 );

}



int main()
{
	struct Triangle tri;
	struct Triangle temp;

	int X, Y;
	int gd = DETECT,gm;
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");

	// triangle coordinate set 
	tri.x1 = 340;
	tri.y1 = 190;
	tri.x2 = 350;
	tri.y2 = 160;
	tri.x3 = 370;
	tri.y3 = 180;

	// axis plot
    line(320,0,320,480);
    line(0,240,640,240);

    // triangle plot 
	line(tri.x1,tri.y1,tri.x2, tri.y2 );
	line(tri.x2,tri.y2,tri.x3, tri.y3 );
	line(tri.x3,tri.y3,tri.x1, tri.y1 );

	// delay 
	delay(2000);
	
	// reflection about (y = x)
    reflection_x(tri);

	// delay 
	delay(2000);
	
	// reflection about (y = -x)
    reflection_y(tri);


    getch(); // Wait for a key press
	closegraph();
    return 0;
}
