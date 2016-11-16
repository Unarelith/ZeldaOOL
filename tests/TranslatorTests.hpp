/*
 * =====================================================================================
 *
 *       Filename:  TranslatorTests.hpp
 *
 *    Description:  
 *
 *        Created:  19/06/2015 00:50:47
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef TRANSLATORTESTS_HPP_
#define TRANSLATORTESTs_HPP_

#include <cxxtest/TestSuite.h>

#include "Translator.hpp"

class TranslatorTests : public CxxTest::TestSuite  {
	public:
		TranslatorTests() {
			Translator::setLocale("fr_FR");
		}
		
		void testTranslate() {
			TS_ASSERT_EQUALS(_t("id"), "text");
			
			TS_ASSERT(_t("id") != "foo");
			TS_ASSERT(_t("id") != "");
			
			TS_ASSERT_EQUALS(_t("foo"), "foo");
		}
};

#endif // TRANSLATORTESTS_HPP_
