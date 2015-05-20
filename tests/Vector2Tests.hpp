/*
 * =====================================================================================
 *
 *       Filename:  Vector2Tests.hpp
 *
 *    Description:  
 *
 *        Created:  12/05/2015 20:28:33
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef VECTOR2TESTS_HPP_
#define VECTOR2TESTS_HPP_

#include <cxxtest/TestSuite.h>

#include "Vector2.hpp"

class Vector2Tests : public CxxTest::TestSuite  {
	public:
		void testEqual() {
			Vector2i v1{5, 4}, v2{2, 6}, v3{5, 4};
			
			TS_ASSERT(v1 != v2);
			TS_ASSERT(v1 == v1);
			TS_ASSERT(v1 == v3);
		}
		
		void testAddition() {
			Vector2i v1{5, 4}, v2{2, 6}, v3{2, 3}, v4{4, 8};
			
			TS_ASSERT_EQUALS(v1 + v2, (Vector2i{ 7, 10}));
			TS_ASSERT_EQUALS(v2 + v3, (Vector2i{ 4,  9}));
			TS_ASSERT_EQUALS(v1 + v1, (Vector2i{10,  8}));
			TS_ASSERT_EQUALS(v4 + v2, (Vector2i{ 6, 14}));
		}
		
		void testSubtraction() {
			Vector2i v1{5, 4}, v2{2, 6}, v3{2, 3}, v4{4, 8};
			
			TS_ASSERT_EQUALS(v1 - v2, (Vector2i{ 3, -2}));
			TS_ASSERT_EQUALS(v2 - v3, (Vector2i{ 0,  3}));
			TS_ASSERT_EQUALS(v1 - v1, (Vector2i{ 0,  0}));
			TS_ASSERT_EQUALS(v4 - v2, (Vector2i{ 2,  2}));
		}
		
		void testMultiplication() {
			Vector2i v1{5, -4};
			
			TS_ASSERT_EQUALS(v1 * -4, (Vector2i{-20, 16}));
			TS_ASSERT_EQUALS(8 * v1, (Vector2i{40, -32}));
		}
};

#endif // VECTOR2TESTS_HPP_
