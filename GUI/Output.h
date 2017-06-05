#pragma once
#include "../Defs.H"
#include "Input.h"
#include <string>
#include <stack>


class Output	//The application manager should have a pointer to this class
{
private:
	window* pWind;	//Pointer to the Graphics Window
public:
	Output(); // Performs the Window Initialization
	Input* CreateInput() const; //creates a pointer to the Input object
	void ChangeTitle(string Title) const;

	void CreateDesignToolBar() const;	//Tool bar of the design mode
	void CreateSimulationToolBar() const;//Tool bar of the simulation mode
	void CreateAddToolBar() const;	//Tool bar of the add gates
	void CreateStatusBar() const;	//Create Status bar

	void ClearStatusBar() const;		//Clears the status bar
	void ClearDrawingArea() const;	//Clears the drawing area
	void Cleartoolbar() const;                  ////hebaaaaaaaaaaaaa
	void Printstring_in_D_A(string msg, Output* pOut,int x,int y) const;       ////HEBAAAAAAAAAA
	void Clear_string_from_D_A(int MsgX, int MsgY)const;        //hebaaaaaaaaaa 
	void Clear_Gate_from_D_A(int X, int Y)const;
	window* CreateWind(int wd, int h, int x, int y) const; //Creates user interface window

	
	// Draws 2-input AND gate
	void DrawAND2(GraphicsInfo r_GfxInfo, bool selected = false) const;

	void DrawNAND2(GraphicsInfo r_GfxInfo, bool selected = false) const;

	void DrawOR2(GraphicsInfo r_GfxInfo, bool selected = false) const;

	void DrawNOR2(GraphicsInfo r_GfxInfo, bool selected = false) const;

	void DrawXOR2(GraphicsInfo r_GfxInfo, bool selected = false) const;

	void DrawXNOR2(GraphicsInfo r_GfxInfo, bool selected = false) const;

	void DrawNOR3(GraphicsInfo r_GfxInfo, bool selected = false) const;

	void DrawXOR3(GraphicsInfo r_GfxInfo, bool selected = false) const;

	void DrawAND3(GraphicsInfo r_GfxInfo, bool selected = false) const;

	void DrawNOT(GraphicsInfo r_GfxInfo, bool selected = false) const;

	void DrawBuffer(GraphicsInfo r_GfxInfo, bool selected= false) const;

	void DrawLED(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawLED_sim(GraphicsInfo r_GfxInfo, bool light = false ) const;
	void DrawLED1(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawSWITCHON(GraphicsInfo r_GfxInfo, bool selected = false) const;
void DrawSWITCHOFF(GraphicsInfo r_GfxInfo, bool selected = false) const;

		///TODO: Make similar functions for drawing all other gates, switch, and LED, .. etc

	// Draws Connection
	void DrawConnection(GraphicsInfo r_GfxInfo, bool selected = false) const;
	
	void PrintMsg(string msg) const;	//Print a message on Status bar


	~Output();
};
