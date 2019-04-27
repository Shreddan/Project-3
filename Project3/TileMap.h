#pragma once
#include "includes.h"

struct TileMap : public sf::Drawable, public sf::Transformable
{
	TileMap();
	~TileMap();


	bool load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height);
	
	//bool create(std::string fileData, std::string name);

	/*int getIndex(int x, int y);
	bool getSolid(int x, int y);*/

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		// apply the transform
		states.transform *= getTransform();

		// apply the tileset texture
		states.texture = &m_tileset;

		// draw the vertex array
		target.draw(m_vertices, states);
	}

	sf::VertexArray m_vertices;
	sf::Texture m_tileset;

	std::string sName;
	sf::Sprite* pSprite;
};
