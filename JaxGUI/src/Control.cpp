#include "..\include\Control.h"


namespace JaxGui
{

	const std::vector<FWidget*> FControl::NoChildren;

	FControl::FControl()
	{
	}


	FControl::~FControl()
	{

	}

	const std::vector<FWidget*>& FControl::GetChildren() const
	{
		return NoChildren;
	}

	SDrawElement FControl::DrawSelf() const
	{
		return SDrawElement();
	}
}