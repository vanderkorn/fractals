//$$---- Form CPP ----
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "newton.h"
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
Matrix2 = new int *[N];
for (int k=0;k<N;k++)
{
Matrix[k] = new int[M];
Matrix2[k] = new int[M];
}

ImageFract->Height=N;
ImageFract->Width=M;
 ImageFract2->Height=N;
ImageFract2->Width=M;
ImageFract3->Height=N;
ImageFract3->Width=M;

isDown=false;
isDown2=false;
isDown3=false;

   unsigned int isWho=0;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
Kmax=StrToInt(EditMaxIter->Text);
isI=RadioGroup->ItemIndex;
Left=-2;
Right=2;
Top=1.5;
Bottom=-1.5;
Rmin=0.01;

dy= fabs(Top-Bottom)/N;
dx=fabs(Right-Left)/M;


fract_go();
}
//---------------------------------------------------------------------------
  void TForm1::fract_go()
 { Graphics::TBitmap* fone=new Graphics::TBitmap();
ImageFract->Picture->Bitmap=fone;
 ImageFract2->Picture->Bitmap=fone;
   ImageFract3->Picture->Bitmap=fone;
 double x=Left,y=Top;
	  for (int i=0; i < N; i++)
	  {
		   for (int j=0; j < M; j++)
		   {
				 fract_newton(x,y,i,j);
				 x+=dx;
		   }
		   x=Left;
			y-=dy;
	  }
	 fract_draw();
 };
 //---------------------------------------------------------------------------
void TForm1::fract_newton( double x,double y,int i,int j)
 {

/*complex < double > a(x,y);
complex < double > b;
int f;
	 for (int k=0; k < Kmax; k++)
	 {
			 f=k;
			 b=a;
			a=(2.0/3.0)*a+pow(pow(a,2.0)*((double)3.0),-1.0f);
			 if ((abs(b-a)<1e-3)||(abs(a)>1e+3) )
			 {
				 break;
			 }
	 }

         Matrix[i][j] =f;
		int z=-1;
		if (f!=Kmax-1)
		{
			 complex < double > r(1.0,0);
			 complex < double > g(-0.5,sqrt(3.0)/2.0);
			 complex < double > b(-0.5,-sqrt(3.0)/2.0);
		double minim=abs(r-a);
		z=0;
		 if (abs(g-a)<minim)
		 {     z=1;
			  minim=abs(g-a);
		 }
		if (abs(b-a)<minim)
		 {     z=2;
			  minim=abs(b-a);
		 }
		 }

		  Matrix2[i][j] =z;   */

 	double lastx;
	double lasty;
	double qx;
	double qy;
	double p;
	 int f;

	 for (int k=0; k < Kmax; k++)
	 {
		f=k;
		lastx=x;
		lasty=y;
			 switch (isI)
			 {
			 case 0:
				p=pow(pow(x,2.0)+pow(y,2.0),2.0);
				x=2.0/3.0*x+(pow(x,2.0)-pow(y,2.0))/(3.0*p);
				y=2.0/3.0*y*(1.0-lastx/p);
			 break;
			 case 1:
				x=2.0/3.0*x+1.0/(3.0*pow(x,2.0));
				y=2.0/3.0*y*(1.0-1.0/pow(x,3.0));
		
			 break;
			 case 2:
				p=pow(pow(x,2.0)-pow(y,2.0),2.0);
				x=2.0/3.0*x+(pow(x,2.0)+pow(y,2.0))/(3.0*p);
				y=2.0/3.0*y*(1.0-lastx/p);
			 break;
			 }
	  qx=fabs(lastx-x);
	  qy=fabs(lasty-y);
	if (((qx*qx+qy*qy)<1e-6)||((x*x+y*y)>1e+6))
		 {
					 break;
		 }
	 }
	 Matrix[i][j] =f;
		int z=-1;
	if (f!=Kmax-1)
	{

	  double r=(1.0-x)*(1.0-x)+(0-y)*(0-y);
	  double minim=r;
	  z=0;
		  if (isI==0 )
		  {
	  double g= (-0.5-x)*(-0.5-x)+(sqrt(3.0)/2.0-y)*(sqrt(3.0)/2.0-y);
	  double b= (-0.5-x)*(-0.5-x)+(-sqrt(3.0)/2.0-y)*(-sqrt(3.0)/2.0-y);

		
		 if (g<minim)
		 {     z=1;
			  minim=g;
		 }
		if (b<minim)
		 {     z=2;
			  minim=b;
		 }
		 }
	}

		  Matrix2[i][j] =z;

 };
