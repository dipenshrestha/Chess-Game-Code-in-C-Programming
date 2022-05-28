#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>
#define R(a) (int)(a+0.5)

int A[10][10]={0};
union REGS in,out;

/*To show mouse pointer */
void showmouseptr()
{
   in.x.ax=1;
   int86(0X33,&in,&out);
}

/*To hide mouse pointer */
void mousehide()
{
   in.x.ax=2;
   int86(0X33,&in,&out);
}

/*To get current mouse position*/
void getmousepos(int *button, int *x, int *y)
{
   in.x.ax=3;
   int86(0X33,&in,&out);
   *button=out.x.bx;
   *x=out.x.cx;
   *y=out.x.dx;
}

/*Function to clear the Array */
void cleararray(int A[10][10])
{
	int i,j;
	for(i=1;i<=8;i++)
	for(j=1;j<=8;j++)
	A[i][j]=0;
}

/*Function to Draw Line using DDL Algorithm */
void line1(int xa,int ya,int xb,int yb,int c)
{
	int dx,dy,x,y,i,steps,xi,yi;
	dx=xb-xa;
	dy=yb-ya;
	x=xa;
	y=ya;
	if(abs(dx)>abs(dy))
	{
		steps=abs(dx);
	}
	else
	{
		steps=abs(dy);
	}
	xi=dx/(float)steps;
	yi=dy/(float)steps;
	putpixel (R(x),R(y),c);
	for(i=0;i<steps;i++)
	{
		x=x+xi;
		y=y+yi;
		putpixel (R(x),R(y),c);
	}
}
/*Function to draw Chess Board */
void createboard(int x,int y)
{
	int i;
	for(i=0;i<=8;i++)
	{
		line1(x,50,x,450,8);
		line1(50,y,450,y,8);
		x=x+50;
		y=y+50;
	}
}

/*Function to color Chess Board */
void colorboard(int x1,int y1)
{
	int x,y,i,j;
	x=x1;
	for(i=1;i<=8;i++)
	{
	y=y1;
	for(j=1;j<=8;j++)
	{
		if(i%2!=0)
		{
			setfillstyle(SOLID_FILL,WHITE);
			floodfill(x,y,8);
			setfillstyle(SOLID_FILL,BLACK);
			floodfill(x,y+50,8);
		}
		else
		{
			setfillstyle(SOLID_FILL,BLACK);
			floodfill(x,y,8);
			setfillstyle(SOLID_FILL,WHITE);
			floodfill(x,y+50,8);
		}
		y=y+100;
	}
	x=x+50;
   }

}

/*Function to create ROOK */
void rook(int x,int y)
{
	int a,b;
	a=x;b=y;
	if(x>=10 && y>=10)
		{
		a=(x/50);
		b=(y/50);
		}
	a=a*50;
	b=b*50;

	line(5+a,5+b,5+8+a,5+b);  //left top
	line(5+8+8+a,5+b,5+8+8+8+a,5+b); //middle top
	line(5+8+8+8+8+a,5+b,5+8+8+8+8+8+a,5+b);//right top
	line(5+a,5+b,5+a,5+5+b);//left 2
	line(5+8+a,5+b,5+8+a,5+5+b); //lm 2
	line(5+8+8+a,5+b,5+8+8+a,5+5+b); //lmm2
	line(5+8+8+8+a,5+b,5+8+8+8+a,5+5+b);//rmm2
	line(5+8+8+8+8+a,5+b,5+8+8+8+8+a,5+5+b); //rm 2
	line(5+8+8+8+8+8+a,5+b,5+8+8+8+8+8+a,5+5+b);// right 2
	line(5+8+a,5+5+b,5+8+8+a,5+5+b); //l 3
	line(5+8+8+8+a,5+5+b,5+8+8+8+8+a,5+5+b); //r 3
	line(5+a,5+5+b,5+10+a,5+5+10+b); //left 4
	line(5+10+a,5+5+10+b,5+10+20+a,5+5+10+b); //middle 4
	line(5+10+20+a,5+5+10+b,5+10+20+10+a,5+5+b); //right 4
	line(5+10+a,5+5+10+b,5+10+a,5+5+10+10+b);//left 5
	line(5+10+20+a,5+5+10+b,5+10+20+a,5+5+10+10+b); //right 5
	line(5+10+a,5+5+10+10+b,5+10+20+a,5+5+10+10+b);//middle 5
	line(5+10+a,5+5+10+10+b,5+a,5+5+10+10+10+b);//left 6
	line(5+10+20+a,5+5+10+10+b,5+10+20+10+a,5+5+10+10+10+b);//right 6
	line(5+a,5+5+10+10+10+b,5+8+8+8+8+8+a,5+5+10+10+10+b);//middle 6
	line(5+a,5+5+10+10+10+b,5+a,5+5+10+10+10+5+b);//left 7
	line(5+8+8+8+8+8+a,5+5+10+10+10+b,5+8+8+8+8+8+a,5+5+10+10+10+5+b);//right 7
	line(5+a,5+5+10+10+10+5+b,5+8+8+8+8+8+a,5+5+10+10+10+5+b);//middle 7
}

/*Function to create KNIGHT */
void knight(int x,int y)
{
	int a,b;
	a=x;b=y;
	if(x>=10 && y>=10)
		{
		a=(x/50);
		b=(y/50);
		}
	a=a*50;
	b=b*50;
	line(5+20+a,5+b,5+20-2+a,5+6+b);//ghoda ko tuppi left
	line(5+20-2+a,5+6+b,5+20-2-18+a,5+6+11+b);//ghoda ko aankha ra nak vako part
	line(5+a,5+6+11+b,5+6+a,5+6+11+10+b);//ghoda ko nakk mukh
	line(5+6+a,5+6+11+10+b,5+6+2+a,5+6+11+10-5+b);//ghoda ko chin
	line(5+6+2+a,5+6+11+10-5+b,5+6+2+12+a,5+6+11+10-5-6+b);//ghoda ko chin mathi
	line(5+6+2+12+a,5+6+11+10-5-6+b,5+6+2+12+1+a,5+6+11+10-5-6+7+b);//ghoda ko larynx
	line(5+6+2+12+1+a,5+6+11+10-5-6+7+b,5+6+2+12+1-7+a,5+36+b);//ghoda ko ghati
	line(5+6+2+12+1-7+16+a,5+36+b,5+6+2+12+1-7+16-3+a,5+36-20+b);//ghoda ko hair
	line(5+6+2+12+1-7+16-3+a,5+36-20+b,5+6+2+12+1-7+16-3-2+a,5+36-20-6+b); //ghoda ko tauko
	line(5+6+2+12+1-7+16-3-2+a,5+36-20-6+b,5+20+a,5+b );//tuppi right
	line(5+6+2+12+1-7+a,5+36+b,5+6+2+12+1-7+16+a,5+36+b);//tala ko rectangle ko top
	line(5+6+2+12+1-7+16+a,5+36+b,5+6+2+12+1-7+16+a,5+36+3+b);//tala ko rectangle ko right
	line(5+6+2+12+1-7+a,5+36+b,5+6+2+12+1-7+a,5+36+3+b);//tala ko rectangle ko left
	line(5+6+2+12+1-7+a,5+36+3+b,5+6+2+12+1-7+16+a,5+36+3+b);//tala ko rectangle ko bottom
	line(5+6+2+12+1-7-5+a,5+36+3+b,5+6+2+12+1-7+16+3+a,5+36+3+b);//sabse tala ko rectangle ko top
	line(5+6+2+12+1-7-5+a,5+36+3+b,5+6+2+12+1-7-5+a,5+36+3+3+b);//sabse tala ko rectangle ko left
	line(5+6+2+12+1-7-5+a,5+36+3+3+b,5+6+2+12+1-7+16+3+a,5+36+3+3+b);//sabse tala ko rectangle ko bottom
	line(5+6+2+12+1-7+16+3+a,5+36+3+3+b,5+6+2+12+1-7+16+3+a,5+36+3+b);//sabse tala ko rectangle ko right
	circle(5+20-2-18+4+a,5+6+11+1+b,2);//ghoda ko naak
	arc(5+20-2+a,5+6+6+b,30,150,2); //ghoda ko aankha
}


