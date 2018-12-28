/*
 * Texture.h
 *
 *  Created on: 17 nov. 2018
 *      Author: antonin
 */

#ifndef SRC_WINDOW_TEXTURELOADER_H_
#define SRC_WINDOW_TEXTURELOADER_H_

#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <map>
#include <string>

#define DEFAULT_TEXTURE "resourcepack/default_null.png"


namespace ta
{

class TextureLoader
{
public:
    TextureLoader();
    ~TextureLoader();
    
    /* Save textures with the name specified */
    void loadTexture(std::string nameTexture, sf::Texture* tex);
    /* Unsave the texture */
    void deloadTexture(std::string nameTexture);
    /* deload all texture. Use delaodTexture method */
    void deloadAllTexture();
    
    /* Load the texture with int rect and save then */
    void loadTextureFromFile(std::string fileName, sf::IntRect area =
            sf::IntRect(), std::string textureName = "");
    
    
    /* return if the texture <textureName> exist */
    bool textureExist(std::string textureName);
    
    
    /* return texture */
    sf::Texture* getTexture(std::string textureName);
    
    /* return the path of fileName. Use current resource pack folder */
    std::string getFile(std::string fileName);

    /* return the current resource pack */
    std::string resourcePack();


    /* set the current resource pack */
    void setResourcePack(std::string newRessourcePack);

private:
    std::map<std::string, sf::Texture*> m_mapTextureLoaded;

    std::string m_resourcePack;
};

}  // namespace ta



#endif /* SRC_WINDOW_TEXTURELOADER_H_ */
