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
	EVT_CLOSE(deformacjeFrm::OnClose)
END_EVENT_TABLE()
////Event Table End

deformacjeFrm::deformacjeFrm(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxFrame(parent, id, title, position, size, style)
{
	CreateGUIControls();
    wxInitAllImageHandlers();
    //wxImage::AddHandler( new wxJPEGHandler );    
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
	WxBoxSizer1->Add(WxPanel1, 0, wxALIGN_CENTER | wxALL, 5);

	WxBoxSizer2 = new wxBoxSizer(wxVERTICAL);
	WxBoxSizer1->Add(WxBoxSizer2, 0, wxALIGN_CENTER | wxALL, 5);

	WxButton1 = new wxButton(this, ID_WXBUTTON1, _("Wczytaj obrazek"), wxPoint(5, 7), wxSize(75, 25), 0, wxDefaultValidator, _("Wczytaj obrazek"));
	WxBoxSizer2->Add(WxButton1, 0, wxALIGN_CENTER | wxALL, 5);

	WxBoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer2->Add(WxBoxSizer3, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText1 = new wxStaticText(this, ID_WXSTATICTEXT1, _("Obrot prostopadle do plaszczyzny rejestrujacej"), wxPoint(5, 5), wxDefaultSize, 0, _("Obrot prostopadle do plaszczyzny rejestrujacej"));
	WxBoxSizer3->Add(WxStaticText1, 0, wxALIGN_CENTER | wxALL, 5);

	WxScrollBar1 = new wxScrollBar(this, ID_WXSCROLLBAR1, wxPoint(92, 6), wxSize(121, 17), wxSB_HORIZONTAL, wxDefaultValidator, _("WxScrollBar1"));
	WxScrollBar1->Enable(false);
	WxBoxSizer3->Add(WxScrollBar1, 0, wxALIGN_CENTER | wxALL, 5);

	WxBoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer2->Add(WxBoxSizer4, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText2 = new wxStaticText(this, ID_WXSTATICTEXT2, _("Obr�t poziom"), wxPoint(5, 5), wxDefaultSize, 0, _("Obr�t poziom"));
	WxBoxSizer4->Add(WxStaticText2, 0, wxALIGN_CENTER | wxALL, 5);

	WxScrollBar2 = new wxScrollBar(this, ID_WXSCROLLBAR2, wxPoint(52, 6), wxSize(121, 17), wxSB_HORIZONTAL, wxDefaultValidator, _("WxScrollBar2"));
	WxScrollBar2->Enable(false);
	WxBoxSizer4->Add(WxScrollBar2, 0, wxALIGN_CENTER | wxALL, 5);

	WxBoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer2->Add(WxBoxSizer5, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText3 = new wxStaticText(this, ID_WXSTATICTEXT3, _("Obr�t pion"), wxPoint(5, 5), wxDefaultSize, 0, _("Obr�t pion"));
	WxBoxSizer5->Add(WxStaticText3, 0, wxALIGN_CENTER | wxALL, 5);

	WxScrollBar3 = new wxScrollBar(this, ID_WXSCROLLBAR3, wxPoint(42, 6), wxSize(121, 17), wxSB_HORIZONTAL, wxDefaultValidator, _("WxScrollBar3"));
	WxScrollBar3->Enable(false);
	WxBoxSizer5->Add(WxScrollBar3, 0, wxALIGN_CENTER | wxALL, 5);

	WxBoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer2->Add(WxBoxSizer6, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText4 = new wxStaticText(this, ID_WXSTATICTEXT4, _("Obr�t poziom"), wxPoint(5, 5), wxDefaultSize, 0, _("Obr�t poziom"));
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
}

void deformacjeFrm::Load(wxCommandEvent& event){
    wxString s;
    wxFileDialog dialog(this, _("Open JPEG file"), "", "", "JPEG files (*.jpg)|*.jpg", wxFD_OPEN|wxFD_FILE_MUST_EXIST);
    if (dialog.ShowModal() == wxID_CANCEL)
        return; 
    wxFileInputStream input_stream(dialog.GetPath());
    if (!input_stream.IsOk() )
        wxLogError("Nie mo�na za�adowa� obrazka");
    else{
        MyImage.LoadFile(input_stream, wxBITMAP_TYPE_JPEG);
        photo = wxBitmap(MyImage); 
    }
}

void deformacjeFrm::Saving(wxCommandEvent& event){
    wxFileDialog zapisz(this, wxString("Zapisz plik"), wxEmptyString, wxEmptyString, wxString("JPEG files (*.jpg) | *.jpg"), wxFD_SAVE);
   
    if(zapisz.ShowModal() == wxID_OK)
    {
        wxString sciezka = zapisz.GetPath();
        //WxBitmap1.SaveFile(sciezka,wxBITMAP_TYPE_BMP);
    }
    
}

void deformacjeFrm::UpdateDrawing(wxUpdateUIEvent& event){
    drawing();
}

void deformacjeFrm::drawing(){
    /*WxBitmap1.Create(WxPanel1->GetSize());
    //wxClientDC dc(WxPanel1);
    wxMemoryDC dc(WxBitmap1);
    dc.Clear();
    //dc.Clear();*/
    //wxBitmap bitmap(MyImage);   
    //wxClientDC dcClient(WxPanel1);
    //wxBufferedDC dc(&dcClient);
    /*WxBitmap1.Create(WxPanel1->GetSize());
    wxMemoryDC dc(WxBitmap1);
    dc.Clear();*/
    wxClientDC dc2(WxPanel1);
    dc2.DrawBitmap(photo,0,0);
    //dc.SelectObject(wxNullBitmap);
    //dc.DrawBitmap(bitmap, 0, 0);
    Refresh();
    
}

void deformacjeFrm::OnClose(wxCloseEvent& event)
{
	Destroy();
}