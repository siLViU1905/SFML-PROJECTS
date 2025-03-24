#pragma once
#include "chunck.h"

namespace sts
{
	class chunck_handler
	{
		std::vector<std::vector<chunck*>> chuncks;
		chunck* chunckSettings;
	public:
		chunck_handler();

		chunck_handler(const chunck& chunckSettings);

		void preloadChuncks(const sf::Vector2f& position,unsigned int chunckCount);

		void addChunck(const sf::Vector2f& position);


		const std::vector<std::vector<chunck*>>& getChuncks() const;

		std::vector<std::vector<chunck*>>& getChuncks();

		~chunck_handler();
	};
}

