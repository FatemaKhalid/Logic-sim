#include "Output.h"

Output::Output()
{
	//Initialize user interface parameters

	UI.AppMode = DESIGN;	//Design Mode is the startup mode

	//Initilaize interface colors
	UI.DrawColor = BLACK;
	UI.SelectColor = BLUE;
	UI.ConnColor = RED;
	UI.MsgColor = BLUE;
	UI.BkGrndColor = WHITE;
	
	//Create the drawing window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);	
	ChangeTitle("Programming Techniques Project");

	CreateDesignToolBar();	//Create the desgin toolbar
	CreateStatusBar();		//Create Status bar

	/*pWind->SetPen(BLUE, 3);
	for (int i = 0; i < 1000; i += 15)
	{
		for (int j = 100; j < 650; j++)


			pWind->DrawPixel(i, j);

	}*/
}

Input* Output::CreateInput() const
{
	//Create an Input Object & assign it to the Same Window
	Input* pIn = new Input(pWind);
	return pIn;
}


//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int wd, int h, int x, int y) const
{
	return new window(wd, h, x, y);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::ChangeTitle(string Title) const
{
	pWind->ChangeTitle(Title);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(RED,3);
	pWind->DrawLine(0, UI.height-UI.StatusBarHeight, UI.width, UI.height-UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::PrintMsg(string msg) const
{
	ClearStatusBar();	//Clear Status bar to print message on it
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	// Print the Message
    pWind->SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial"); 
	pWind->SetPen(UI.MsgColor);            //
	pWind->DrawString(MsgX, UI.height - MsgY, msg);
}
/////////////////////////////////////////////////////////////////////////////hebaaaaa
void  Output::Printstring_in_D_A(string msg, Output* pOut,int x, int y) const
{
	
	if (msg != "")   //3lshan lw 3ml escabe mystnash click
	{
		
		/*int x, y;
		PrintMsg("Choose the place you want to print label in ");
		pWind->FlushMouseQueue();
		pWind->WaitMouseClick(x, y);
		//whna andaah fnkshan aala7saaas  hebaaaaaaaaaaaa
	    mkanald5t.x1 = x;  mkanald5t.y1 = y;
		mkanald5t.x2 = x + msg.length();   
		mkanald5t.y2 = y + 30;               //aftrad;*/
		// Print the Message
		pWind->SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial");
		pWind->SetPen(UI.MsgColor);            
		
		pWind->DrawString(x, y, msg);
		pOut->ClearStatusBar();
		
	}
	else
	{
		pOut->ClearStatusBar();
	}
	//return mkanald5t;
}
void Output::Clear_Gate_from_D_A(int X, int Y)const
{
	pWind->SetPen(UI.BkGrndColor);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(X - 5, Y - 20, X + 55, Y + 55);

}
//////////////////////////////end hebaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
//////////////////////////////////////////////////////////////////////////////////
void Output::Clear_string_from_D_A(int MsgX, int MsgY)const                                        //     ???????
{
	
	// Set the Message offset from the Status Bar
	
	
	//Overwrite using bachground color to erase the message
	pWind->SetPen(UI.BkGrndColor);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(MsgX-3, MsgY, MsgX + 55, MsgY+20);   //3 lla7tyaat
}
void Output::ClearStatusBar()const
{                                                //////hebaaaaaaaa 
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	//Overwrite using bachground color to erase the message
	pWind->SetPen(UI.BkGrndColor);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(MsgX, UI.height - MsgY, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
//Clears the drawing (degin) area
void Output::ClearDrawingArea() const
{
	pWind->SetPen(RED, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
	pWind->SetPen(BLUE, 3);
	for (int i = 0; i < UI.width; i += 15)
	{
		for (int j = 90; j <UI.height-50; j+=15)


			pWind->DrawPixel(i, j);

	}
	
}

void Output::Cleartoolbar() const               //hebaaa
{
	
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}

//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the Design mode
void Output::CreateDesignToolBar() const
{
	UI.AppMode = DESIGN;	//Design Mode                                       

	//You can draw the tool bar icons in any way you want.

	//First prepare List of images for each menu item
	string MenuItemImages[ITM_DSN_CNT];
	/*
	MenuItemImages[ITM_AND2] = "images\\Menu\\Menu_AND2.jpg";
	MenuItemImages[ITM_OR2]  = "images\\Menu\\Menu_OR2.jpg";
	MenuItemImages[ITM_NAND2] = "images\\Menu\\Menu_NAND2.jpg";
	MenuItemImages[ITM_NOR2] = "images\\Menu\\Menu_NOR2.jpg";
	MenuItemImages[ITM_XOR2] = "images\\Menu\\Menu_XOR2.jpg";
	MenuItemImages[ITM_XNOR2] = "images\\Menu\\Menu_XNOR2.jpg";
	MenuItemImages[ITM_AND3] = "images\\Menu\\Menu_AND3.jpg";
	MenuItemImages[ITM_NOR3] = "images\\Menu\\Menu_NOR3.jpg";
	MenuItemImages[ITM_XOR3] = "images\\Menu\\Menu_XOR3.jpg";
	MenuItemImages[ITM_BUFFER] = "images\\Menu\\Menu_BUFFER.jpg";
	MenuItemImages[ITM_INVERTER] = "images\\Menu\\Menu_INVERTER.jpg";
	MenuItemImages[ITM_SWITCH] = "images\\Menu\\Menu_SWITCH.jpg";
	MenuItemImages[ITM_LED] = "images\\Menu\\Menu_LED.jpg";
	MenuItemImages[ITM_CONNECTIONS] = "images\\Menu\\Menu_CONNECTIONS.jpg";*/
	MenuItemImages[ITM_Add] = "images\\Menu\\Add_gate.jpg";
	MenuItemImages[ITM_Add_label] = "images\\Menu\\Add_label.jpg";
	MenuItemImages[ITM_Edit_label] = "images\\Menu\\Edit_label.jpg";
	MenuItemImages[ITM_Delete] = "images\\Menu\\delete.jpg";
	MenuItemImages[ITM_Move] = "images\\Menu\\move.jpg";
	MenuItemImages[ITM_Select]= "images\\Menu\\select.jpg";
	MenuItemImages[ITM_Unselect] = "images\\Menu\\Unselect.jpg";
	MenuItemImages[ITM_Multi_Select] = "images\\Menu\\multi_select.jpg";
	MenuItemImages[ITM_Select_Area] = "images\\Menu\\Menu_selectarea.jpg";
	MenuItemImages[ITM_SAVE] = "images\\Menu\\Menu_SAVE.jpg";
	MenuItemImages[ITM_LOAD] = "images\\Menu\\Menu_LOAD.jpg";
	MenuItemImages[ITM_REDO] = "images\\Menu\\Menu_REDO.jpg";
	MenuItemImages[ITM_UNDO] = "images\\Menu\\Menu_UNDO.jpg";
	MenuItemImages[ITM_SWITCH_TO_SIMMULATION] = "images\\Menu\\Menu_SWITCH_TO_SIMMULATION.jpg";
	MenuItemImages[ITM_EXIT] = "images\\Menu\\Menu_Exit.jpg";

	///// 
	//TODO: Prepare image for each menu item and add it to the list

	//Draw menu item one image at a time
	for(int i=0; i<ITM_DSN_CNT; i++)
		pWind->DrawImage(MenuItemImages[i],i*UI.ToolItemWidth,0,UI.ToolItemWidth, UI.ToolBarHeight);


	//Draw a line under the toolbar
	pWind->SetPen(RED,3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

	pWind->SetPen(BLUE, 3);
	for (int i = 0; i < UI.width; i += 15)
	{
		for (int j = 90; j < UI.height-50; j+=15)


			pWind->DrawPixel(i, j);

	}
}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the simulation mode
void Output::CreateSimulationToolBar() const
{
	UI.AppMode = SIMULATION;	//Simulation Mode

	//TODO: Write code to draw the simualtion toolbar (similar to that of design toolbar drawing)
	string MenuItemImages[ITM_SIM_CNT];
	MenuItemImages[ITM_PROBING] = "images\\Menu\\Menu_Probing.jpg";
	MenuItemImages[ITM_TRUTH] = "images\\Menu\\Menu_TruthTable.jpg";
	MenuItemImages[ITM_SwitchToDesign] = "images\\Menu\\Menu_Design_Mode.jpg";
	MenuItemImages[ITM_ValidCiruit] = "images\\Menu\\Menu_CircuitValid.jpg";
	MenuItemImages[ITM_SimCirciut] = "images\\Menu\\Menu_Simulate.jpg";
	MenuItemImages[ITM_changeSwitch]= "images\\Menu\\change_switch.jpg";
	MenuItemImages[ITM_EXIT2] = "images\\Menu\\Menu_Exit.jpg";
	//Draw menu item one image at a time
	for (int i = 0; i<ITM_SIM_CNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.ToolItemWidth, 0, UI.ToolItemWidth, UI.ToolBarHeight);


	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
	
	
}

void Output::CreateAddToolBar() const
{

	UI.AppMode = ADD;	//Design Mode                                       

							//You can draw the tool bar icons in any way you want.

							//First prepare List of images for each menu item
	string MenuItemImages[ITM_ADD_CNT];
	MenuItemImages[ITM_AND2] = "images\\Menu\\Menu_AND2.jpg";
	MenuItemImages[ITM_OR2] = "images\\Menu\\Menu_OR2.jpg";
	MenuItemImages[ITM_NAND2] = "images\\Menu\\Menu_NAND2.jpg";
	MenuItemImages[ITM_NOR2] = "images\\Menu\\Menu_NOR2.jpg";
	MenuItemImages[ITM_XOR2] = "images\\Menu\\Menu_XOR2.jpg";
	MenuItemImages[ITM_XNOR2] = "images\\Menu\\Menu_XNOR2.jpg";
	MenuItemImages[ITM_AND3] = "images\\Menu\\Menu_AND3.jpg";
	MenuItemImages[ITM_NOR3] = "images\\Menu\\Menu_NOR3.jpg";
	MenuItemImages[ITM_XOR3] = "images\\Menu\\Menu_XOR3.jpg";
	MenuItemImages[ITM_BUFFER] = "images\\Menu\\Menu_BUFFER.jpg";
	MenuItemImages[ITM_INVERTER] = "images\\Menu\\Menu_INVERTER.jpg";
	MenuItemImages[ITM_SWITCH] = "images\\Menu\\Menu_SWITCH.jpg";
	MenuItemImages[ITM_LED] = "images\\Menu\\Menu_LED.jpg";
	MenuItemImages[ITM_CONNECTIONS] = "images\\Menu\\Menu_CONNECTIONS.jpg";
	MenuItemImages[ITM_REDO2] = "images\\Menu\\Menu_REDO.jpg";
	MenuItemImages[ITM_UNDO2] = "images\\Menu\\Menu_UNDO.jpg";
	MenuItemImages[ITM_switch_back]= "images\\Menu\\Menu_Switchback.jpg";
	//Draw menu item one image at a time
	for (int i = 0; i<ITM_ADD_CNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.ToolItemWidth, 0, UI.ToolItemWidth, UI.ToolBarHeight);


	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}

//======================================================================================//
//								Components Drawing Functions							//
//======================================================================================//

void Output::DrawAND2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if(selected)	//use image in the highlighted case
		GateImage="Images\\Gates\\Gate_AND2_Hi.jpg";
	else  
		GateImage = "Images\\Gates\\Gate_AND2.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
//TODO: Add similar functions to draw all components
void Output::DrawNAND2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_NAND2.HI.jpg";
	else
		GateImage = "Images\\Gates\\Gate_NAND2.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.NAND2_Width, UI.NAND2_Height);
}
void Output::DrawOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_OR2.HI.jpg";
	else
		GateImage = "Images\\Gates\\Gate_OR2.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.OR2_Width, UI.OR2_Height);
}
void Output::DrawNOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_NOR2.HI.jpg";
	else
		GateImage = "Images\\Gates\\Gate_NOR2.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.NOR2_Width, UI.NOR2_Height);
}
void Output::DrawXOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_XOR2.HI.jpg";
	else
		GateImage = "Images\\Gates\\Gate_XOR2.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.XOR2_Width, UI.XOR2_Height);
}
void Output::DrawXNOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_XNOR2.HI.jpg";
	else
		GateImage = "Images\\Gates\\Gate_XNOR2.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.XNOR2_Width, UI.XNOR2_Height);
}
void Output::DrawNOR3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_NOR3.HI.jpg";
	else
		GateImage = "Images\\Gates\\Gate_NOR3.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.NOR3_Width, UI.NOR3_Height);
}
void Output::DrawXOR3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_XOR3.HI.jpg";
	else
		GateImage = "Images\\Gates\\Gate_XOR3.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.XOR3_Width, UI.XOR3_Height);
}
void Output::DrawAND3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_AND3.HI.jpg";
	else
		GateImage = "Images\\Gates\\Gate_AND3.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND3_Width, UI.AND3_Height);
}
void Output::DrawNOT(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_NOT.HI.jpg";
	else
		GateImage = "Images\\Gates\\Gate_NOT.jpg";

	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.NOT_Width, UI.NOT_Height);
}
void Output::DrawBuffer(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_Buffer.HI.jpg";
	else
		GateImage = "Images\\Gates\\Gate_Buffer.jpg";

	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.NOT_Width, UI.NOT_Height);
}

