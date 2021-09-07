#pragma once

namespace io {
	
	class Window {
	protected:
		unsigned int m_Width, m_Height;
		const wchar_t* m_Title;
		
	public:
		virtual int Initialize() = 0;

		virtual void Update() = 0;

		virtual void Draw() = 0;

		virtual void Close() = 0;

		virtual bool ShouldClose() const = 0;

		virtual void SetVisibility(short visibility) = 0;

		inline unsigned int GetWidth() const { return m_Width; }

		inline unsigned int GetHeight() const { return m_Width; }
	};

}