/*
 * Texture.cpp
 *
 *  Created on: 17 nov. 2018
 *      Author: antonin
 */

#include "Texture.h"

#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <iostream>
#include <string>

namespace ta
{
namespace Texture
{

sf::Texture loadTextureFromFile(std::string fileName, bool smooth)
{
	sf::Texture tex;

	if (!tex.loadFromFile(fileName))
	{
		std::cerr << "Can't load: " << fileName;
		tex.loadFromFile(NULL_TEXTURE);
		return tex;
	}
	tex.setSmooth(smooth);

	return tex;
}

sf::Texture loadTextureFromFile(std::string fileName, sf::IntRect area,
		bool smooth)
{
	sf::Texture tex;

	if (!tex.loadFromFile(fileName, area))
	{
		std::cerr << "Can't load: " << fileName;
		tex.loadFromFile(NULL_TEXTURE);
		return tex;
	}
		tex.setSmooth(smooth);

	return tex;
}

}  // namespace Texture
}  // namespace ta
