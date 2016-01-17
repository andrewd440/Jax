#pragma once

#include <vector>

#include "Widget.h"
#include "Control.h"

namespace JaxGui
{
	class FContainer : public FWidget
	{
	public:
		FContainer();
		virtual ~FContainer();

		/* HANDING INVALIDATE EVENTS FROM CHILDREN */

	private:
		std::vector<FControl> mChildren;
	};
}