#include <iostream>
#include <string>

// old C-style macro
#define DSTR "TestString"

// more C++99 like
constexpr char* const cstr = "TestString";
constexpr char astr[] = "TestString";

// completely OO.
std::string ostr{ "TestString" };

// The solution I like the most, guarantee to be resolved compile time.
template< size_t N >
constexpr size_t length(char const (&)[N])
{
	return N - 1;
}

// more functional solution (it doesn't get resolved in compile time in debug though)
int constexpr length_rec(const char* str)
{
	return *str ? 1 + length_rec(str + 1) : 0;
}


int main()
{
	constexpr int alen = length(astr);
	constexpr int dlen = length(DSTR);
	// constexpr int clen = length(cstr); - DOESN'T WORK - const char* type is not const char []

	constexpr int alen_rec = length_rec(astr);
	constexpr int dlen_rec = length_rec(DSTR);
	constexpr int clen_rec = length_rec(cstr);

	const int olen = length_rec(ostr.c_str());

	std::cout << "cstr : " << clen_rec << "\n";
	std::cout << "ostr : " << olen << "\n";
	std::cout << "astr : " << alen << "\n";
	std::cout << "DSTR : " << dlen << "\n";


    return 0;
}
