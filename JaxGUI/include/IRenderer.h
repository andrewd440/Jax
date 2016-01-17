#pragma once

#include <vector>

#include "Vertex.h"

namespace JaxGui
{
	/**
	* Interface used to render gui components.
	*/
	class IRenderer
	{
		IRenderer() = default;
		virtual ~IRenderer() = default;

		virtual void Draw(const std::vector<Vertex>& vertices) = 0;
	};
}