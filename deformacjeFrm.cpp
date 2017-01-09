///-----------------------------------------------------------------
///
/// @file      deformacjeFrm.cpp
/// @author    Natalia Aleksandra
/// Created:   2017-01-07 14:54:28
/// @section   DESCRIPTION
///            deformacjeFrm class implementation
///
///------------------------------------------------------------------

#include "deformacjeFrm.h"
#include <wx/dcbuffer.h>
#include <wx/wfstream.h>
#include <vector>
#include "vecmat.h"

double deg = M_PI/180.0;

//Do not add custom headers between
//Header Include Start and Header Include End
//wxDev-C++ designer will remove them
////Header Include Start
////Header Include End

//----------------------------------------------------------------------------
// deformacjeFrm
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(deformacjeFrm,wxFrame)
	////Manual Code Start
	////Manual Code End
	EVT_UPDATE_UI(ID_WXPANEL1,deformacjeFrm::UpdateDrawing)
	EVT_BUTTON(ID_WXBUTTON1,deformacjeFrm::Load)
    EVT_BUTTON(ID_WXBUTTON2,deformacjeFrm::Saving)
    EVT_COMMAND_SCROLL(ID_WXSCROLLBAR1,deformacjeFrm::RotationX)
    EVT_COMMAND_SCROLL(ID_WXSCROLLBAR2,deformacjeFrm::RotationY)
    EVT_COMMAND_SCROLL(ID_WXSCROLLBAR3,deformacjeFrm::RotationZ)
    EVT_COMMAND_SCROLL(ID_WXSCROLLBAR4,deformacjeFrm::SkewX)
    EVT_COMMAND_SCROLL(ID_WXSCROLLBAR5,deformacjeFrm::SkewY)
    EVT_COMMAND_SCROLL(ID_WXSCROLLBAR6,deformacjeFrm::BarrelPincushion)
	EVT_CLOSE(deformacjeFrm::OnClose)
END_EVENT_TABLE()
////Event Table End

