//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "include/DasHard.h.h"
#include <winsock2.h>
#define DMX_MAXCHANNEL 512
	typedef int socklen_t;
#include "main.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{

	//Chargement de la DLL
g_dasusbdll = LoadLibrary(L"DasHard2006.dll");
//Verification du chargement
if (g_dasusbdll)
DasUsbCommand = (DASHARDCOMMAND)::GetProcAddress((HMODULE)g_dasusbdll, "DasUsbCommand");
//Initialisation de la DLL

interface_open =DasUsbCommand(DHC_INIT,0, NULL);
Textco->Caption = interface_open;
interface_open = DasUsbCommand(DHC_OPEN,0,0);

if (interface_open>0)
{
		   Textco->Caption = "passe";
int i;
for (i = 0 ; i<DMX_MAXCHANNEL + 1; i++)
{
	dmxBlock[i] = 0;
}

DasUsbCommand(DHC_DMXOUT, DMX_MAXCHANNEL, dmxBlock);
	   }
}

//---------------------------------------------------------------------------
 void __fastcall TForm1::SendTrame()
 {
	if(interface_open>0)
	{
		try
		{
			DasUsbCommand(DHC_DMXOUT,DMX_MAXCHANNEL,dmxBlock);
		}
		catch(int x)
		{
		}
	}

 }

 void __fastcall TForm1::FormClose(TObject*Sender,TCloseAction&Action)
 {
 //Fermeture du DMX l'arret du programme
	if(interface_open>0)
	{
		DasUsbCommand(DHC_CLOSE,0,0);
		DasUsbCommand(DHC_EXIT,0,NULL);
	}
	if(g_dasusbdll!=NULL)
	FreeLibrary(g_dasusbdll);
 }

//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
	SendTrame();
}
//---------------------------------------------------------------------------

 //bouton blanc
void __fastcall TForm1::BlancClick(TObject *Sender)
{
	
    for (int i = 0; i < 512; i++)
		{
			dmxBlock[i] = 0;
		}
	dmxBlock[0]=0xFF;
	dmxBlock[1]=0xFF;
	dmxBlock[2]=0xFF;
	dmxBlock[3]=0xFF;
	dmxBlock[4]=0xFF;
	dmxBlock[5]=0xFF;
}
//---------------------------------------------------------------------------

//bouton vert
void __fastcall TForm1::VertClick(TObject *Sender)
{
for (int i = 0; i < 512; i++)
	{
		dmxBlock[i] = 0;
	}
	dmxBlock[0]=0x00;
	dmxBlock[1]=0xFF;
	dmxBlock[2]=0x00;
	dmxBlock[3]=0x00;
	dmxBlock[4]=0x00;
	dmxBlock[5]=0x00;
	
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

void __fastcall TForm1::TrackBar1Change(TObject *Sender)
{
		dmxBlock[1]= TrackBar1->Position;
		DasUsbCommand(DHC_DMXOUT, DMX_MAXCHANNEL, dmxBlock);
}
//---------------------------------------------------------------------------

//bouton rouge
void __fastcall TForm1::RougeClick(TObject *Sender)
{
for (int i = 0; i < 512; i++)
	{
		dmxBlock[i] = 0;
	}
	dmxBlock[0]=0xFF;
	dmxBlock[1]=0x00;
	dmxBlock[2]=0x00;
	dmxBlock[3]=0x00;
	dmxBlock[4]=0xFF;
	dmxBlock[5]=0xFF;
}
//---------------------------------------------------------------------------

//bouton bleu
void __fastcall TForm1::BleuClick(TObject *Sender)
{
	for (int i = 0; i < 512; i++)
		{
			dmxBlock[i] = 0;
		}

	dmxBlock[1]=0x00;
	dmxBlock[2]=0xFF;
	dmxBlock[3]=0x00;
	dmxBlock[4]=0x00;
	dmxBlock[5]=0x00;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::StroboscopeClick(TObject *Sender)
{
		for (int i = 0; i < 512; i++)
		{
			dmxBlock[i] = 0;
		}

		dmxBlock[1]=0xFF;
		dmxBlock[2]=0xFF;
		dmxBlock[3]=0xFF;
		dmxBlock[4]=0xFF;
		dmxBlock[5]=0xFF;
}
//---------------------------------------------------------------------------