/*Function to create BISHOP */
void bishop(int x,int y)
{

	int a,b;
	a=x;b=y;
	if(x>=10 && y>=10)
		{
		a=(x/50);
		b=(y/50);
		}
	a=a*50;
	b=b*50;
	line(25+a,3+b,10+a,3+3+b);//left hat
	line(25+a,3+b,50-10+a,3+3+b);//right hat
	line(10+a,3+3+b,15+a,3+3+17+b);//hat left bottom part
	line(50-10+a,3+3+b,50-10-5+a,3+3+17+b); //hat right bottom part
	line(25+a,3+3+b,25+2+a,3+3+b);//plus ko mathi right
	line(25+a,3+3+b,25-2+a,3+3+b); //plus ko mathi left
	line(25+2+a,3+3+b,25+2+a,3+3+4+b);//plus ko 2nd right
	line(25-2+a,3+3+b,25-2+a,3+3+4+b);//plus ko 2nd left
	line(25-2+a,3+3+4+b,25-2-4+a,3+3+4+b); //plus ko 3rd left
	line(25+2+a,3+3+4+b,25+2+4+a,3+3+4+b);//plus ko 3rd right
	line(25-2-4+a,3+3+4+b,25-2-4+a,3+3+4+4+b); //plus ko 4th left
	line(25+2+4+a,3+3+4+b,25+2+4+a,3+3+4+4+b);//plus ko 4th right
	line(25-2-4+a,3+3+4+4+b,25-2-4+4+a,3+3+4+4+b); //plus ko 5th left
	line(25+2+4+a,3+3+4+4+b,25+2+4-4+a,3+3+4+4+b);//plus ko 5th right
	line(25-2-4+4+a,3+3+4+4+b,25-2-4+4+a,3+3+4+4+5+b);//plus ko 6th left
	line(25+2+4-4+a,3+3+4+4+b,25+2+4-4+a,3+3+4+4+5+b);//plus ko 6th right
	line(25-2-4+4+a,3+3+4+4+5+b,25+2+4-4+a,3+3+4+4+5+b);//base ko line
	ellipse(10+7+a,3+3+17+7+b,110,180+45+15,6,8);//tauko left part ghatauna milxa
	ellipse(50-10-7+a,3+3+17+7+b,300,360+70,6,8);//tauko right part
	line(10+7-1+a,3+3+17+7+8+b,10+7-8+a,3+3+17+7+8+2+b); //left wala collor mathi
	line(50-10-7+1+a,3+3+17+7+8+b,50-10-7+8+a,3+3+17+7+8+2+b);  //right wala collor mathi
	line(10+7-8+a,3+3+17+7+8+2+b,10+7-1-8+8+a,3+3+17+7+8+2+2+b); //left wala collor tala
	line(50-10-7+8+a,3+3+17+7+8+2+b,50-10-7+1+8-8+a,3+3+17+7+8+2+2+b);//right wala collor tala
	ellipse(10+7-8+a,3+3+17+7+8+2+2+b,280,360,7,3);  //jiu left
	ellipse(50-10-7+8+a,3+3+17+7+8+2+2+b,180,265,7,3);   //jiu right
	line(10+7-8+a,3+3+17+7+8+2+2+3+b,10+7-8+a,3+3+17+7+8+2+2+3+3+b); //tala ko rectangle ko left
	line(50-10-7+8+a,3+3+17+7+8+2+2+3+b,50-10-7+8+a,3+3+17+7+8+2+2+3+3+b);//tala ko rectangle ko right
	line(10+7-8+a,3+3+17+7+8+2+2+3+3+b,50-10-7+8+a,3+3+17+7+8+2+2+3+3+b); //tala ko rectangle ko base part
}



/*
Function to create PAWN */
void pawn(int x,int y)
{
	int a,b;
	a=x;b=y;
	if(x>=10 && y>=10)
		{
		a=(x/50);
		b=(y/50);
		}
	a=a*50;
	b=b*50;
	arc(25+a,7+20+b,0,180,8);//helmet
	circle(25+a,15+b,6);
	line(25-8+a,7+12+7+b,25-8+a,7+5+7+10+b);//left side ko 2nd
	line(25+8+a,7+7+10+2+b,25+8+a,7+5+7+10+b);//right side ko 2nd
	line(25-8+a,7+5+7+10+b,25-8+a,7+5+7+10+10+b);//left side ko 3rd
	line(25+8+a,7+5+7+10+b,25+8+a,7+5+7+10+10+b);//right side ko 3rd
	line(25-8+a,7+5+7+10+10+b,25+8+a,7+5+7+10+10+b);// 3rd ko bottom
	line(25-8+a,7+5+7+10+10+b,25-8-8+a,7+5+7+10+10+8+b); //left slant
	line(25+8+a,7+5+7+10+10+b,25+8+8+a,7+5+7+10+10+8+b);// right slant
	line(25-8-7+a,7+5+7+10+10+8+b,25+8+7+a,7+5+7+10+10+8+b);//bottom
}


/*Function to create KING */
void king(int x,int y)
{
	int a,b;
	a=x;b=y;
	if(x>=10 && y>=10)
		{
		a=(x/50);
		b=(y/50);
		}
	a=a*50;
	b=b*50;
	line(5+8+8+2+a,1+b,5+8+8+6+a,1+b);//top left point
	line(5+8+8+2+a,1+b,5+8+8+2+a,8+b);//top right point
	line(28+a,1+b,28+a,8+b);//left top bata tala
	line(23+a,8+b,16+a,8+b);//right top bata tala
	line(28+a,8+b,35+a,8+b);//right bata agadi
	line(16+a,8+b,16+a,12+b); //left bata tala
	line(35+a,8+b,35+a,12+b); //right bata tala
	line(16+a,12+b,23+a,12+b); //left bata bicha ma
	line(35+a,12+b,28+a,12+b); //right bata bicha ma
	line(23+a,12+b,23+a,19+b);//+ ko tala ko left point
	line(28+a,12+b,28+a,19+b);//+ ko tala ko right point
	line(23+a,18+b,10+a,25+b);//slanted right line
	line(10+a,25+b,20+a,28+b);//slanted right line
	line(28+a,19+b,41+a,25+b);//slanted  right
	line(41+a,25+b,31+a,28+b);//slanted right
	ellipse(24+a,35+b,125,200,7,8);//left curve
	ellipse(28+a,35+b,350,50,7,8);//right curve
	line(18+a,36+b,7+a,49+b);//left base point
	line(34+a,36+b,45+a,49+b);//right base point
	line(7+a,49+b,45+a,49+b); //base
	line(10+a,47+b,42+a,47+b);
	line(11+a,45+b,40+a,45+b);//line base mathi ko
}

