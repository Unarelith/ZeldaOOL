/*
 * =====================================================================================
 *
 *       Filename:  Application.hpp
 *
 *    Description:
 *
 *        Created:  19/09/2014 19:37:36
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef APPLICATION_HPP_
#define APPLICATION_HPP_

#include "CoreApplication.hpp"

class Application : public CoreApplication {
	public:
		Application(int argc, char **argv) : CoreApplication(argc, argv) {}

		void init() override;
};

#endif // APPLICATION_HPP_
