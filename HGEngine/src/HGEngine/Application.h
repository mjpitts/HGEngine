#pragma once

#include "Core.h"

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
