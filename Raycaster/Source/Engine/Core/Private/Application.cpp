#include "../../Util/Assert.hpp"
#include "../Public/Application.hpp"
#include "../../../Platform/Windows/Public/WindowsWindow.hpp"

namespace core {

	Application::Application() {
		m_Window = new platform::windows::WindowsWindow(500, 500, L"Test");
		m_Secondary = new platform::windows::WindowsWindow(500, 500, L"Child");
		ASSERT(m_Window->Initialize());
		ASSERT(m_Secondary->Initialize());
		m_Window->SetVisibility(SW_SHOW);
		m_Secondary->SetVisibility(SW_SHOW);
	}

	Application::~Application() {
		delete m_Window;
	}

	void Application::Run() {
		while (m_Window->ShouldClose() == false) {
			m_Window->Update();
			m_Secondary->Update();
			m_Window->Draw();
			m_Secondary->Draw();
		}
	}

}