void Output::DrawLED(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\LED.HI.jpg";
	else
		GateImage = "Images\\Gates\\LED.jpg";
//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.LED_Width, UI.LED_Height);
}
void Output::DrawLED_sim(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\LED.light.jpg";
	else
		GateImage = "Images\\Gates\\LED.jpg";
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.LED_Width, UI.LED_Height);
}
//////////////////////fun
void Output::DrawLED1(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	GateImage = "Images\\Gates\\LED1.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.LED_Width, UI.LED_Height);
}
//////////////////
void Output::DrawSWITCHON(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;

if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\SWITCH.ON.HI.jpg";
	else
		GateImage = "Images\\Gates\\SWITCH.ON.jpg";

//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.LED_Width, UI.LED_Height);
}
void Output::DrawSWITCHOFF(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;

if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\SWITCH.OFF.HI.jpg";
	else
		GateImage = "Images\\Gates\\SWITCH.OFF.jpg";

//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.LED_Width, UI.LED_Height);
}

void Output::DrawConnection(GraphicsInfo r_GfxInfo, bool selected) const
{
	//TODO: Add code to draw connection
	//GraphicsInfo G;

	if (selected)
	{
		// aabdo's ta3dil 
		pWind->SetPen(BLUE, 5);



		if (r_GfxInfo.x2 > r_GfxInfo.x1)
		{
			int blablabla = (r_GfxInfo.x2 - r_GfxInfo.x1) / 2 + r_GfxInfo.x1;
			pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, blablabla, r_GfxInfo.y1);
			pWind->DrawLine(blablabla, r_GfxInfo.y1, blablabla, r_GfxInfo.y2);
			pWind->DrawLine(blablabla, r_GfxInfo.y2, r_GfxInfo.x2, r_GfxInfo.y2);

		}
		else
		
		{
			int blablabla = (r_GfxInfo.x1 - r_GfxInfo.x2) / 2 + r_GfxInfo.x2;
			pWind->DrawLine(r_GfxInfo.x2, r_GfxInfo.y2, blablabla, r_GfxInfo.y2);
			pWind->DrawLine(blablabla, r_GfxInfo.y2, blablabla, r_GfxInfo.y1);
			pWind->DrawLine(blablabla, r_GfxInfo.y1, r_GfxInfo.x1, r_GfxInfo.y1);


		}
		 
		// pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x2, r_GfxInfo.y2);

		
	}
	else
	{
		//pWind->SetPen(bate5a, 5);
		pWind->SetPen(BLACK, 4);
		if (r_GfxInfo.x2 > r_GfxInfo.x1)
		{
			int blablabla = (r_GfxInfo.x2 - r_GfxInfo.x1) / 2 + r_GfxInfo.x1;
			pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, blablabla, r_GfxInfo.y1);
			pWind->DrawLine(blablabla, r_GfxInfo.y1, blablabla, r_GfxInfo.y2);
			pWind->DrawLine(blablabla, r_GfxInfo.y2, r_GfxInfo.x2, r_GfxInfo.y2);

		}
		else

		{
			int blablabla = (r_GfxInfo.x1 - r_GfxInfo.x2) / 2 + r_GfxInfo.x2;
			pWind->DrawLine(r_GfxInfo.x2, r_GfxInfo.y2, blablabla, r_GfxInfo.y2);
			pWind->DrawLine(blablabla, r_GfxInfo.y2, blablabla, r_GfxInfo.y1);
			pWind->DrawLine(blablabla, r_GfxInfo.y1, r_GfxInfo.x1, r_GfxInfo.y1);


		}
		//pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x2, r_GfxInfo.y2);

	}
}

