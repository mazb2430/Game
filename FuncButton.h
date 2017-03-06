#ifndef FUNCBUTTON_H
#define FUNCBUTTON_H
#include "Button.h"
class FuncButton :
	public Button
{
public:
	static FuncButton* getInstance(const SDL_Rect& r, std::string pathUp, std::string pathDown, std::string str, void(*f)(std::string));
	void perform(std::string str);
protected:
	FuncButton(const SDL_Rect& r, std::string pathUp, std::string pathDown, std::string str, void(*f)(std::string));
private:
	void(*doIt)(std::string);
};

#endif

