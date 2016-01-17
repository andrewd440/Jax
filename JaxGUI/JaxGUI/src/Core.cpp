#include "..\include\Core.h"

namespace JaxGui
{
	FCore::FCore()
	{
	}

	FCore::~FCore()
	{
	}

	void FCore::AddWidget(FWidget* Widget)
	{
		mWidgets.push_back(Widget);
	}

	std::vector<SDrawElement> FCore::Draw()
	{

	}
}