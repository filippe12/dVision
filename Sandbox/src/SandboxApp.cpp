#include <dVision.h>


class Sandbox : public dVision::Application 
{
public:
	Sandbox() 
	{

	}

	~Sandbox() 
	{

	}

};

dVision::Application* dVision::CreateApplication()
{
	return new Sandbox();
}