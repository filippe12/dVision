#pragma once

#include "Core.h"

namespace dVision {
	class DVISION_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//To be defined in client
	Application* CreateApplication();
}

