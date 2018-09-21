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

#include "SceneObject.hpp"
#include "Sprite.hpp"
#include "Text.hpp"

class StatsBar : public IDrawable {
	public:
		StatsBar();

		void update(const SceneObject &player);
		void updateRupees(const SceneObject &player);
		void updateHearts(const SceneObject &player);

	private:
		void draw(RenderTarget &target, RenderStates states) const override;

		Image m_background{"interface-stats"};

		Text m_rupees{"interface-numbers", 7, 6};
		Text m_hearts{"interface-hearts", 7, 7};
};

#endif // STATSBAR_HPP_
