#ifndef EVENT_OBJECT_HPP
#define EVENT_OBJECT_HPP

#include "SDL3/sdl.h"

class EventObject {
	public:
		virtual ~EventObject() = default;

		virtual void Handle(const SDL_Event& event) = 0;
	private:
};

#endif // EVENT_OBJECT_HPP