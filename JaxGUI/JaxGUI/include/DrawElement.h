#pragma once

#include <vector>

#include "Types.h"
#include "Vertex.h"

namespace JaxGui
{
	struct SDrawElement
	{
		FTextureID TextureID;
		std::vector<Vertex> Vertices;
		std::vector<uint32_t> Indices;
	};

}
