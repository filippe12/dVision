#pragma once

#ifdef DV_PLATFORM_WINDOWS

extern dVision::Application* dVision::CreateApplication();

int main(int argc, char** argv) {

	dVision::Logger::Init();
	DV_CORE_WARN("Created dVision logger!");
	int a = 5;
	DV_INFO("Created client logger! Var={0}",a);
	auto app = dVision::CreateApplication();
	app->Run();
	delete app;
	return 0;
}

#endif
