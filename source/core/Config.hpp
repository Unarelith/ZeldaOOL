/*
 * =====================================================================================
 *
 *  ZeldaOOL
 *
 *  Copyright (C) 2014-2020 Unarelith, Quentin Bazin <zelda.ool@unarelith.net>
 *
 *  This file is part of ZeldaOOL.
 *
 *  ZeldaOOL is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  ZeldaOOL is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with ZeldaOOL; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA
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
