#pragma once

#include "Gngine/Window.h"
#include "GLFW/glfw3.h"

struct GLFWwindow;

namespace Gngine {
	class WindowsWindow : public Window {
	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();
		GLFWwindow* m_Window;
		struct WindowData {
			std::string Title;
			unsigned int Width, Height;
			bool VSync;

			EventCallbackFn EventCallback;
		};

		WindowData m_data;
		
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		inline unsigned int GetWidth() const override {
			return m_data.Width;
		}
		inline unsigned int GetHeight() const override {
			return m_data.Height;
		}

		//Window Attributes
		inline void SetEventCallback(const EventCallbackFn& callback) override {
			m_data.EventCallback = callback;
		}

		void SetVSync(bool enabled) override;
		bool isVSync() const override;
	};
}