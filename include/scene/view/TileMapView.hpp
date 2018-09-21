/*
 * =====================================================================================
 *
 *       Filename:  TileMapView.hpp
 *
 *    Description:
 *
 *        Created:  21/04/2018 09:28:54
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef TILEMAPVIEW_HPP_
#define TILEMAPVIEW_HPP_

#include "AbstractView.hpp"

class TileMapView : public AbstractView {
	public:
		void draw(const SceneObject &object, RenderTarget &target, RenderStates states) const override;
};

#endif // TILEMAPVIEW_HPP_
