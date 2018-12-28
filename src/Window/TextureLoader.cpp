/*
 * Texture.cpp
 *
 *  Created on: 17 nov. 2018
 *      Author: PyJaC++
 */

#include "TextureLoader.h"

#include <iostream>
#include <stdexcept>

#include "../General.h"


namespace ta
{

TextureLoader::TextureLoader() :
        m_mapTextureLoaded(), m_resourcePack("default")
{
    loadTextureFromFile("null.png", sf::IntRect(), "null");
}

TextureLoader::~TextureLoader()
{
    deloadAllTexture();
}

void TextureLoader::loadTexture(std::string nameTexture, sf::Texture* tex)
{
    m_mapTextureLoaded[nameTexture] = tex;
}

void TextureLoader::deloadTexture(std::string nameTexture)
{
    sf::Texture * tex = m_mapTextureLoaded[nameTexture];
    
    m_mapTextureLoaded.erase(nameTexture);

    delete tex;
}

void TextureLoader::deloadAllTexture()
{
    while (m_mapTextureLoaded.size() != 0) // while they have element in map
    {
        std::map<std::string, sf::Texture*>::iterator it =
                m_mapTextureLoaded.begin(); // get first element
                
        sf::Texture *tex = it->second;
        
        m_mapTextureLoaded.erase(it);
        
        delete tex;
    }
}

void TextureLoader::loadTextureFromFile(std::string fileName, sf::IntRect area,
        std::string textureName)
{
    if (textureName == "") textureName = fileName;

    if (textureExist(textureName)) // if th texture already exist print and return
    {
        ta::log::warm("Texture " + textureName + " already exist !");
        return;
    }

    sf::Texture * tex = new sf::Texture();

    tex->loadFromFile(getFile(fileName), area);

    if (!tex)
    {
        ta::log::error(
                "Can't load texture: " + fileName + " called " + textureName);
        tex->loadFromFile(getFile("null"));

        if (!tex) /* if the default texture not exist in resourcePack get the default */
        {
            ta::log::error(
                    "Can't load texture default in " + m_resourcePack
                            + ". Load the default");
            
            tex->loadFromFile(DEFAULT_TEXTURE);
        }
    }

    loadTexture(textureName, tex);
}

bool TextureLoader::textureExist(std::string textureExist)
{
    std::map<std::string, sf::Texture*>::iterator it = m_mapTextureLoaded.find(
            textureExist);

    return it != m_mapTextureLoaded.end();
}

sf::Texture* TextureLoader::getTexture(std::string textureName)
{
    
    if (textureExist(textureName)) return m_mapTextureLoaded[textureName];
    else
    {
        if (textureName != "null")
        {
            ta::log::error("The texture " + textureName + " don't exist");
            return getTexture("null");
            }
        else throw std::runtime_error("Texture null don't extist !");
    }
}

std::string TextureLoader::getFile(std::string fileName)
{
    return "resourcepack/" + m_resourcePack + "/" + fileName;
}

std::string TextureLoader::resourcePack()
{
    return m_resourcePack;
}

void TextureLoader::setResourcePack(std::string rescourcePack)
{
    m_resourcePack = rescourcePack;
}

}  // namespace ta
