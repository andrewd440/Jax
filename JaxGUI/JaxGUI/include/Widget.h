#pragma once

#include <vector>

#include "DrawElement.h"

namespace JaxGui
{
	class FWidget
	{
	public:
		FWidget();
		virtual ~FWidget();

		void Draw(std::vector<SDrawElement>& DrawElements) const;

		virtual const std::vector<FWidget*>& GetChildren() const = 0;

	protected:
		virtual SDrawElement DrawSelf() const = 0;

	private:

	};
}
