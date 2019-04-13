/*
 * =====================================================================================
 *
 *       Filename:  StatsBar.hpp
 *
 *    Description:
 *
 *        Created:  15/09/2014 23:34:47
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef STATSBAR_HPP_
#define STATSBAR_HPP_

#include "Sprite.hpp"
#include "Text.hpp"

class StatsBar : public gk::Drawable {
	public:
		StatsBar();

		void update();
		void updateRupees();
		void updateHearts();

	private:
		void draw(gk::RenderTarget &target, gk::RenderStates states) const override;

		Image m_background{"interface-stats"};

		Text m_rupees{"interface-numbers", 7, 6};
		Text m_hearts{"interface-hearts", 7, 7};
};

#endif // STATSBAR_HPP_
