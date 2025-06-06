#pragma once
#include "Gngine/Core.h"
#include "Layer.h"
#include <vector>

namespace Gngine {
	class GE_API LayerStack {
	private:
		std::vector<Layer*> m_Layers;
		std::vector<Layer*>::iterator m_LayerInsert;
	public:
		LayerStack();
		~LayerStack();

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
		void PopLayer(Layer* layer);
		void PopOverlay(Layer* layer);

		std::vector<Layer*>::iterator begin() {
			return m_Layers.begin();
		}

		std::vector<Layer*>::iterator end() {
			return m_Layers.end();
		}
	};
}