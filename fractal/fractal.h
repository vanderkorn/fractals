//$$---- Form HDR ----
//---------------------------------------------------------------------------

#ifndef fractalH
#define fractalH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
	#include "complex.h"
	using namespace std;
  #include <VarCmplx.hpp >
 #include <Math.h>
#include <Math.hpp>
		#define _USE_OLD_RW_STL
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TImage *ImageFract;
	TButton *ButtonPusk;
	TComboBox *ComboBoxType;
	TEdit *EditMaxIter;
	TUpDown *UpDownMaxIter;
	void __fastcall ButtonPuskClick(TObject *Sender);
	void __fastcall ImageFractMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
	void __fastcall ImageFractMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
	void __fastcall ImageFractMouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y);
private:	// User declarations
int **Matrix;
double Left;
double Right;
double Top;
double Bottom;

int Kmax;
int Rmin;
int N;
int M;
int Xnew;
int Ynew;
	  double dy;
 double dx;
 bool isDown;
   TRect R;
   unsigned int isWho;
void fract_go();

int fract_mandelbrot(double x,double y);
int fract_djulia(double x,double y);
 int fract_newton(double x,double y);
void fract_draw();
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
