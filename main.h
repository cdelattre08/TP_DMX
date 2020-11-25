//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include<System.Classes.hpp>
#include<Vcl.Controls.hpp>
#include<Vcl.StdCtrls.hpp>
#include<Vcl.Forms.hpp>
#include<Vcl.ComCtrls.hpp>
#include<Vcl.ExtCtrls.hpp>
#include"include/DasHard.h.h"
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
#define DMX_MAXCHANNEL 512
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
	__published:	// Composants gérés par l'EDI
		TTimer *Timer1;
		TButton *Bleu;
		TPanel *Connect;
		TLabel *Textco;
		TButton *Rouge;
		TButton *Vert;
		TButton *Blanc;
		TButton *Stroboscope;
		TPanel *Panel1;
		TPanel *PanelBleu;
		TPanel *Panel3;
		TPanel *Panel4;
		TTrackBar *TrackBar1;
		void __fastcall Timer1Timer(TObject *Sender);
		void __fastcall FormClose(TObject*Sender,TCloseAction&Action);
		void __fastcall BlancClick(TObject *Sender);
		void __fastcall VertClick(TObject *Sender);
		void __fastcall TrackBar1Change(TObject *Sender);
		void __fastcall RougeClick(TObject *Sender);
		void __fastcall BleuClick(TObject *Sender);
		void __fastcall StroboscopeClick(TObject *Sender);

	private:	// Déclarations utilisateur
		HINSTANCE g_dasusbdll;
		typedef int(*DASHARDCOMMAND)(int,int,unsigned char*);
		DASHARDCOMMAND DasUsbCommand;
		int interface_open;
		unsigned char dmxBlock[512];
		unsigned char close[512];
		//void__fastcall SendTrame();
		int CouleurR;
		int CouleurG;
		int CouleurB;
		int CouleurW;

	public:		// Déclarations utilisateur
		  SOCKET sock;
		__fastcall TForm1(TComponent* Owner);
		void __fastcall SendTrame();
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
