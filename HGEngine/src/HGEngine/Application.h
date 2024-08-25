#pragma once

#include "Events/Event.h"

namespace HGEngine
{
	class HGE_API Application
	{
	private:
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	/* To be defined in CLIENT */
	Application* CreateApplication();
}
