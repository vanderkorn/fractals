//$$---- Form CPP ----
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fractal.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{

N=300;
M=400;
Matrix = new int *[N];
for (int k=0;k<N;k++)
{
Matrix[k] = new int[M];
}
ImageFract->Height=N;
ImageFract->Width=M;

isDown=false;

   unsigned int isWho=0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonPuskClick(TObject *Sender)
{
Kmax=StrToInt(EditMaxIter->Text);
isWho=ComboBoxType->ItemIndex;

 if (isWho==0)
 {
Left=-2;
Right=1;
Top=1.5;
Bottom=-1.5;
 Rmin=2;
 } ;
 if (isWho==1)
 {
Left=-1;
Right=1;
Top=1;
Bottom=-1;
 Rmin=2;
 } ;
 if (isWho==2)
 {
Left=-2;
Right=2;
Top=1.5;
Bottom=-1.5;
Rmin=0.01;
 } ;


dy= fabs(Top-Bottom)/N;
dx=fabs(Right-Left)/M;
fract_go();
}
 void TForm1::fract_go()
 { Graphics::TBitmap* fone=new Graphics::TBitmap();
ImageFract->Picture->Bitmap=fone;

 double x=Left,y=Top;
	  for (int i=0; i < N; i++)
	  {
		   for (int j=0; j < M; j++)
		   {
			  if (isWho==0) {
				 Matrix[i][j]=fract_mandelbrot(x,y);
			  }
				 if (isWho==1) {
				 Matrix[i][j]=fract_djulia(x,y);
			  }                          
			  if (isWho==2) {
				 Matrix[i][j]=fract_newton(x,y);
			  }
			  x+=dx;
		   }
		   x=Left;
			y-=dy;
	  }
	 fract_draw();
 };
 //---------------------------------------------------------------------------
  int TForm1::fract_djulia(double x,double y)
 {
	  double cx=0.36;
double cy=0.36;
double lastx;
	 int f;
	 for (int k=0; k < Kmax; k++)
	 {        f=k;
			  if (sqrt(x*x+y*y)>Rmin)
			  {
					 break;
			  }
			 lastx=x;
			 x=lastx*lastx-y*y+cx;
			 y=2*lastx*y+cy;

	 }
	 return f;
 };
 //---------------------------------------------------------------------------

 int TForm1::fract_newton( double x,double y)
 {
/*complex < double > a(x,y);
complex < double > b;
int f;
	 for (int k=0; k < Kmax; k++)
	 {
			f=k;
			b=a;
			a=((0.75))*a+pow(pow(a,3)*(( double)4.0),-1.0f);
			if ((abs(b-a)<1e-1)||(abs(a)>1e+1)   )
			{
				 break;
			}
	 }
  return f;*/

	double a;
	double b;
	double lastx;
	double lasty;
	double qx;
	double qy;
	int f;
	 for (int k=0; k < Kmax; k++)
	 {
		f=k;
		lastx=x;
		lasty=y;
		a=x*x*x-3*y*y*x;
		b=-y*y*y+3*x*x*y;
		x=(0.75)*x+a/(4.0*(a*a+b*b));
		y=(0.75)*y-b/(4.0*(a*a+b*b));
		qx=fabs(lastx-x);
		qy=fabs(lasty-y);
		if (((qx*qx+qy*qy)<1e-6)||((x*x+y*y)>1e+6))
		 {
					 break;
		 }
	 }
	 return f;
 };
//---------------------------------------------------------------------------
int TForm1::fract_mandelbrot(double x,double y)
{
double cx=x;
double cy=y;
double lastx;
	 int f;
	 for (int k=0; k < Kmax; k++)
	 {        f=k;
			  if (sqrt(x*x+y*y)>Rmin)
			  {
					 break;
			  }
			 lastx=x;
			 x=lastx*lastx-y*y+cx;
			 y=2*lastx*y+cy;

	 }
	 return f;
};
//---------------------------------------------------------------------------


void TForm1::fract_draw()
{


	
	COLORREF *paletterS=new COLORREF[Kmax];
	int dopC,dopC2;
	dopC=ceil((double)Kmax/6);

	int j=0;
	for (int i = 0; i <2*dopC; i++)
	{
		  paletterS[i+j]=RGB(255,i*(255/(2*dopC)),0);
	}
	j+=2*dopC;
	for (int i = 0; i <dopC; i++)
	{
		  paletterS[i+j]=RGB(255-i*(255/(dopC)),255,0);
	}
	j+=dopC;
	for (int i = 0; i <dopC; i++)
	{
		  paletterS[i+j]=RGB(0,255,i*(255/(dopC)));
	}
	j+=dopC;
	for (int i = 0; i <dopC; i++)
	{
		  paletterS[i+j]=RGB(0,255-i*(255/(dopC)),255);
	}
	j+=dopC;
    dopC2=Kmax-j;
	for (int i = 0; i <dopC2; i++)
	{
		  paletterS[i+j]=RGB(i*(255/(dopC2)),0,255);
	}


Graphics::TBitmap* after=new Graphics::TBitmap();
after->Width=M;
after->Height=N;
	  for (int i=0; i < N; i++)
	  {
		   for (int j=0; j < M; j++)
		   {

			int f=RoundTo(Matrix[i][j],0);
			after->Canvas->Pixels[j][i]=paletterS[f];
			}
	  }
	ImageFract->Picture->Bitmap=after;
	ImageFract->Refresh();
};
  //---------------------------------------------------------------------------
void __fastcall TForm1::ImageFractMouseDown(TObject *Sender,
	  TMouseButton Button, TShiftState Shift, int X, int Y)
{
 if (Button==mbLeft)
 {
 Xnew=X;
Ynew=Y;
R.top=0;
R.bottom=0;
R.left=0;
R.right=0;

	isDown=true;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ImageFractMouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
if (Button==mbLeft)
 {
if (X<Xnew) {Right=Left+dx*Xnew;Left=Left+dx*X;} else{Right=Left+dx*X;Left=Left+dx*Xnew;}
if (Y<Ynew) {Bottom=Top-dy*Ynew;Top=Top-dy*Y;} else{Bottom=Top-dy*Y;Top=Top-dy*Ynew;}

dy= fabs(Top-Bottom)/N;
dx=fabs(Right-Left)/M;
isDown=false;
Kmax=StrToInt(EditMaxIter->Text);

fract_go();
}

}
//---------------------------------------------------------------------------


void __fastcall TForm1::ImageFractMouseMove(TObject *Sender, TShiftState Shift,
	  int X, int Y)
{
if (isDown){
ImageFract->Canvas->DrawFocusRect(R) ;
if (X<Xnew) {R.left=X;R.right=Xnew;} else{R.left=Xnew;R.right=X;}
if (Y<Ynew) {R.top=Y;R.bottom=Ynew;} else{R.top=Ynew;R.bottom=Y;}
ImageFract->Canvas->DrawFocusRect(R) ;
}
}
//---------------------------------------------------------------------------


