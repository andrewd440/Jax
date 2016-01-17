#pragma once
#include "Widget.h"

namespace JaxGui
{
	class FControl : public FWidget
	{
	public:
		FControl();
		virtual ~FControl();

		const std::vector<FWidget*>& GetChildren() const override;
		SDrawElement DrawSelf() const override;
	
	private:
		static const std::vector<FWidget*> NoChildren;
	};
}