Output::~Output()
{
	delete pWind;
}




/*

void Output::DrawConnection(GraphicsInfo r_GfxInfo, bool selected) const
{
	//TODO: Add code to draw connection
	GraphicsInfo G;

	if (selected)
	{
		// aabdo's ta3dil 
		pWind->SetPen(BLUE, 5);
		pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x2, r_GfxInfo.y2);

		if (r_GfxInfo.y1 == r_GfxInfo.y2)
		{
			r_GfxInfo.y1 = r_GfxInfo.y1 + 100;
			r_GfxInfo.y2 = r_GfxInfo.y2 + 100;


			pWind->SetPen(BLUE, 5);
			pWind->DrawArc(r_GfxInfo.x1 + 50, r_GfxInfo.y1 - 15, r_GfxInfo.x1 + 80, r_GfxInfo.y1 + 15, 0.0, 180.0, FRAME, DEGREES);

			pWind->SetPen(BLUE, 5);
			pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + 50, r_GfxInfo.y1, FRAME);

			pWind->SetPen(BLUE, 5);
			pWind->DrawLine(r_GfxInfo.x1 + 80, r_GfxInfo.y1, r_GfxInfo.x2, r_GfxInfo.y1, FRAME);
		}
		else if (r_GfxInfo.x1 == r_GfxInfo.x2)
		{

			int f = r_GfxInfo.y2 - r_GfxInfo.y1;

			r_GfxInfo.y1 = r_GfxInfo.y2 + 100;
			r_GfxInfo.y2 = r_GfxInfo.y1 + f;

			pWind->SetPen(BLUE, 5);
			pWind->DrawArc(r_GfxInfo.x1 - 15, r_GfxInfo.y1 + 50, r_GfxInfo.x1 + 15, r_GfxInfo.y1 + 80, 270, 90, FRAME, DEGREES);

			pWind->SetPen(BLUE, 5);
			pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1, r_GfxInfo.y1 + 50, FRAME);

			pWind->SetPen(BLUE, 5);
			pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1 + 80, r_GfxInfo.x1, r_GfxInfo.y2, FRAME);



		}
	}
	else
	{
		pWind->SetPen(bate5a, 5);
		pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x2, r_GfxInfo.y2);

		if (r_GfxInfo.y1 == r_GfxInfo.y2)
		{

			r_GfxInfo.y1 = r_GfxInfo.y1 + 100;
			r_GfxInfo.y2 = r_GfxInfo.y2 + 100;

			pWind->SetPen(bate5a, 5);
			pWind->DrawArc(r_GfxInfo.x1 + 50, r_GfxInfo.y1 - 15, r_GfxInfo.x1 + 80, r_GfxInfo.y1 + 15, 0.0, 180.0, FRAME, DEGREES);

			pWind->SetPen(bate5a, 5);
			pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1 + 50, r_GfxInfo.y1, FRAME);

			pWind->SetPen(bate5a, 5);
			pWind->DrawLine(r_GfxInfo.x1 + 80, r_GfxInfo.y1, r_GfxInfo.x2, r_GfxInfo.y1, FRAME);
		}
		else if (r_GfxInfo.x1 == r_GfxInfo.x2)
		{
			int f = r_GfxInfo.y2 - r_GfxInfo.y1;

			r_GfxInfo.y1 = r_GfxInfo.y2 + 100;
			r_GfxInfo.y2 = r_GfxInfo.y1 + f;

			pWind->SetPen(bate5a, 5);
			pWind->DrawArc(r_GfxInfo.x1 - 15, r_GfxInfo.y1 + 50, r_GfxInfo.x1 + 15, r_GfxInfo.y1 + 80, 270, 90, FRAME, DEGREES);

			pWind->SetPen(bate5a, 5);
			pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1, r_GfxInfo.y1 + 50, FRAME);

			pWind->SetPen(bate5a, 5);
			pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1 + 80, r_GfxInfo.x1, r_GfxInfo.y2, FRAME);



		}
	}
}*/
