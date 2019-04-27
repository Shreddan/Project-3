#pragma once
#include "includes.h"

struct TileMap : public sf::Drawable, public sf::Transformable
{
	TileMap();
	~TileMap();

	int mWidth;
	int mHeight;
	//int mapSize = mWidth * mHeight;


	bool load(const std::string& tileset, sf::Vector2u tileSize, std::vector<int> tiles, unsigned int width, unsigned int height);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		// apply the transform
		states.transform *= getTransform();

		// apply the tileset texture
		states.texture = &m_tileset;

		// draw the vertex array
		target.draw(m_vertices, states);
	}

	bool create(std::string fileData, std::vector<int>& level, int mWidth, int mHeight);

	sf::VertexArray m_vertices;
	sf::Texture m_tileset;

	std::string name;
	std::vector<int> level;
	std::string fileData;
	

	

};
