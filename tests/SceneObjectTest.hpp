/*
 * =====================================================================================
 *
 *       Filename:  SceneObjectTest.hpp
 *
 *    Description:  
 *
 *        Created:  05/05/2015 13:33:53
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include <cxxtest/TestSuite.h>

#include "Exception.hpp"
#include "SceneObject.hpp"

class SceneObjectTest : public CxxTest::TestSuite  {
	public:
		void testGet() {
			SceneObject object;
			
			TS_ASSERT_THROWS(object.get<int>(), Exception);
			// TS_ASSERT_THROWS_ANYTHING(object.get<int>());
		}
		
		void testSet() {
			SceneObject object;
			object.set<int>(5);
			
			TS_ASSERT(object.has<int>());
			TS_ASSERT_EQUALS(object.get<int>(), 5);
			
			object.set<int>(8);
			
			TS_ASSERT_EQUALS(object.get<int>(), 8);
		}
		
		void testRemove() {
			SceneObject object;
			object.set<int>(5);
			object.remove<int>();
			
			TS_ASSERT(!object.has<int>());
		}
};