/*Function to create QUEEN */
void queen(int x,int y)
{
	int a,b;
	a=x;b=y;
	if(x>=10 && y>=10)
		{
		a=(x/50);
		b=(y/50);
		}
	a=a*50;
	b=b*50;
	line(25+a,1+b,23+a,10+b);//1st top  chuchho point
	line(25+a,1+b,27+a,10+b);//left base wala point top ko chucho bata
	line(23+a,10+b,20+a,5+b);//right base wala point top ko chucho bata
	line(27+a,10+b,31+a,5+b);//2nd left chucho point left
	line(20+a,5+b,22+a,13+b);//2nd right chucho point right
	line(31+a,5+b,29+a,13+b);//left base point from 2nd ko chucho
	line(22+a,13+b,17+a,8+b);//right base point from 2nd ko chucho
	line(29+a,13+b,34+a,8+b);//3rd left chucho wala point
	line(17+a,8+b,22+a,17+b);//left base point 3rd ko chucho bata
	line(34+a,8+b,29+a,17+b);//right base point from 3rd ko chucho
	ellipse(25+a,25+b,110,250,5,8);//quuen curved body left
	ellipse(26+a,25+b,305,63,5,8);//right curved body
	line(24+a,33+b,19+a,33+b);//left hand part
	line(19+a,33+b,19+a,35+b);
	line(19+a,35+b,24+a,35+b);
	line(28+a,33+b,33+a,33+b);//right hand part
	line(33+a,33+b,33+a,35+b);
	line(33+a,35+b,25+a,35+b);
	ellipse(13+a,40+b,300,47,8,9);//bottom left ko curve
	ellipse(39+a,40+b,150,240,8,9);//bottom right ko curve
	line(17+a,49+b,35+a,49+b);
}



/*Function to put Rooks on chess board */
void putrooks(int x1,int y1)
{
   int i,x,y;
   for(i=0;i<4;i++)
   {
	x=x1;y=y1;
	if(i==0)
	{
		x=1;
		y=1;
	}
	else if(i==1)
	{
		x=1;
		y=8;
	}
	else if(i==2)
	{
		x=8;
		y=1;
	}
	else if(i==3)
	{
		x=8;
		y=8;
	}
	rook(x,y);
	if(i%2==0)
	{
		A[x][y]=50;
	}
	else
	{
		A[x][y]=51;
	}
   }
}

/*Function to put Knights on chess board */
void putknights(int x1,int y1)
{
   int i,x,y;
   for(i=0;i<4;i++)
   {
	x=x1;y=y1;
	if(i==0)
	{
		x=2;
		y=1;
	}
	else if(i==1)
	{
		x=2;
		y=8;
	}
	else if(i==2)
	{
		x=7;
		y=1;
	}
	else if(i==3)
	{
		x=7;
		y=8;
	}
	knight(x,y);
	if(i%2==0)
	{
		A[x][y]=40;
	}
	else
	{
		A[x][y]=41;
	}
   }
}

/*Function to put Bishops on chess board */
void putbishops(int x1,int y1)
{
   int i,x,y;
   for(i=0;i<4;i++)
   {
	x=x1;y=y1;
	if(i==0)
	{
		x=3;
		y=1;
	}
	else if(i==1)
	{
		x=3;
		y=8;
	}
	else if(i==2)
	{
		x=6;
		y=1;
	}
	else if(i==3)
	{
		x=6;
		y=8;
	}
	bishop(x,y);
	if(i%2==0)
	{
		A[x][y]=30;
	}
	else
	{
		A[x][y]=31;
	}
   }
}

/*Function to put Pawns on chess board */
void putpawns(int x1,int y1)
{
	int i,j,x,y;
	x=x1;y=y1+2;
	for(i=0;i<2;i++)
	{
		x=1;
		for(j=0;j<8;j++)
		{
			pawn(x,y);
			if(i==0)
			{
				A[x][y]=60;
			}
			else
			{
				A[x][y]=61;
			}
			x=x+1;
		}
		y=y+5;
	}
}

/*Function to put Kings on chess board */
void putkings(int x1,int y1)
{
   int i,x,y;
   for(i=0;i<2;i++)
   {
	x=x1;y=y1;
	if(i==0)
	{
		x=5;
		y=1;
	}
	else if(i==1)
	{
		x=5;
		y=8;
	}
	king(x,y);
	if(i==0)
	{
		A[x][y]=10;
	}
	else
	{
		A[x][y]=11;
	}
   }
}

/*Function to put Queens on chess board */
void putqueens(int x1,int y1)
{
   int i,x,y;
   for(i=0;i<2;i++)
   {
	x=x1;y=y1;
	if(i==0)
	{
		x=4;
		y=1;
	}
	else if(i==1)
	{
		x=4;
		y=8;
	}
	queen(x,y);
	if(i==0)
	{
		A[x][y]=20;
	}
	else
	{
		A[x][y]=21;
	}
   }
}

/*Functions to return mid-point of any box for any
  entered coordinate inside the box */
int midx(int x)
{
	int i,minx,x2;
	minx=x;
	for(i=50;i<=400;i=i+50)
	{
		if((x-i)<minx && (x-i)>=0)
		{
			minx=x-i;
			x2=(x-minx+25);
		}
	}
	return x2;
}

int midy(int y)
{
	int i,miny,y2;
	miny=y;
	for(i=50;i<=400;i=i+50)
	{
		if((y-i)<miny && (y-i)>=0)
		{
			miny=y-i;
			y2=(y-miny+25);
		}
	}
	return y2;
}

/*Function to fill a box with its background color */
int fillbox(int x,int y,int color)
{
	int i,j;
	setfillstyle(SOLID_FILL,color);
	for(i=x-23;i<x+24;i++)
	{
		for(j=y-23;j<y+24;j++)
		{
			floodfill(i,j,color);
		}
	}
	return 0;
}

/*Function to highlight the selected piece
  box and its valid positions */
int colorbox(int x,int y,int c)
{
	line1(x-23,y-23,x-23,y+23,c);
	line1(x-21,y+23,x+21,y+23,c);
	line1(x+23,y+23,x+23,y-23,c);
	line1(x+21,y-23,x-21,y-23,c);
	return 0;
}

/*Function to create RESTART and EXIT Buttons on GAME OVER */
void gameoverbuttons()
{
	setcolor(15);
	line1(210,250,270,250,8);
	line1(270,250,270,280,8);
	line1(270,280,210,280,8);
	line1(210,280,210,250,8);
	setfillstyle(SOLID_FILL,CYAN);
	floodfill(215,255,8);
	outtextxy(213,265,"RESTART");
	line1(290,250,350,250,8);
	line1(350,250,350,280,8);
	line1(350,280,290,280,8);
	line1(290,280,290,250,8);
	setfillstyle(SOLID_FILL,RED);
	floodfill(295,255,8);
	outtextxy(305,265,"EXIT");
}

/*Function to check whether the king is CHECKMATED or not */
int win(int x1,int y1,int x2,int y2)
{
	int a=A[x1/50][y1/50];
	int b=A[x2/50][y2/50];
	if((a%2!=0 && b==10)||(a%2==0 && b==11))
	{
		return 1;
	}
	else return 0;
}

void instructions()
{
	clearviewport();
	setfillstyle(SOLID_FILL,3);
	floodfill(10,10,8);
	settextstyle(DEFAULT_FONT,0,2);
	outtextxy(100,40,"-------------");
	outtextxy(100,60," HOW TO PLAY");
	outtextxy(100,80,"-------------");
	settextstyle(DEFAULT_FONT,0,1);
	outtextxy(50,120,"1. Right Click on any piece to select it.");
	outtextxy(50,140,"2. Left Click on any valid position to move the selected piece there.");
	outtextxy(50,160,"3. Left Click on CLEAR SELECTION button to clear the selected piece.");
	outtextxy(50,180,"4. TURN box shows who's turn, currently is.");
	outtextxy(50,200,"5. Left click on INSTRUCTIONS button to see how to play the game.");
	outtextxy(50,220,"6. Left Click on RESTART button to restart or reset the game.");
	outtextxy(50,240,"7. Left Click on EXIT button to exit the game.");
	outtextxy(180,280," *** BEST OF LUCK ***");
	outtextxy(150,300,"...Press any key to continue...");
	getch();
}

