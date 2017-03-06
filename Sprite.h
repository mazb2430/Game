#ifndef SPRITE_H
#define SPRITE_H
#include "SDL.h"

	class Sprite
	{
	public:
		virtual void draw() = 0;
		virtual void mouseUp(const SDL_Event& event) {}
		virtual void mouseDown(const SDL_Event& event){}
		virtual void keyUp(const SDL_Event& event){}
		virtual void keyDown(const SDL_Event& event) {}
		virtual void tick(){}
		SDL_Rect getRect() const { return rect; }
		bool getVisible() const { return visible; }
		void setY(int y);
		void setX(int x);
		void setVisible(bool c);
		virtual ~Sprite();
	protected:
		Sprite(const SDL_Rect& rect);
	private:
		SDL_Rect rect;
		bool visible = false;
		Sprite(const Sprite&) = delete;
		const Sprite& operator = (const Sprite&) = delete;
	};

#endif
