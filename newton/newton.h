//$$---- Form HDR ----
//---------------------------------------------------------------------------

#ifndef newtonH
#define newtonH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
  #include <VarCmplx.hpp >
	#include <complex>
	using namespace std;
 #include <Math.h>
#include <Math.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TImage *ImageFract;
	TEdit *EditMaxIter;
	TUpDown *UpDown1;
	TButton *Button1;
	TImage *ImageFract2;
	TImage *ImageFract3;
	TRadioGroup *RadioGroup;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall ImageFractMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
	void __fastcall ImageFractMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
	void __fastcall ImageFractMouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y);
	void __fastcall ImageFract2MouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
	void __fastcall ImageFract2MouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
	void __fastcall ImageFract2MouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y);
	void __fastcall ImageFract3MouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
	void __fastcall ImageFract3MouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
	void __fastcall ImageFract3MouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y);
private:	// User declarations
int **Matrix;
int **Matrix2;
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
bool isDown2;
bool isDown3;
int isI;
TRect R;
void fract_go();
void fract_newton(double x,double y,int i,int j);
void fract_draw();
public:		// User declarations
__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
