/*
 * =====================================================================================
 *
 *       Filename:  Config.hpp
 *
 *    Description:
 *
 *        Created:  15/09/2018 19:28:43
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef CONFIG_HPP_
#define CONFIG_HPP_

namespace {
	constexpr const char *APP_NAME = "The Legend of Zelda";

	constexpr int SCREEN_WIDTH  = 160;
	constexpr int SCREEN_HEIGHT = 144;
}

#include <cassert>

// FIXME: Pre-C++17 fix
namespace std {
	template<class T>
	constexpr const T &clamp(const T& v, const T& lo, const T& hi)
	{
		return clamp(v, lo, hi, std::less<>());
	}

	template<class T, class Compare>
	constexpr const T &clamp(const T &v, const T &lo, const T &hi, Compare comp)
	{
		return assert(!comp(hi, lo)), comp(v, lo) ? lo : comp(hi, v) ? hi : v;
	}
}

#endif // CONFIG_HPP_