//---------------------------------------------------------------------------
 void TForm1::fract_draw()
{

Graphics::TBitmap* after=new Graphics::TBitmap();
after->Width=M;
after->Height=N;
 Graphics::TBitmap* after2=new Graphics::TBitmap();
after2->Width=M;
after2->Height=N;
  Graphics::TBitmap* after3=new Graphics::TBitmap();
after3->Width=M;
after3->Height=N;
	  for (int i=0; i < N; i++)
	  {
		   for (int j=0; j < M; j++)
		   {
		switch (Matrix2[i][j])
		{
	   case 0:
		 after->Canvas->Pixels[j][i]=clRed;
		 break;
	   case 	1:
		 after->Canvas->Pixels[j][i]=clGreen;
		 break;

	   case 2:
		after->Canvas->Pixels[j][i]=clBlue;
		 break;
	   case -1:
		after2->Canvas->Pixels[j][i]=clBlack;
		break;
			default:
			break;
		}
		 int q,w;
	 q=fmod(Matrix[i][j],2.0);

		if (q&1)

		{
			  after3->Canvas->Pixels[j][i]=clWhite;
		}
		else
		{
			  after3->Canvas->Pixels[j][i]=clBlack;
		}


}
	  }
ImageFract->Picture->Bitmap=after;
ImageFract->Refresh();
 ImageFract2->Picture->Bitmap=after2;
ImageFract2->Refresh();
	ImageFract3->Picture->Bitmap=after3;
ImageFract3->Refresh();
};
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

void __fastcall TForm1::ImageFract2MouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
	if (Button==mbLeft)
{
if (X<Xnew) {Right=Left+dx*Xnew;Left=Left+dx*X;} else{Right=Left+dx*X;Left=Left+dx*Xnew;}
if (Y<Ynew) {Bottom=Top-dy*Ynew;Top=Top-dy*Y;} else{Bottom=Top-dy*Y;Top=Top-dy*Ynew;}
dy= fabs(Top-Bottom)/N;
dx=fabs(Right-Left)/M;
isDown2=false;
Kmax=StrToInt(EditMaxIter->Text);
fract_go();
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ImageFract2MouseDown(TObject *Sender,
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
isDown2=true;
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ImageFract2MouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
	  if (isDown2){
ImageFract2->Canvas->DrawFocusRect(R) ;
if (X<Xnew) {R.left=X;R.right=Xnew;} else{R.left=Xnew;R.right=X;}
if (Y<Ynew) {R.top=Y;R.bottom=Ynew;} else{R.top=Ynew;R.bottom=Y;}
ImageFract2->Canvas->DrawFocusRect(R) ;
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ImageFract3MouseDown(TObject *Sender,
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
isDown3=true;
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ImageFract3MouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
	   	if (Button==mbLeft)
{
if (X<Xnew) {Right=Left+dx*Xnew;Left=Left+dx*X;} else{Right=Left+dx*X;Left=Left+dx*Xnew;}
if (Y<Ynew) {Bottom=Top-dy*Ynew;Top=Top-dy*Y;} else{Bottom=Top-dy*Y;Top=Top-dy*Ynew;}
dy= fabs(Top-Bottom)/N;
dx=fabs(Right-Left)/M;
isDown3=false;
Kmax=StrToInt(EditMaxIter->Text);
fract_go();
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ImageFract3MouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
		  if (isDown3){
ImageFract3->Canvas->DrawFocusRect(R) ;
if (X<Xnew) {R.left=X;R.right=Xnew;} else{R.left=Xnew;R.right=X;}
if (Y<Ynew) {R.top=Y;R.bottom=Ynew;} else{R.top=Ynew;R.bottom=Y;}
ImageFract3->Canvas->DrawFocusRect(R) ;
}
}
//---------------------------------------------------------------------------

