#include <SFML/Graphics.h>

int main()
{

	sfRenderWindow *window;
	sfVideoMode mode;
	mode.bitsPerPixel = 32;
	mode.height = 200;
	mode.width = 200;
	window = sfRenderWindow_create(mode,"",0, NULL);
	while(sfWindow_isOpen(window));

	/*
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);g
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
	sf::Event event;
	while (window.pollEvent(event))
	{
	if (event.type == sf::Event::Closed)
	window.close();
	}

	window.clear();
	window.draw(shape);
	window.display();
	}
	*/
	return 0;
}