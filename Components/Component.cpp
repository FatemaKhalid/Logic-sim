#include "Component.h"

Component::Component(const GraphicsInfo &r_GfxInfo, string type, string label) :id(++last_id)   //dft 7gat
{
	m_GfxInfo = r_GfxInfo;	
	HI = false;
	lazy_deleted = false;
}

void Component::setlazy_d(bool l)
{
	lazy_deleted = l;
}

bool Component::getlazy_d()
{
	return lazy_deleted;
}
Component::Component() :id(++last_id)      //dft 7gat
{
	m_Label = "";
	HI = false;
	lazy_deleted = false;
}


Component::~Component()    
{}
void Component::change_to_UnHI()
{
	HI = false;
}

void Component::change_to_HI()
{
	HI = true;
}

bool Component::getHI()
{
	return HI;
}

////hebaaaaa
int Component::getid()
{
	return id;
}
string Component::gettype()
{
	return type;
}
void Component::settype(string t)
{
	type = t;
}
string Component::getlabel()
{
	return m_Label;
}
void Component::edit_label(string label)
{
	m_Label = label;
}
GraphicsInfo Component::getm_GfxInfo()
{
	return m_GfxInfo;
}
int Component::last_id = 0;