/*
 * Texture.h
 *
 *  Created on: 17 nov. 2018
 *      Author: antonin
 */

#ifndef SRC_WINDOW_TEXTURE_H_
#define SRC_WINDOW_TEXTURE_H_

#include <SFML/Graphics/Rect.hpp>
#include <string>

#define NULL_TEXTURE "assets/null.png"

namespace sf
{
class Texture;
} /* namespace sf */

namespace ta
{
namespace Texture
{

sf::Texture loadTextureFromFile(std::string fileName, bool smooth = true);
sf::Texture loadTextureFromFile(std::string fileName, sf::IntRect area,
		bool smooth = true);

}  // namespace Texture


}  // namespace ta



#endif /* SRC_WINDOW_TEXTURE_H_ */
