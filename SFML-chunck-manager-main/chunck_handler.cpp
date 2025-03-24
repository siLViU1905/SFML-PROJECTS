#include "chunck_handler.h"

namespace sts
{
	chunck_handler::chunck_handler():chunckSettings(nullptr) {}

	chunck_handler::chunck_handler(const chunck& chunckSettings)
	{
		this->chunckSettings = new chunck(chunckSettings);
	}

	void chunck_handler::preloadChuncks(const sf::Vector2f& position, unsigned int chunckCount)
	{
		chuncks.resize(chunckCount);
		for (int i = 0; i < chunckCount; ++i)
			chuncks[i].resize(chunckCount);

		float step = (float)chunckSettings->getSize() * chunckSettings->getComponentSize();
		float x = chunckSettings->getPosition().x;
		float y = chunckSettings->getPosition().y;
		for (int i = 0; i < chunckCount; ++i)
		{
			for (int j = 0; j < chunckCount; ++j)
			{
				chuncks[i][j] = new chunck(chunckSettings->getSize(),chunckSettings->getComponentSize());
				chuncks[i][j]->setPosition({ x,y });
				chuncks[i][j]->loadChunck();
				x += step;
			}
			x = chunckSettings->getPosition().x;
			y += step;
		}
	}

	void chunck_handler::addChunck(const sf::Vector2f& position)
	{
		
		unsigned int newSize = chuncks.size() +1;
		unsigned int oldSize = newSize - 1;
		chuncks.resize(newSize);
		for (int i = 0; i < newSize; ++i)
			chuncks[i].resize(newSize,nullptr);

		float step = (float)chunckSettings->getSize() * chunckSettings->getComponentSize();
		float x = position.x;
		float y = position.y;

		for (int i = 0; i < newSize; ++i)
		{
			chuncks[i][oldSize] = new chunck(chunckSettings->getSize(), chunckSettings->getComponentSize());
			chuncks[i][oldSize]->setPosition({ x,y });
			chuncks[i][oldSize]->loadChunck();

			chuncks[oldSize][i] = new chunck(chunckSettings->getSize(), chunckSettings->getComponentSize());
			chuncks[oldSize][i]->setPosition({ x,y });
			chuncks[oldSize][i]->loadChunck();
		}

	}


	const std::vector<std::vector<chunck*>>& chunck_handler::getChuncks() const
	{
		return chuncks;
	}


	std::vector<std::vector<chunck*>>& chunck_handler::getChuncks()
	{
		return chuncks;
	}


	chunck_handler::~chunck_handler()
	{
		if (chunckSettings)
			delete chunckSettings;
		if (chuncks[0][0])
			for (int i = 0; i < chuncks.size(); ++i)
				for (int j = 0; j < chuncks.size(); ++j)
					delete chuncks[i][j];
	}
}