/*Function to exit the game */
void exitgame()
{
	    int i;
	    cleardevice();
	    setfillstyle(SOLID_FILL,15);
	    floodfill(10,10,7);
	    setbkcolor(CYAN);
	    setcolor(RED);
	    outtextxy(200,200,"...Exiting...Please Wait...");
	    line1(110,223,512,223,8);
	    line1(512,223,512,240,8);
	    line1(512,240,110,240,8);
	    line1(110,240,110,223,8);
	    gotoxy(15,15);
	    for(i=0;i<50;i++)
	    {
			setcolor(CYAN);
			printf(" ");
			outtextxy(50,350,"SUPERVISED BY :");
			outtextxy(50,365,"Shiva Prasad Mahato");
			outtextxy(50,410,"Computer Engineering");
			outtextxy(450,350,"MADE BY :");
			outtextxy(450,365,"Anjan Prajapati");
			outtextxy(450,380,"Dipen Shrestha");
			outtextxy(450,395,"Samesh Bajracharya");
			outtextxy(450,410,"Sushant Twayana");
			outtextxy(450,425,"C.E.- 3RD SEMESTER");
			delay(40);
	    }
	    closegraph();
	    exit(0);
}

/*Function to decide valid positions for ROOK */
void rookpos(int x,int y,int i)
{
	int x1,y1,c,a,a1;
	a1=A[x/50][y/50];
	x1=x;y1=y;
	a=A[(x1+50)/50][y1/50];
	if(a!=0 && ((a1%2==0 && a%2!=0) ||(a1%2!=0 && a%2==0)))
	{
		c=getpixel(x1+50-18,y1);
		if(i==1)
		colorbox(x1+50,y1,12);
		else if(i==0)
		colorbox(x1+50,y1,c);
	}
	while(A[(x1+50)/50][y1/50]==0 && x1+50<450)
	{
		c=getpixel(x1+50,y1);
		if(i==1)
		colorbox(x1+50,y1,10);
		else if(i==0)
		colorbox(x1+50,y1,c);
		x1=x1+50;
		a=A[(x1+50)/50][y1/50];
		if(a!=0 && ((a1%2==0 && a%2!=0) ||(a1%2!=0 && a%2==0)))
		{
			c=getpixel(x1+50-18,y1);
			if(i==1)
			colorbox(x1+50,y1,12);
			else if(i==0)
			colorbox(x1+50,y1,c);
		}
	}
	x1=x;y1=y;
	a=A[(x1-50)/50][y1/50];
	if(a!=0 && ((a1%2==0 && a%2!=0) ||(a1%2!=0 && a%2==0)))
	{
		c=getpixel(x1-50-18,y1);
		if(i==1)
		colorbox(x1-50,y1,12);
		else if(i==0)
		colorbox(x1-50,y1,c);
	}
	while(A[(x1-50)/50][y1/50]==0 && x1-50>50)
	{
		c=getpixel(x1-50,y1);
		if(i==1)
		colorbox(x1-50,y1,10);
		else if(i==0)
		colorbox(x1-50,y1,c);
		x1=x1-50;
		a=A[(x1-50)/50][y1/50];
		if(a!=0 && ((a1%2==0 && a%2!=0) ||(a1%2!=0 && a%2==0)))
		{
			c=getpixel(x1-50-18,y1);
			if(i==1)
			colorbox(x1-50,y1,12);
			else if(i==0)
			colorbox(x1-50,y1,c);
		}
	}
	x1=x;y1=y;
	a=A[x1/50][(y1+50)/50];
	if(a!=0 && ((a1%2==0 && a%2!=0) ||(a1%2!=0 && a%2==0)))
	{
		c=getpixel(x1-18,y1+50);
		if(i==1)
		colorbox(x1,y1+50,12);
		else if(i==0)
		colorbox(x1,y1+50,c);
	}
	while(A[x1/50][(y1+50)/50]==0 && y1+50<450)
	{
		c=getpixel(x1-18,y1+50);
		if(i==1)
		colorbox(x1,y1+50,10);
		else if(i==0)
		colorbox(x1,y1+50,c);
		y1=y1+50;
		a=A[x1/50][(y1+50)/50];
		if(a!=0 && ((a1%2==0 && a%2!=0) ||(a1%2!=0 && a%2==0)))
		{
			c=getpixel(x1-18,y1+50);
			if(i==1)
			colorbox(x1,y1+50,12);
			else if(i==0)
			colorbox(x1,y1+50,c);
		}
	}
	x1=x;y1=y;
	a=A[x1/50][(y1-50)/50];
	if(a!=0 && ((a1%2==0 && a%2!=0) ||(a1%2!=0 && a%2==0)))
	{
		c=getpixel(x1-18,y1-50);
		if(i==1)
		colorbox(x1,y1-50,12);
		else if(i==0)
		colorbox(x1,y1-50,c);
	}
	while(A[x1/50][(y1-50)/50]==0 && y1-50>50)
	{
		c=getpixel(x1,y1-50);
		if(i==1)
		colorbox(x1,y1-50,10);
		else if(i==0)
		colorbox(x1,y1-50,c);
		y1=y1-50;
		a=A[x1/50][(y1-50)/50];
		if(a!=0 && ((a1%2==0 && a%2!=0) ||(a1%2!=0 && a%2==0)))
		{
			c=getpixel(x1-18,y1-50);
			if(i==1)
			colorbox(x1,y1-50,12);
			else if(i==0)
			colorbox(x1,y1-50,c);
		}
	}
}

/*Function to decide valid positions for KNIGHT */
void knightpos(int x,int y,int i)
{
	int a1,a,c,j,x1,y1;
	a1=A[x/50][y/50];
	for(j=8;j>=1;j--)
	{
		x1=x;
		y1=y;
		if(j==8)
		{
			x1=x1+50;
			y1=y1-100;
		}
		else if(j==7)
		{
			x1=x1+100;
			y1=y1-50;
		}
		else if(j==6)
		{
			x1=x1+100;
			y1=y1+50;
		}
		else if(j==5)
		{
			x1=x1+50;
			y1=y1+100;
		}
		else if(j==4)
		{
			x1=x1-50;
			y1=y1+100;
		}
		else if(j==3)
		{
			x1=x1-100;
			y1=y1+50;
		}
		else if(j==2)
		{
			x1=x1-100;
			y1=y1-50;
		}
		else if(j==1)
		{
			x1=x1-50;
			y1=y1-100;
		}
		a=A[x1/50][y1/50];
		if(x1>50 && x1<450 && y1>50 && y1<450)
		{
			if(a!=0 && ((a1%2==0 && a%2!=0) ||(a1%2!=0 && a%2==0)))
			{
				c=getpixel(x1-18,y1);
				if(i==1)
				colorbox(x1,y1,12);
				else if(i==0)
				colorbox(x1,y1,c);
			}
			else if(a==0)
			{
				c=getpixel(x1-18,y1);
				if(i==1)
				colorbox(x1,y1,10);
				else if(i==0)
				colorbox(x1,y1,c);
			}
		}
	}
}

