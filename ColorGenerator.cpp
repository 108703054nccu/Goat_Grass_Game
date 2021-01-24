#include "ColorGenerator.h"
Color::Modifier::Modifier(Code pCode) : code(pCode) {}

std::ostream& Color::operator<<(std::ostream& os, const Color::Modifier& mod) {
		return os << "\033[" << mod.code << "m";
}

