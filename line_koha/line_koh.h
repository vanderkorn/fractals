//$$---- Form HDR ----
//---------------------------------------------------------------------------

#ifndef line_kohH
#define line_kohH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include <vector>
#include <vector>
#include <vector>
#include <vector>
#include <math.h>
 #include <Math.hpp>
using namespace std;
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TImage *ImageFract;
	TButton *ButtonGo;
	TComboBox *ComboBoxFract;
	TEdit *EditIter;
	TUpDown *UpDown1;
	void __fastcall ButtonGoClick(TObject *Sender);
private:	// User declarations
	vector<TPoint> points;
	vector<TPoint> line;
	double eps;
	int MaxIter;
	int DOrient;

	void line_koha_iter();
	void draw_fract();

	void line_koha_rec_go();
	vector<TPoint> line_koha_rec(vector<TPoint> L,TPoint b,int DOrient,int rec);

	void paporotnik_go();
	void paporotnik(TPoint p0,double h,double psi,int side, double eps,int rec);
	Graphics::TBitmap* PicPaporotnik;
	double d;
	double h0;

	double k1;
	double k2;
	double m1;
	double m2;
	double m3;

	double fi0;
	double fi1;
	double fi2;
	double fi3;

	Graphics::TBitmap* PicDragon;
	void dragon_harter();
	void lineto(double x,double y,double l,double u);
	int orient(int i);
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