/*Function to decide valid positions for BISHOP */
void bishoppos(int x,int y,int i)
{
	int x1,y1,c,a1,a;
	a1=A[x/50][y/50];
	x1=x;y1=y;
	a=A[(x1+50)/50][(y1-50)/50];
	if(a!=0 && ((a1%2==0 && a%2!=0) ||(a1%2!=0 && a%2==0)))
	{
		c=getpixel(x1+50-18,y1-50);
		if(i==1)
		colorbox(x1+50,y1-50,12);
		else if(i==0)
		colorbox(x1+50,y1-50,c);
	}
	while(A[(x1+50)/50][(y1-50)/50]==0 && x1+50<450 && y1-50>50)
	{
		c=getpixel(x1+50,y1-50);
		if(i==1)
		colorbox(x1+50,y1-50,10);
		else if(i==0)
		colorbox(x1+50,y1-50,c);
		x1=x1+50;
		y1=y1-50;
		a=A[(x1+50)/50][(y1-50)/50];
		if(a!=0 && ((a1%2==0 && a%2!=0) ||(a1%2!=0 && a%2==0)))
		{
			c=getpixel(x1+50-18,y1-50);
			if(i==1)
			colorbox(x1+50,y1-50,12);
			else if(i==0)
			colorbox(x1+50,y1-50,c);
		}
	}
	x1=x;y1=y;
	a=A[(x1-50)/50][(y1-50)/50];
	if(a!=0 && ((a1%2==0 && a%2!=0) ||(a1%2!=0 && a%2==0)))
	{
		c=getpixel(x1-50-18,y1-50);
		if(i==1)
		colorbox(x1-50,y1-50,12);
		else if(i==0)
		colorbox(x1-50,y1-50,c);
	}
	while(A[(x1-50)/50][(y1-50)/50]==0 && x1-50>50 && y1-50>50)
	{
		c=getpixel(x1-50-18,y1-50);
		if(i==1)
		colorbox(x1-50,y1-50,10);
		else if(i==0)
		colorbox(x1-50,y1-50,c);
		x1=x1-50;
		y1=y1-50;
		a=A[(x1-50)/50][(y1-50)/50];
		if(a!=0 && ((a1%2==0 && a%2!=0) ||(a1%2!=0 && a%2==0)))
		{
			c=getpixel(x1-50-18,y1-50);
			if(i==1)
			colorbox(x1-50,y1-50,12);
			else if(i==0)
			colorbox(x1-50,y1-50,c);
		}
	}
	x1=x;y1=y;
	a=A[(x1+50)/50][(y1+50)/50];
	if(a!=0 && ((a1%2==0 && a%2!=0) ||(a1%2!=0 && a%2==0)))
	{
		c=getpixel(x1+50-18,y1+50);
		if(i==1)
		colorbox(x1+50,y1+50,12);
		else if(i==0)
		colorbox(x1+50,y1+50,c);
	}
	while(A[(x1+50)/50][(y1+50)/50]==0 && x1+50<450 && y1+50<450)
	{
		c=getpixel(x1+50,y1+50);
		if(i==1)
		colorbox(x1+50,y1+50,10);
		else if(i==0)
		colorbox(x1+50,y1+50,c);
		x1=x1+50;
		y1=y1+50;
		a=A[(x1+50)/50][(y1+50)/50];
		if(a!=0 && ((a1%2==0 && a%2!=0) ||(a1%2!=0 && a%2==0)))
		{
			c=getpixel(x1+50-18,y1+50);
			if(i==1)
			colorbox(x1+50,y1+50,12);
			else if(i==0)
			colorbox(x1+50,y1+50,c);
		}
	}
	x1=x;y1=y;
	a=A[(x1-50)/50][(y1+50)/50];
	if(a!=0 && ((a1%2==0 && a%2!=0) ||(a1%2!=0 && a%2==0)))
	{
		c=getpixel(x1-50-18,y1+50);
		if(i==1)
		colorbox(x1-50,y1+50,12);
		else if(i==0)
		colorbox(x1-50,y1+50,c);
	}
	while(A[(x1-50)/50][(y1+50)/50]==0 && x1-50>50 && y1+50<450)
	{
		c=getpixel(x1-50,y1+50);
		if(i==1)
		colorbox(x1-50,y1+50,10);
		else if(i==0)
		colorbox(x1-50,y1+50,c);
		x1=x1-50;
		y1=y1+50;
		a=A[(x1-50)/50][(y1+50)/50];
		if(a!=0 && ((a1%2==0 && a%2!=0) ||(a1%2!=0 && a%2==0)))
		{
			c=getpixel(x1-50-18,y1+50);
			if(i==1)
			colorbox(x1-50,y1+50,12);
			else if(i==0)
			colorbox(x1-50,y1+50,c);
		}
	}
}

