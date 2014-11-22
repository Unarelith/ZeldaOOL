/*
 * =====================================================================================
 *
 *       Filename:  Drawable.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  22/11/2014 23:02:44
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef DRAWABLE_HPP_
#define DRAWABLE_HPP_

class Drawable {
	public:
		Drawable();
		virtual ~Drawable();
		
		virtual void draw() = 0;
		
		bool hasView() { return m_view.loaded(); }
		void useView() { m_view.use(); }
		
	private:
		View m_view;
};

#endif // DRAWABLE_HPP_
