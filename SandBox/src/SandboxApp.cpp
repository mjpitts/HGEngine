#include <HGEngine.h>

class Sandbox : public HGEngine::Application
{
private:
public:
	Sandbox()
	{
	
	}
	~Sandbox()
	{
	
	}
};

HGEngine::Application* HGEngine::CreateApplication()
{
	return new Sandbox();
}