#pragma once
#include "Core.h"
#include "Events/Event.h"

namespace Gngine {
	class GE_API Application
	{
	public:
		Application();
		virtual ~Application();
		void run();
	};

	//To be defined in CLIENT
	Application* CreateApplication();
}

