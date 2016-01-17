#pragma once

#include "JaxMat\Vector2.h"
#include "JaxMat\Color.h"

namespace JaxGui
{
	/**
	* Vertex type produced by JaxGui UI components for rendering.
	*/
	struct Vertex
	{
		JaxMat::Vector2f  position;
		JaxMat::Vector2f  texCoord;
		JaxMat::FColor    color;
	};
}