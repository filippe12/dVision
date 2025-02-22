#pragma once

#ifdef DV_PLATFORM_WINDOWS

extern dVision::Application* dVision::CreateApplication();

int main(int argc, char** argv) {


	auto app = dVision::CreateApplication();
	app->Run();
	delete app;
	return 0;
}

#endif
