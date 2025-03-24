#include "animation.h"

namespace sts
{
	direction_state::direction_state():up(false),left(false),right(false),down(false){}



  animation::animation(sf::Texture* texture,const sf::Vector2u& imageCount, float switchTime):texture(texture)
  {
	  this->imageCount = imageCount;
	  this->switchTime = switchTime;
	  totalTime = 0.f;
	  currentImage.x = 0;

	  rect.size.x = texture->getSize().x / (float)imageCount.x;
	  rect.size.y = texture->getSize().y / (float)imageCount.y;
  }

  void animation::update(int row, float deltaTime,direction_state direction)
  {
	  currentImage.y = row;
	  totalTime += deltaTime;
	  if (totalTime >= switchTime)
	  {
		  totalTime -= switchTime;
		  ++currentImage.x;
		  currentImage.x %= imageCount.x;
	  }
	  rect.position.y = currentImage.y * rect.size.y;
	  rect.position.x = currentImage.x * rect.size.x;
	
  }




  animation::~animation() {}


}
