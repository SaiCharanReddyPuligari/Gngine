#include "Gpch.h"
#include "Application.h"
#include "Gngine/Log.h"
#include "Gngine/Events/Event.h"
#include "Events/ApplicationEvent.h"

namespace Gngine {
	Application::Application() {

	}

	Application::~Application() {

	}

	void Application::run() {

		WindowResizeEvent e(1200, 720);
		Gngine::Log::GetClientLogger()->trace(e.ToString());
		while (true) {

		}

	}
}