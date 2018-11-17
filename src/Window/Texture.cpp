/*
 * Texture.cpp
 *
 *  Created on: 17 nov. 2018
 *      Author: antonin
 */

#include "Texture.h"

#include <SFML/Graphics/Texture.hpp>
#include <string>

namespace ta
{
namespace Texture
{

sf::Texture loadTextureFromFile(std::string fileName, bool smooth)
{
	sf::Texture tex;

	tex.loadFromFile(fileName);
	tex.setSmooth(smooth);

	return tex;
}

sf::Texture loadTextureFromFile(std::string fileName, sf::IntRect area,
		bool smooth)
{
	sf::Texture tex;

	tex.loadFromFile(fileName, area);
	tex.setSmooth(smooth);

	return tex;
}

}  // namespace Texture
}  // namespace ta
