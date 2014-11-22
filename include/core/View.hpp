/*
 * =====================================================================================
 *
 *       Filename:  View.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  22/11/2014 23:00:56
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef VIEW_HPP_
#define VIEW_HPP_

class View {
	public:
		View();
		~View();
		
		bool isLoaded() const { return m_isLoaded; }
		
	private:
		bool m_isLoaded;
};

#endif // VIEW_HPP_
