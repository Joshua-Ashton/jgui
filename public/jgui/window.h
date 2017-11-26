#ifndef JGUI_WINDOW_H
#define JGUI_WINDOW_H

#include <jgui/panel.h>

#include <jgui/jgui_common.h>

#include <jgui/vsync_modes.h>
#include <jgui/open_states.h>

namespace jgui
{
	class jgui_export Window : public Panel
	{
	public:
		DECLARE_CLASS(Window, Panel)
		DECLARE_DATA_DESC()

		~Window();

		bool Open();
		void Shutdown();

		static bool AnyOpen();

		virtual void OnQuitRequested();
		virtual void OnNameUpdated();
		virtual void OnBoundsUpdated(bool pos, bool wide);

		inline void SetIsProportional(bool isProportional)
		{
			m_bIsProportional = isProportional;
			RecomputeScale();
		}
		inline bool GetIsProportional()
		{
			return m_bIsProportional;
		}
		DESC_FUNC_BOOL_WRAPPER(SetIsProportional);

		void Render(u32 xOffset, u32 yOffset);

		virtual void OnCreated();

	protected:
		virtual void* GetRenderContext();
		bool m_bIsProportional = false;
	};
}

#endif