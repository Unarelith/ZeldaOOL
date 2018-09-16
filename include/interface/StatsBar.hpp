/*
 * =====================================================================================
 *
 *       Filename:  StatsBar.hpp
 *
 *    Description:
 *
 *        Created:  15/09/2014 23:34:47
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef STATSBAR_HPP_
#define STATSBAR_HPP_

#include "Sprite.hpp"

class StatsBar : public IDrawable {
	public:
		void update();

	private:
		void draw(RenderTarget &target, RenderStates states) const override;
		void drawHearts(RenderTarget &target, RenderStates states) const;
		void drawRupees(RenderTarget &target, RenderStates states) const;

		Image m_background{"interface-stats"};
};

#endif // STATSBAR_HPP_
