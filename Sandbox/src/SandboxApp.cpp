
//namespace Gngine {
//	__declspec(dllimport) void Print();
//}

#include <Gngine.h>

class ExampleLayer : public Gngine::Layer {
public:
	ExampleLayer():Layer("Example") {

	}

	void OnUpdate() override {
		GE_CLIENT_INFO("ExampleLayer::Update");
	}

	void OnEvent(Gngine::Event& event) override {

		GE_CLIENT_INFO("{0}", event);
	}
};

class Sandbox : public Gngine::Application {
public:
	Sandbox() {
		PushLayer(new ExampleLayer());
	}
	~Sandbox() {

	}
};

Gngine::Application* Gngine::CreateApplication() {
	return new Sandbox();
}