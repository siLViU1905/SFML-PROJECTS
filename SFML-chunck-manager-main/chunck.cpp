#include "chunck.h"
#include <iostream>

namespace sts
{
	chunck::chunck() :size(4),componentSize(50.f) 
    {
        components.assign(size, std::vector<structure*>(size));
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                components[i][j] = nullptr;
    }

	chunck::chunck(unsigned int chunckSize,float componentSize) :size(chunckSize),componentSize(componentSize) 
    {
        components.assign(size, std::vector<structure*>(size));
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                components[i][j] = nullptr;
    }

    chunck::chunck(const chunck& other)
    {
        components.assign(1, std::vector<structure*>(1));
        position = other.position;
        size = other.size;
        componentSize = other.componentSize;
    }

	bool chunck::contains(const sf::FloatRect& frect) const
	{
        float chunkRight = position.x + (float)size * componentSize;
        float chunkBottom = position.y + (float)size * componentSize;

        float rectRight = frect.position.x + frect.size.x;
        float rectBottom = frect.position.y + frect.size.y;

        return (frect.position.x >= position.x) && (rectRight <= chunkRight) &&
            (frect.position.y >= position.y) && (rectBottom <= chunkBottom);
	}


    bool chunck::intersects(const sf::FloatRect& frect) const
    {
     float chunkRight = position.x + (float)size * componentSize;
            float chunkBottom = position.y + (float)size * componentSize;
   
            float rectRight = frect.position.x + frect.size.x;
            float rectBottom = frect.position.y + frect.size.y;

            bool xOverlap = (frect.position.x < chunkRight) && (rectRight > position.x);
            bool yOverlap = (frect.position.y < chunkBottom) && (rectBottom > position.y);

            return xOverlap && yOverlap;
    }

    void chunck::setPosition(const sf::Vector2f& position)
    {
        this->position = position;
    }

    sf::Vector2f chunck::getPosition() const
    {
        return position;
    }

    void chunck::loadChunck()
    {
        float x_step = position.x, y_step = position.y;

        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                components[i][j] = sts::generateStructure(0.05f);
                components[i][j]->getComponent().setSize({ componentSize, componentSize });
                components[i][j]->getComponent().setPosition({ x_step,y_step });
                components[i][j]->textureFile(nullptr);
                components[i][j]->_generate();
                x_step += componentSize;
            }
            x_step = position.x;
            y_step += componentSize;
        }
        std::cout << "Chunck loaded\n";
    }


    std::vector<std::vector<structure*>>& chunck::getComponents()
    {
        return components;
    }

    const std::vector<std::vector<structure*>>& chunck::getComponents() const
    {
        return components;
    }



    unsigned int chunck::getSize() const
    {
        return size;
    }

    float chunck::getComponentSize() const
    {
        return componentSize;
    }


    void chunck::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                target.draw(*components[i][j]);
    }

    chunck::~chunck()
    {
        if (components[0][0])
            for (int i = 0; i < size; ++i)
                for (int j = 0; j < size; ++j)
                    delete components[i][j];
    }
}