/*Function to decide valid positions for QUEEN */
void queenpos(int x,int y,int i)
{
	int x1,y1,c,a1,a;
	a1=A[x/50][y/50];
	x1=x;y1=y;
	a=A[(x1+50)/50][y1/50];
	if(a!=0 && ((a1%2==0 && a%2!=0) ||(a1%2!=0 && a%2==0)))
	{
		c=getpixel(x1+50-18,y1);
		if(i==1)
		colorbox(x1+50,y1,12);
		else if(i==0)
		colorbox(x1+50,y1,c);
	}
	while(A[(x1+50)/50][y1/50]==0 && x1+50<450)
	{
		c=getpixel(x1+50-18,y1);
		if(i==1)
		colorbox(x1+50,y1,10);
		else if(i==0)
		colorbox(x1+50,y1,c);
		x1=x1+50;
		a=A[(x1+50)/50][y1/50];
		if(a!=0 && ((a1%2==0 && a%2!=0) ||(a1%2!=0 && a%2==0)))
		{
			c=getpixel(x1+50-18,y1);
			if(i==1)
			colorbox(x1+50,y1,12);
			else if(i==0)
			colorbox(x1+50,y1,c);
		}
	}
	x1=x;y1=y;
	a=A[(x1-50)/50][y1/50];
	if(a!=0 && ((a1%2==0 && a%2!=0) ||(a1%2!=0 && a%2==0)))
	{
		c=getpixel(x1-50-18,y1);
		if(i==1)
		colorbox(x1-50,y1,12);
		else if(i==0)
		colorbox(x1-50,y1,c);
	}
	while(A[(x1-50)/50][y1/50]==0 && x1-50>50)
	{
		c=getpixel(x1-50-18,y1);
		if(i==1)
		colorbox(x1-50,y1,10);
		else if(i==0)
		colorbox(x1-50,y1,c);
		x1=x1-50;
		a=A[(x1-50)/50][y1/50];
		if(a!=0 && ((a1%2==0 && a%2!=0) ||(a1%2!=0 && a%2==0)))
		{
			c=getpixel(x1-50-18,y1);
			if(i==1)
			colorbox(x1-50,y1,12);
			else if(i==0)
			colorbox(x1-50,y1,c);
		}
	}
	x1=x;y1=y;
	a=A[x1/50][(y1+50)/50];
	if(a!=0 && ((a1%2==0 && a%2!=0) ||(a1%2!=0 && a%2==0)))
	{
		c=getpixel(x1-18,y1+50);
		if(i==1)
		colorbox(x1,y1+50,12);
		else if(i==0)
		colorbox(x1,y1+50,c);
	}
	while(A[x1/50][(y1+50)/50]==0 && y1+50<450)
	{
		c=getpixel(x1-18,y1+50);
		if(i==1)
		colorbox(x1,y1+50,10);
		else if(i==0)
		colorbox(x1,y1+50,c);
		y1=y1+50;
		a=A[x1/50][(y1+50)/50];
		if(a!=0 && ((a1%2==0 && a%2!=0) ||(a1%2!=0 && a%2==0)))
		{
			c=getpixel(x1-18,y1+50);
			if(i==1)
			colorbox(x1,y1+50,12);
			else if(i==0)
			colorbox(x1,y1+50,c);
		}
	}
	x1=x;y1=y;
	a=A[x1/50][(y1-50)/50];
	if(a!=0 && ((a1%2==0 && a%2!=0) ||(a1%2!=0 && a%2==0)))
	{
		c=getpixel(x1-18,y1-50);
		if(i==1)
		colorbox(x1,y1-50,12);
		else if(i==0)
		colorbox(x1,y1-50,c);
	}
	while(A[x1/50][(y1-50)/50]==0 && y1-50>50)
	{
		c=getpixel(x1,y1-50);
		if(i==1)
		colorbox(x1,y1-50,10);
		else if(i==0)
		colorbox(x1,y1-50,c);
		y1=y1-50;
		a=A[x1/50][(y1-50)/50];
		if(a!=0 && ((a1%2==0 && a%2!=0) ||(a1%2!=0 && a%2==0)))
		{
			c=getpixel(x1-18,y1-50);
			if(i==1)
			colorbox(x1,y1-50,12);
			else if(i==0)
			colorbox(x1,y1-50,c);
		}
	}
	//Diagonal
	x1=x;y1=y;
	a=A[(x1+50)/50][(y1-50)/50];
	if(a!=0 && ((a1%2==0 && a%2!=0) ||(a1%2!=0 && a%2==0)))
	{
		c=getpixel(x1+50-18,y1-50);
		if(i==1)
		colorbox(x1+50,y1-50,12);
		else if(i==0)
		colorbox(x1+50,y1-50,c);
	}
	while(A[(x1+50)/50][(y1-50)/50]==0 && x1+50<450 && y1-50>50)
	{
		c=getpixel(x1+50,y1-50);
		if(i==1)
		colorbox(x1+50,y1-50,10);
		else if(i==0)
		colorbox(x1+50,y1-50,c);
		x1=x1+50;
		y1=y1-50;
		a=A[(x1+50)/50][(y1-50)/50];
		if(a!=0 && ((a1%2==0 && a%2!=0) ||(a1%2!=0 && a%2==0)))
		{
			c=getpixel(x1+50-18,y1-50);
			if(i==1)
			colorbox(x1+50,y1-50,12);
			else if(i==0)
			colorbox(x1+50,y1-50,c);
		}
	}
	x1=x;y1=y;
	a=A[(x1+50)/50][(y1+50)/50];
	if(a!=0 && ((a1%2==0 && a%2!=0) ||(a1%2!=0 && a%2==0)))
	{
		c=getpixel(x1+50-18,y1+50);
		if(i==1)
		colorbox(x1+50,y1+50,12);
		else if(i==0)
		colorbox(x1+50,y1+50,c);
	}
	while(A[(x1+50)/50][(y1+50)/50]==0 && x1+50<450 && y1+50<450)
	{
		c=getpixel(x1+50,y1+50);
		if(i==1)
		colorbox(x1+50,y1+50,10);
		else if(i==0)
		colorbox(x1+50,y1+50,c);
		x1=x1+50;
		y1=y1+50;
		a=A[(x1+50)/50][(y1+50)/50];
		if(a!=0 && ((a1%2==0 && a%2!=0) ||(a1%2!=0 && a%2==0)))
		{
			c=getpixel(x1+50-18,y1+50);
			if(i==1)
			colorbox(x1+50,y1+50,12);
			else if(i==0)
			colorbox(x1+50,y1+50,c);
		}
	}
	x1=x;y1=y;
	a=A[(x1-50)/50][(y1-50)/50];
	if(a!=0 && ((a1%2==0 && a%2!=0) ||(a1%2!=0 && a%2==0)))
	{
		c=getpixel(x1-50-18,y1-50);
		if(i==1)
		colorbox(x1-50,y1-50,12);
		else if(i==0)
		colorbox(x1-50,y1-50,c);
	}
	while(A[(x1-50)/50][(y1-50)/50]==0 && x1-50>50 && y1-50>50)
	{
		c=getpixel(x1-50,y1-50);
		if(i==1)
		colorbox(x1-50,y1-50,10);
		else if(i==0)
		colorbox(x1-50,y1-50,c);
		x1=x1-50;
		y1=y1-50;
		a=A[(x1-50)/50][(y1-50)/50];
		if(a!=0 && ((a1%2==0 && a%2!=0) ||(a1%2!=0 && a%2==0)))
		{
			c=getpixel(x1-50-18,y1-50);
			if(i==1)
			colorbox(x1-50,y1-50,12);
			else if(i==0)
			colorbox(x1-50,y1-50,c);
		}
	}
	x1=x;y1=y;
	a=A[(x1-50)/50][(y1+50)/50];
	if(a!=0 && ((a1%2==0 && a%2!=0) ||(a1%2!=0 && a%2==0)))
	{
		c=getpixel(x1-50-18,y1+50);
		if(i==1)
		colorbox(x1-50,y1+50,12);
		else if(i==0)
		colorbox(x1-50,y1+50,c);
	}
	while(A[(x1-50)/50][(y1+50)/50]==0 && x1-50>50 && y1+50<450)
	{
		c=getpixel(x1-50,y1+50);
		if(i==1)
		colorbox(x1-50,y1+50,10);
		else if(i==0)
		colorbox(x1-50,y1+50,c);
		x1=x1-50;
		y1=y1+50;
		a=A[(x1-50)/50][(y1+50)/50];
		if(a!=0 && ((a1%2==0 && a%2!=0) ||(a1%2!=0 && a%2==0)))
		{
			c=getpixel(x1-50-18,y1+50);
			if(i==1)
			colorbox(x1-50,y1+50,12);
			else if(i==0)
			colorbox(x1-50,y1+50,c);
		}
	}
}

/*Function to decide valid positions for KING */
void kingpos(int x,int y,int i)
{
	int c,j,x1,y1,a1,a;
	a1=A[x/50][y/50];
	for(j=8;j>=1;j--)
	{
		x1=x;
		y1=y;
		if(j==8)
		{
			x1=x1-50;
			y1=y1-50;
		}
		else if(j==7)
		{
			y1=y1-50;
		}
		else if(j==6)
		{
			x1=x1+50;
			y1=y1-50;
		}
		else if(j==5)
		{
			x1=x1+50;
		}
		else if(j==4)
		{
			x1=x1+50;
			y1=y1+50;
		}
		else if(j==3)
		{
			y1=y1+50;
		}
		else if(j==2)
		{
			x1=x1-50;
			y1=y1+50;
		}
		else if(j==1)
		{
			x1=x1-50;
		}
		a=A[x1/50][y1/50];
		if(x1>50 && x1<450 && y1>50 && y1<450)
		{
			if(a==0)
			{
				c=getpixel(x1,y1);
				if(i==1)
				colorbox(x1,y1,10);
				else if(i==0)
				colorbox(x1,y1,c);
			}
			else if(a!=0 && ((a%2==0 && a1%2!=0)||(a%2!=0 && a1%2==0)))
			{
				c=getpixel(x1-18,y1);
				if(i==1)
				colorbox(x1,y1,12);
				else if(i==0)
				colorbox(x1,y1,c);
			}
		}
	}
}

