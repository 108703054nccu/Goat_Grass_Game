#ifndef COLORGENERATOR_H
#define COLORGENERATOR_H
#include <iostream>
namespace Color {
	enum Code {
		FG_RED      = 31,
		FG_GREEN    = 32,
		FG_BLUE     = 34,
		FG_DEFAULT  = 39,
		FG_WHITE    = 97,
		BG_RED      = 41,
		BG_GREEN    = 42,
		BG_BLUE     = 44,
		BG_DEFAULT  = 49,
		BG_WHITE = 107,
		BG_LIGHT_GREEN = 102
	};
	class Modifier {
		public:
		Color::Code code;
		Modifier(Color::Code pCode);
		friend std::ostream & operator<<(std::ostream&, const Color::Modifier&);
	};
}

#endif //COLORGENERATOR_H
