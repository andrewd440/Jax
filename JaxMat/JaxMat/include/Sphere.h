#pragma once

#pragma warning ( disable : 4251 )

#include "Vector3.h"
#include "JaxCommon/Common.h"
#include "ImportExports.h"

namespace JaxMat
{
	struct alignas(16) FSphere
	{
		Vector3f Center;
		float Radius;
	};
}