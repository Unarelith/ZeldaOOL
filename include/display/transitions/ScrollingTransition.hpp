/*
 * =====================================================================================
 *
 *       Filename:  ScrollingTransition.hpp
 *
 *    Description:
 *
 *        Created:  05/10/2014 17:45:49
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef SCROLLINGTRANSITION_HPP_
#define SCROLLINGTRANSITION_HPP_

#include "TileMap.hpp"
#include "Transition.hpp"

class ScrollingTransition : public Transition {
	public:
		enum class Mode {
			ScrollingLeft,
			ScrollingRight,
			ScrollingUp,
			ScrollingDown
		};

		ScrollingTransition(SceneObject &player, SceneObject &tilemap, Mode mode);

		void update() override;

	private:
		void draw(RenderTarget &target, RenderStates states) const override;

		Mode m_mode;

		float m_vx = 0;
		float m_vy = 0;

		float m_scrolled = 0;

		TileMap *m_nextMap = nullptr;

		SceneObject &m_player;
		SceneObject &m_tilemap;
};

#endif // SCROLLINGTRANSITION_HPP_
