#include "Application.h"

#include "Events/MouseEvent.h"
#include"Log.h"

HGEngine::Application::Application()
{

}

HGEngine::Application::~Application()
{

}

void HGEngine::Application::Run()
{
	MouseButtonPressedEvent e(1);
	HGE_TRACE(e);

	while (true);
}
