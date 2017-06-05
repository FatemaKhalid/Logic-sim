#pragma once
#include "Actions/Action.h"
#include "ApplicationManager.h"

class select_area :
	public Action
{
public:
	select_area(ApplicationManager *pApp);
	virtual ~select_area();
};