/*Function to decide valid positions for PAWN */
void pawnpos(int x,int y,int i)
{
	int c,a,b;
	if(A[x/50][y/50]==60 && y+50<450)
	{
		a=A[(x-50)/50][(y+50)/50];
		b=A[(x+50)/50][(y+50)/50];
		if(a!=0 && a%2!=0)
		{
			c=getpixel(x-50-18,y+50);
			if(i==1)
			colorbox(x-50,y+50,12);
			else if(i==0)
			colorbox(x-50,y+50,c);
		}
		if(b!=0 && b%2!=0)
		{
			c=getpixel(x+50-18,y+50);
			if(i==1)
			colorbox(x+50,y+50,12);
			else if(i==0)
			colorbox(x+50,y+50,c);
		}
		if(A[x/50][(y+50)/50]==0)
		{
			c=getpixel(x-18,y+50);
			if(i==1)
			colorbox(x,y+50,10);
			else if(i==0)
			colorbox(x,y+50,c);
		}
	}
	else if(A[x/50][y/50]==61 && y-50>50)
	{
		a=A[(x-50)/50][(y-50)/50];
		b=A[(x+50)/50][(y-50)/50];
		if(a!=0 && a%2==0)
		{
			c=getpixel(x-50-18,y-50);
			if(i==1)
			colorbox(x-50,y-50,12);
			else if(i==0)
			colorbox(x-50,y-50,c);
		}
		if(b!=0 && b%2==0)
		{
			c=getpixel(x+50-18,y-50);
			if(i==1)
			colorbox(x+50,y-50,12);
			else if(i==0)
			colorbox(x+50,y-50,c);
		}
		if(A[x/50][(y-50)/50]==0)
		{
			c=getpixel(x,y-50);
			if(i==1)
			colorbox(x,y-50,10);
			else if(i==0)
			colorbox(x,y-50,c);
		}
	}
}

