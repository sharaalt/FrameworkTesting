#ifndef INPUT_HANDLER_HPP
#define INPUT_HANDLER_HPP

#include "SDL3/sdl.h"
#include "EventObject.hpp"

class InputHandler : public EventObject {
	public:
		InputHandler();

		virtual void Handle(const SDL_Event& event);
	private:
};

#endif // InputHandler