deformacjeFrm::deformacjeFrm(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxFrame(parent, id, title, position, size, style)
{
	wxInitAllImageHandlers();
	CreateGUIControls();   
}

deformacjeFrm::~deformacjeFrm()
{
}

void deformacjeFrm::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start


	WxBoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	this->SetSizer(WxBoxSizer1);
	this->SetAutoLayout(true);

	WxPanel1 = new wxPanel(this, ID_WXPANEL1, wxPoint(5, 15), wxSize(500, 500));
	WxBoxSizer1->Add(WxPanel1, 0, wxEXPAND | wxALL, 5);

	WxBoxSizer2 = new wxBoxSizer(wxVERTICAL);
	WxBoxSizer1->Add(WxBoxSizer2, 0, wxALIGN_CENTER | wxALL, 5);

	WxButton1 = new wxButton(this, ID_WXBUTTON1, _("Wczytaj obrazek"), wxPoint(5, 7), wxSize(85, 25), 0, wxDefaultValidator, _("Wczytaj obrazek"));
	WxBoxSizer2->Add(WxButton1, 0, wxALIGN_CENTER | wxALL, 5);

	WxBoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer2->Add(WxBoxSizer3, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText1 = new wxStaticText(this, ID_WXSTATICTEXT1, _("Obrot z"), wxPoint(5, 5), wxDefaultSize, 0, _("Obrot prostopadle do plaszczyzny rejestrujacej"));
	WxBoxSizer3->Add(WxStaticText1, 0, wxALIGN_CENTER | wxALL, 5);

	WxScrollBar1 = new wxScrollBar(this, ID_WXSCROLLBAR1, wxPoint(92, 6), wxSize(121, 17), wxSB_HORIZONTAL, wxDefaultValidator, _("WxScrollBar1"));
	WxScrollBar1->Enable(false);
	WxBoxSizer3->Add(WxScrollBar1, 0, wxALIGN_CENTER | wxALL, 5);

	WxBoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer2->Add(WxBoxSizer4, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText2 = new wxStaticText(this, ID_WXSTATICTEXT2, _("Obrót x"), wxPoint(5, 5), wxDefaultSize, 0, _("Obrót poziom"));
	WxBoxSizer4->Add(WxStaticText2, 0, wxALIGN_CENTER | wxALL, 5);

	WxScrollBar2 = new wxScrollBar(this, ID_WXSCROLLBAR2, wxPoint(52, 6), wxSize(121, 17), wxSB_HORIZONTAL, wxDefaultValidator, _("WxScrollBar2"));
	WxScrollBar2->Enable(false);
	WxBoxSizer4->Add(WxScrollBar2, 0, wxALIGN_CENTER | wxALL, 5);

	WxBoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer2->Add(WxBoxSizer5, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText3 = new wxStaticText(this, ID_WXSTATICTEXT3, _("Obrót y"), wxPoint(5, 5), wxDefaultSize, 0, _("Obrót pion"));
	WxBoxSizer5->Add(WxStaticText3, 0, wxALIGN_CENTER | wxALL, 5);

	WxScrollBar3 = new wxScrollBar(this, ID_WXSCROLLBAR3, wxPoint(42, 6), wxSize(121, 17), wxSB_HORIZONTAL, wxDefaultValidator, _("WxScrollBar3"));
	WxScrollBar3->Enable(false);
	WxBoxSizer5->Add(WxScrollBar3, 0, wxALIGN_CENTER | wxALL, 5);

	WxBoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer2->Add(WxBoxSizer6, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText4 = new wxStaticText(this, ID_WXSTATICTEXT4, _("Obrót poziom"), wxPoint(5, 5), wxDefaultSize, 0, _("Obrót poziom"));
	WxBoxSizer6->Add(WxStaticText4, 0, wxALIGN_CENTER | wxALL, 5);

	WxEdit1 = new wxTextCtrl(this, ID_WXEDIT1, _("x"), wxPoint(92, 5), wxSize(121, 19), 0, wxDefaultValidator, _("x"));
	WxBoxSizer6->Add(WxEdit1, 0, wxALIGN_CENTER | wxALL, 5);

	WxEdit2 = new wxTextCtrl(this, ID_WXEDIT2, _("y"), wxPoint(223, 5), wxSize(121, 19), 0, wxDefaultValidator, _("y"));
	WxBoxSizer6->Add(WxEdit2, 0, wxALIGN_CENTER | wxALL, 5);

	WxBoxSizer7 = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer2->Add(WxBoxSizer7, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText5 = new wxStaticText(this, ID_WXSTATICTEXT5, _("Przechylenie pion"), wxPoint(5, 5), wxDefaultSize, 0, _("Przechylenie pion"));
	WxBoxSizer7->Add(WxStaticText5, 0, wxALIGN_CENTER | wxALL, 5);

	WxScrollBar4 = new wxScrollBar(this, ID_WXSCROLLBAR4, wxPoint(39, 6), wxSize(121, 17), wxSB_HORIZONTAL, wxDefaultValidator, _("WxScrollBar4"));
	WxScrollBar4->Enable(false);
	WxBoxSizer7->Add(WxScrollBar4, 0, wxALIGN_CENTER | wxALL, 5);

	WxBoxSizer8 = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer2->Add(WxBoxSizer8, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText6 = new wxStaticText(this, ID_WXSTATICTEXT6, _("Przechylenie poziom"), wxPoint(5, 5), wxDefaultSize, 0, _("Przechylenie poziom"));
	WxBoxSizer8->Add(WxStaticText6, 0, wxALIGN_CENTER | wxALL, 5);

	WxScrollBar5 = new wxScrollBar(this, ID_WXSCROLLBAR5, wxPoint(41, 6), wxSize(121, 17), wxSB_HORIZONTAL, wxDefaultValidator, _("WxScrollBar5"));
	WxScrollBar5->Enable(false);
	WxBoxSizer8->Add(WxScrollBar5, 0, wxALIGN_CENTER | wxALL, 5);

	WxBoxSizer9 = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer2->Add(WxBoxSizer9, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText7 = new wxStaticText(this, ID_WXSTATICTEXT7, _("Beczka/Poduszka"), wxPoint(5, 5), wxDefaultSize, 0, _("Beczka/Poduszka"));
	WxBoxSizer9->Add(WxStaticText7, 0, wxALIGN_CENTER | wxALL, 5);

	WxScrollBar6 = new wxScrollBar(this, ID_WXSCROLLBAR6, wxPoint(41, 6), wxSize(121, 17), wxSB_HORIZONTAL, wxDefaultValidator, _("WxScrollBar6"));
	WxScrollBar6->Enable(false);
	WxBoxSizer9->Add(WxScrollBar6, 0, wxALIGN_CENTER | wxALL, 5);

	WxButton2 = new wxButton(this, ID_WXBUTTON2, _("Zapisz obrazek"), wxPoint(1159, 7), wxSize(75, 25), 0, wxDefaultValidator, _("Zapisz obrazek"));
	WxBoxSizer2->Add(WxButton2, 0, wxALIGN_CENTER | wxALL, 5);

	SetTitle(_("deformacje"));
	SetIcon(wxNullIcon);
	
	Layout();
	GetSizer()->Fit(this);
	GetSizer()->SetSizeHints(this);
	Center();
	
	////GUI Items Creation End
	dc = new wxClientDC(WxPanel1);
    WxScrollBar1->SetScrollbar(0, 1, 361, 1,true);
	WxScrollBar1->Enable(true);
	WxScrollBar2->SetScrollbar(0, 1, 361, 1,true);
	WxScrollBar2->Enable(true);
	WxScrollBar3->SetScrollbar(0, 1, 361, 1,true);
	WxScrollBar3->Enable(true);
	WxScrollBar4->SetScrollbar(0, 1, 361, 1,true);
	WxScrollBar4->Enable(true);
	WxScrollBar5->SetScrollbar(0, 1, 361, 1,true);
	WxScrollBar5->Enable(true);
	wxWindow::GetSize(&xPoint,&yPoint);
	xPoint/=2.;
	yPoint/=2.;
}

void deformacjeFrm::OnClose(wxCloseEvent& event)
{
	Destroy();
}

void deformacjeFrm::Load(wxCommandEvent& event){

	wxFileDialog dialog(this, _("Zaladuj obrazek"), "", "", "JPEG files (*.jpg)|*.jpg", wxFD_OPEN|wxFD_FILE_MUST_EXIST);
	if (dialog.ShowModal() == wxID_CANCEL) {
		return; 
	}
	wxFileInputStream input_stream(dialog.GetPath());
	if (!input_stream.IsOk() ) {
		wxLogError("Nie mozna zaladowa obrazka");
	} else {
		img.LoadFile(input_stream, wxBITMAP_TYPE_JPEG);
	}
	
}

void deformacjeFrm::Saving(wxCommandEvent& event){

	if(img.Ok()) {
		wxImage::AddHandler(new wxPNGHandler);
		wxFileDialog dialog(this, _("Zapisz obrazek"), "", "", "PNG (*.png)|*.png", wxFD_SAVE);
		int arg = dialog.ShowModal();
		if (arg == wxID_CANCEL){
			return;
		} else if (arg == wxID_OK) {
			img.SaveFile(dialog.GetPath(), wxBITMAP_TYPE_PNG);
		} else {
			wxMessageBox("Zapis nie powiódl sie!");
		}
	}
    
}

Matrix4 deformacjeFrm::RotateZ(double alpha)
{
    Matrix4 temp;
    temp.data[0][0] =  temp.data[1][1] = cos(alpha);
    temp.data[0][1] = -sin(alpha);
    temp.data[1][0] = sin(alpha);
    temp.data[2][2] = 1;
    return temp;
}

Matrix4 deformacjeFrm::RotateX(double alpha) {	
   Matrix4 temp;
   temp.data[0][0] = 1.0;
   temp.data[1][1] =  temp.data[2][2] = cos(alpha);
   temp.data[1][2] = -sin(alpha);
   temp.data[2][1] = sin(alpha);
   return temp;
}
Matrix4 deformacjeFrm::RotateY(double alpha) {	
   Matrix4 temp;
   temp.data[0][0] = temp.data[2][2] = cos(alpha);
   temp.data[2][0] = -sin(alpha);
   temp.data[0][2] = sin(alpha);
   temp.data[1][1] = 1.0;
   return temp;
}	


Matrix4 deformacjeFrm::norma(double z){
   Matrix4 tmp;
   tmp.data[0][0] = 1.0/z;
   tmp.data[1][1] = 1.0/z; 
   tmp.data[3][3] = 1.0/z;
   return tmp;
}

Matrix4 deformacjeFrm::scale(double Sx,double Sy, double Sz){
   Matrix4 tmp;
   tmp.data[0][0] = Sx;
   tmp.data[1][1] = Sy;
   tmp.data[2][2] = Sz;
   return tmp;
} 

Matrix4 deformacjeFrm::SkewX(double a,double b){
   Matrix4 tmp;
   tmp.data[0][0] = tmp.data[1][1] = tmp.data[2][2] = 1;
   tmp.data[1][0] = b;
   tmp.data[0][1] = a;

   return tmp;
}

Matrix4 deformacjeFrm::Shift3D(double Tx, double Ty,double Tz) 
{
    Matrix4 shift;
    shift.data[0][0] = 1.0;
    shift.data[0][3] = Tx ;
    shift.data[1][1] = 1.0;
    shift.data[1][3] = Ty;
    shift.data[2][2] = 1.0;
    shift.data[2][3] = Tz ;
    return shift;
}

Matrix4  deformacjeFrm::ToWindow(double xmax, double ymax){
    Matrix4 t1,t2;
    t1.data[0][0] = 1;
    t1.data[1][1] = 1;
    t1.data[0][3] = xmax/2.0; // przesuwamyc calosc na srodek okna (w/2, h/2);
    t1.data[1][3] = ymax/2.0;
    return t1;
}

/**rzutowanie  z 3D na 2D 
 * d - odleglosc kamery od obrazu
 */
Matrix4 deformacjeFrm::To2D() {
	
    Matrix4 tmp;
	tmp.data[0][0] = 1.0;
    tmp.data[1][1] = 1.0;
    tmp.data[3][2] = 0; // 1.0/ d -> 0 , bo d->inf 
    tmp.data[3][3] = 1.0 ;
	return tmp;
}

void deformacjeFrm::UpdateDrawing(wxUpdateUIEvent& event){
    if(img.Ok()){
		drawing();
	}
}

void deformacjeFrm::drawing(){
    
    int w, h;
	Img_Cpy = img.Copy();
	Img_Cpy.Rescale(WxPanel1->GetSize().x, WxPanel1->GetSize().y);
    dc->DrawBitmap(wxBitmap(Img_Cpy), 0, 0, true);
    WxPanel1->GetSize(&w, &h);
    //int w = Img_Cpy.GetWidth();
    //int h = Img_Cpy.GetHeight();
    Matrix4 T1 =  ToWindow( w, h);

/* Operacje w ukladzie swiata */

/**
* jakisscrol->GetThumbPosition() ---> pobiera wartoœæ na która wskazuje scroll
*
**/
    Matrix4 M1= To2D() * Shift3D(0,0,0); // dowolne wartosci?
    Matrix4 M2 = M1 * SkewX(0.0,0.0)* Shift3D(-xPoint,-yPoint,0)* RotateX(0.0);
    M2 = M2 * RotateY(0.0); //value*deg/100....
    M2 = M2 * RotateZ(0.0); // wartosci 0-360
    M2 = M2 * Shift3D(xPoint,yPoint,0)*scale(1,1,1); // wartosci > 0

///////////////////////////////////////////////////////

    Vector4 a1, b1;
    int x1,y1;
    for(int i =0 ; i < w ; i++){
        for(int j =0 ; j < h; j++){
            int r = img.GetRed(i,j);
            int g = img.GetGreen(i,j);
            int b = img.GetBlue(i,j);
        
/** musimu zmienic wspolrzedne punktu na wspolrzedne swiata - > x = x - w/2, y = y- h/2 */

            a1.Set(i- (w/2),j -(h/2),0);
            b1= M2*a1; //operacje ukladzie swiata
            b1 = norma(b1.data[3])*b1; // normowanie
            b1 = T1*b1; // na ekran
            x1 = b1.GetX();
            y1 = b1.GetY();
        /** sprawdzamy czy wspolrzedne nie wykraczaja poza obraz*/
            if( x1>0 && x1 < w && y1 < h && y1 > 0){
                Img_Cpy.SetRGB(x1,y1, r,g,b);
            }
        }
    }

    /*double kd1 = (value-50.0)/10000000.0;
    double oldX, oldY, newX, newY;
    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < h; j++)
        {
            oldX = i - w/2.0; 
            oldY = j - h/2.0;
            double ru =sqrt(pow(oldX, 2) + pow(oldY, 2));
            newX = oldX/(1.0 + kd1* pow(ru,2) ) ;
            newY = oldY/(1.0 + kd1* pow(ru,2) ) ;
            
            newX += w/2.0;
            newY += h/2.0; 
           
            if( newX >0 &&  newX < w-1 && newY < h-1 && newY > 0){
            int r = Img_Org.GetRed(i,j);
            int g = Img_Org.GetGreen(i,j);
            int b = Img_Org.GetBlue(i,j);
            Img_Cpy.SetRGB(newX,newY, r,g,b);
            }
        }
    }*/
    
}

void deformacjeFrm::RotationX(wxScrollEvent& event){
}

void deformacjeFrm::RotationY(wxScrollEvent& event){
}

void deformacjeFrm::RotationZ(wxScrollEvent& event){
}

void deformacjeFrm::SkewX(wxScrollEvent& event){
}

void deformacjeFrm::SkewY(wxScrollEvent& event){
}

void deformacjeFrm::BarrelPincushion(wxScrollEvent& event){
}
