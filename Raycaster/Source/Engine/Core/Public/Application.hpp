#pragma once

namespace io {
	class Window;
}

namespace core {

	class Application {
	protected:
		io::Window* m_Window;
		io::Window* m_Secondary;

	public:
		Application();

		~Application();

		void Run();

		inline io::Window* GetWindow() const { return m_Window; }
	};
}