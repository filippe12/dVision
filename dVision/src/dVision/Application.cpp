#include "dvpch.h"
#include "Application.h"
#include "Events/ApplicationEvent.h"
#include "Events/MouseEvent.h"
#include "dVision/Logger.h"
namespace dVision {
	
	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		MouseMovedEvent e(120,20);
		DV_WARN(e);
		while (true);

	}
}
