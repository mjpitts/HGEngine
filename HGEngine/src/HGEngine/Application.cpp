#include "Application.h"

#include "Events/ApplicationEvent.h"
#include"Log.h"

HGEngine::Application::Application()
{

}

HGEngine::Application::~Application()
{

}

void HGEngine::Application::Run()
{
	WindowResizeEvent e(1280, 720);
	HGE_TRACE(e);

	while (true);
}
