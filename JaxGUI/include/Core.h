#pragma once

#include <vector>
#include <map>

#include "Types.h"
#include "DrawElement.h"

namespace JaxGui
{
	class FWidget;

	class FCore
	{
	public:
		FCore();
		~FCore();

		/*
		* HANDLE WINDOW AND INPUT EVENTS
		*/

		void AddWidget(FWidget* Widget);

		std::vector<SDrawElement> Draw();

	private:
		std::vector<FWidget*> mWidgets;
		std::map<FTextureID, std::string> mTextureMap;
	};
}

