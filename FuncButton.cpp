#include "FuncButton.h"

void FuncButton::perform(std::string str) {
	doIt(str);
}

FuncButton::FuncButton(const SDL_Rect& r, std::string pathUp, std::string pathDown, std::string str, void(*f)(std::string))
	: Button(r, pathUp, pathDown, str), doIt(f)
{
}


FuncButton* FuncButton::getInstance(const SDL_Rect& r, std::string pathUp, std::string pathDown, std::string str, void(*f)(std::string)) {
	return new FuncButton(r, pathUp, pathDown, str, f);
}