void main()
{
   /* request auto detection */
   int gdriver=DETECT,gmode,errorcode,status,button;
   int x,y,x1,y1,i,j,color,hcolor,bcolor,x2,y2,turn,s,a,b;

   /* initialize graphics and local variables */
   initgraph(&gdriver,&gmode,"C:\\TC\\BGI");

   /* read result of initialization */
   errorcode=graphresult();
   /* an error occurred */
   if (errorcode != grOk)
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1);
   }

   restart:		   /*Label to restart the game*/
   cleararray(A);
   turn=1;
   setbkcolor(7);
   setcolor(8);
   createboard(50,50);
   colorboard(75,75);

   //put the pieces in its respective place
   putrooks(0,0);
   putknights(0,0);
   putbishops(0,0);
   putpawns(0,0);
   putkings(0,0);
   putqueens(0,0);

   /*Exit Button */
   line1(490,50,550,50,8);
   line1(550,50,550,80,8);
   line1(550,80,490,80,8);
   line1(490,80,490,50,8);
   setfillstyle(SOLID_FILL,12);
   floodfill(500,70,8);
   setcolor(15);
   outtextxy(505,64,"EXIT");

   /*Clear Selection Button */
   line1(490,100,630,100,8);
   line1(630,100,630,130,8);
   line1(630,130,490,130,8);
   line1(490,130,490,100,8);
   setfillstyle(SOLID_FILL,15);
   floodfill(495,105,8);
   setcolor(GREEN);
   outtextxy(500,114,"CLEAR SELECTION");

   /*Current Player's Turn Box */
   line1(490,150,630,150,8);
   line1(630,150,630,180,8);
   line1(630,180,490,180,8);
   line1(490,180,490,150,8);
   setfillstyle(SOLID_FILL,15);
   floodfill(495,155,8);
   setcolor(BLUE);
   outtextxy(500,164,"TURN : Player ");

   /*Instructions Button */
   line1(490,350,600,380,8);
   line1(600,350,600,380,8);
   line1(600,380,490,380,8);
   line1(490,380,490,350,8);
   setfillstyle(SOLID_FILL,3);
   floodfill(495,355,8);
   setcolor(15);
   outtextxy(500,364,"INSTRUCTIONS");

   /*Restart Button */
   line1(490,400,570,400,8);
   line1(570,400,570,430,8);
   line1(570,430,490,430,8);
   line1(490,430,490,400,8);
   setfillstyle(SOLID_FILL,3);
   floodfill(495,405,8);
   setcolor(15);
   outtextxy(500,414,"RESTART");

   /*Prints "CHESS" */
   setcolor(BROWN);
   settextstyle(DEFAULT_FONT,0,3);
   outtextxy(50,15,"CHESS");
   settextstyle(DEFAULT_FONT,0,1);

   /*Mouse Responses*/
   showmouseptr();
   while(!kbhit())
   {
	gotoxy(78,11);
	if(turn%2==0)
	printf("2");
	else
	printf("1");
	getmousepos(&button,&x,&y);

	/*Right click on any piece to select it*/
	 if((button==2) && (x>50 && x<450) && (y>50 && y<450))
	 {
		x1=midx(x);
		y1=midy(y);
		a=A[x1/50][y1/50];
		if((turn%2!=0 && A[x1/50][y1/50]%2==0)||(turn%2==0 && A[x1/50][y1/50]%2!=0))
		{
			goto B;
		}
		turn++;
		color=getpixel(x1-20,y1);
		if(A[x1/50][y1/50]!=0)
		{
			mousehide();
			colorbox(x1,y1,1);
			showmouseptr();
			if(A[x1/50][y1/50]==50 || A[x1/50][y1/50]==51)
			{
				mousehide();
				rookpos(x1,y1,1);
				showmouseptr();
			}
			else if(A[x1/50][y1/50]==40 || A[x1/50][y1/50]==41)
			{
				mousehide();
				knightpos(x1,y1,1);
				showmouseptr();
			}
			else if(A[x1/50][y1/50]==30 || A[x1/50][y1/50]==31)
			{
				mousehide();
				bishoppos(x1,y1,1);
				showmouseptr();
			}
			else if(A[x1/50][y1/50]==20 || A[x1/50][y1/50]==21)
			{
				mousehide();
				queenpos(x1,y1,1);
				showmouseptr();
			}
			else if(A[x1/50][y1/50]==10 || A[x1/50][y1/50]==11)
			{
				mousehide();
				kingpos(x1,y1,1);
				showmouseptr();
			}
			else if(A[x1/50][y1/50]==60 || A[x1/50][y1/50]==61)
			{
				mousehide();
				pawnpos(x1,y1,1);
				showmouseptr();
			}
		}
		else if(A[x1/50][y1/50]==0)
		{
			goto B;
		}
		while(!kbhit())
		{
			getmousepos(&button,&x,&y);
			x2=midx(x);
			y2=midy(y);

		       /*Left click on any valid postion to move
		       selected piece */
			if(button==1 && (x>50 && x<450) && (y>50 && y<450))
			{
				hcolor=getpixel(x2-23,y2);
				bcolor=getpixel(x2-20,y2);
				mousehide();
				if((A[x1/50][y1/50]==50 || A[x1/50][y1/50]==51))
				{

					if(hcolor==10 || hcolor==12)
					{
						if(hcolor==12)
							fillbox(x2,y2,bcolor);
						rookpos(x1,y1,0);
						rook(x2,y2);
						if(A[x1/50][y1/50]==50)
						{
							s=win(x1,y1,x2,y2);
							b=A[x2/50][y2/50];
							A[x2/50][y2/50]=50;
						}
						else if(A[x1/50][y1/50]==51)
						{
							s=win(x1,y1,x2,y2);
							b=A[x2/50][y2/50];
							A[x2/50][y2/50]=51;
						}
					}
					else
					{	showmouseptr();
						goto A;
					}
				}
				else if((A[x1/50][y1/50]==40)||(A[x1/50][y1/50]==41))
				{
					if(hcolor==10 || hcolor==12)
					{
						if(hcolor==12)
							fillbox(x2,y2,bcolor);
						knightpos(x1,y1,0);
						knight(x2,y2);
						if(A[x1/50][y1/50]==40)
						{
							s=win(x1,y1,x2,y2);
							b=A[x2/50][y2/50];
							A[x2/50][y2/50]=40;
						}
						else if(A[x1/50][y1/50]==41)
						{
							s=win(x1,y1,x2,y2);
							b=A[x2/50][y2/50];
							A[x2/50][y2/50]=41;
						}
					}
					else
					{	showmouseptr();
						goto A;
					}
				}
				else if(A[x1/50][y1/50]==30||A[x1/50][y1/50]==31)
				{
					if(hcolor==10 || hcolor==12)
					{
						if(hcolor==12)
							fillbox(x2,y2,bcolor);
						bishoppos(x1,y1,0);
						bishop(x2,y2);
						if(A[x1/50][y1/50]==30)
						{
							s=win(x1,y1,x2,y2);
							b=A[x2/50][y2/50];
							A[x2/50][y2/50]=30;
						}
						else if(A[x1/50][y1/50]==31)
						{
							s=win(x1,y1,x2,y2);
							b=A[x2/50][y2/50];
							A[x2/50][y2/50]=31;
						}
					}
					else
					{	showmouseptr();
						goto A;
					}
				}
				else if((A[x1/50][y1/50]==20)||(A[x1/50][y1/50]==21))
				{
					if(hcolor==10 || hcolor==12)
					{
						if(hcolor==12)
							fillbox(x2,y2,bcolor);
						queenpos(x1,y1,0);
						queen(x2,y2);
						if(A[x1/50][y1/50]==20)
						{
							s=win(x1,y1,x2,y2);
							b=A[x2/50][y2/50];
							A[x2/50][y2/50]=20;
						}
						else if(A[x1/50][y1/50]==21)
						{
							s=win(x1,y1,x2,y2);
							b=A[x2/50][y2/50];
							A[x2/50][y2/50]=21;
						}
					}
					else
					{	showmouseptr();
						goto A;
					}
				}
				else if((A[x1/50][y1/50]==10)||(A[x1/50][y1/50]==11))
				{
					if(hcolor==10 || hcolor==12)
					{
						if(hcolor==12)
							fillbox(x2,y2,bcolor);
						kingpos(x1,y1,0);
						king(x2,y2);
						if(A[x1/50][y1/50]==10)
						{
							s=win(x1,y1,x2,y2);
							b=A[x2/50][y2/50];
							A[x2/50][y2/50]=10;
						}
						else if(A[x1/50][y1/50]==11)
						{
							s=win(x1,y1,x2,y2);
							b=A[x2/50][y2/50];
							A[x2/50][y2/50]=11;
						}
					}
					else
					{	showmouseptr();
						goto A;
					}
				}
				else if(A[x1/50][y1/50]==60||A[x1/50][y1/50]==61)
				{
					if(hcolor==10 || hcolor==12)
					{
						if(hcolor==12)
							fillbox(x2,y2,bcolor);
						pawnpos(x1,y1,0);
						pawn(x2,y2);
						if(A[x1/50][y1/50]==60)
						{
							s=win(x1,y1,x2,y2);
							b=A[x2/50][y2/50];
							A[x2/50][y2/50]=60;
						}
						else if(A[x1/50][y1/50]==61)
						{
							s=win(x1,y1,x2,y2);
							b=A[x2/50][y2/50];
							A[x2/50][y2/50]=61;
						}
					}
					else
					{	showmouseptr();
						goto A;
					}
				}

				else
				{
					showmouseptr();
					break;
				}

				A[x1/50][y1/50]=0;
				fillbox(x1,y1,color);
				showmouseptr();

				/*To show GAME OVER Dialogue*/
				if(s==1)
				{
					if((a%2!=0 && b==10)||(a%2==0 && b==11))
					{
						delay(500);
						mousehide();
						clearviewport();
						setfillstyle(SOLID_FILL,15);
						floodfill(10,10,7);
						setcolor(RED);
						settextstyle(DEFAULT_FONT,0,2);
						outtextxy(160,200,"...GAME OVER...");
						setcolor(BLUE);
						settextstyle(DEFAULT_FONT,0,1);
						if((a%2!=0 && b==10))
						outtextxy(230,230,"Player 1 Wins");
						else
						outtextxy(230,230,"Player 2 Wins");
						gameoverbuttons();
						setbkcolor(8);
						showmouseptr();
						while(!kbhit())
						{
							getmousepos(&button,&x,&y);
							if((button==1) && (x>210 && x<270) && (y>250 && y<280))
							{
								fflush(stdin);
								mousehide();
								clearviewport();
								goto restart;
							}
							else if((button==1) && (x>290 && x<350) && (y>250 && y<280))
							{
								mousehide();
								exitgame();
							}
						}
					}
				}
				break;
			}

			/*To clear the selected Piece */
			else if(button==1 && (A[x1/50][y1/50]!=0) && (x>490 && x<600) && (y>100 && y<130))
			{
				turn--;
				setcolor(YELLOW);
				outtextxy(500,114,"CLEAR SELECTION");
				delay(100);
				setcolor(GREEN);
				outtextxy(500,114,"CLEAR SELECTION");
				line1(x1-23,y1-23,x1-23,y1+23,color);
				line1(x1-21,y1+23,x1+21,y1+23,color);
				line1(x1+23,y1+23,x1+23,y1-23,color);
				line1(x1+21,y1-23,x1-21,y1-23,color);

				if((A[x1/50][y1/50]==50) || (A[x1/50][y1/50]==51))
				{
					mousehide();
					rookpos(x1,y1,0);
					showmouseptr();
				}
				else if((A[x1/50][y1/50]==40) || (A[x1/50][y1/50]==41))
				{
					mousehide();
					knightpos(x1,y1,0);
					showmouseptr();
				}
				else if((A[x1/50][y1/50]==30) || (A[x1/50][y1/50]==31))
				{
					mousehide();
					bishoppos(x1,y1,0);
					showmouseptr();
				}
				else if((A[x1/50][y1/50]==20) || (A[x1/50][y1/50]==21))
				{
					mousehide();
					queenpos(x1,y1,0);
					showmouseptr();
				}
				else if((A[x1/50][y1/50]==10) || (A[x1/50][y1/50]==11))
				{
					mousehide();
					kingpos(x1,y1,0);
					showmouseptr();
				}
				else if((A[x1/50][y1/50]==60) || (A[x1/50][y1/50]==61))
				{
					mousehide();
					pawnpos(x1,y1,0);
					showmouseptr();
				}
				showmouseptr();
				break;
			}
			A:fflush(stdin);
		}
		B:fflush(stdin);
	}

	/*To read the Instructions */
	else if((button==1) && (x>490 && x<600) && (y>350 && y<380))
	{
	    mousehide();
	    setcolor(15);
	    setfillstyle(SOLID_FILL,9);
	    floodfill(495,355,8);
	    outtextxy(500,364,"INSTRUCTIONS");
	    delay(50);
	    instructions();
	    fflush(stdin);
	    clearviewport();
	    goto restart;
	}

	/*To Restart the game */
	else if((button==1) && (x>490 && x<570) && (y>400 && y<430))
	{
	    mousehide();
	    setcolor(15);
	    setfillstyle(SOLID_FILL,9);
	    floodfill(495,405,8);
	    outtextxy(500,414,"RESTART");
	    delay(50);
	    setfillstyle(SOLID_FILL,3);
	    floodfill(495,405,8);
	    outtextxy(500,414,"RESTART");
	    delay(50);
	    fflush(stdin);
	    clearviewport();
	    goto restart;
	}
	/*To Exit the game */
	else if((button==1) && (x>490 && x<550) && (y>50 && y<80))
	{
	    mousehide();
	    setcolor(15);
	    setfillstyle(SOLID_FILL,14);
	    floodfill(500,70,8);
	    outtextxy(505,64,"EXIT");
	    delay(50);
	    setfillstyle(SOLID_FILL,12);
	    floodfill(500,70,8);
	    outtextxy(505,64,"EXIT");
	    delay(50);
	    exitgame();
	}

   }

   /* clean up */
   getch();
   closegraph();
}
