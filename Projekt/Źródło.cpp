#define Liczba_wierszy 3
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <iostream>
#include <windows.h>
#include <ctime>
#include <chrono>
#include <random>
#include <cmath>
class Ball {
private:
	sf::Vector2f position;
public:
	sf::CircleShape ball;
	Ball(float x_in, float y_in);
	void przesun(float x_in, float y_in);
	sf::CircleShape getBall() { return ball; }
	sf::Vector2f getPos() { return ball.getPosition(); }
};
class Menu
{
private:
	sf::Font font;
	sf::Text menu[Liczba_wierszy];
	int selectedItem = 0;
public:
	Menu(float width, float height);
	~Menu() {};
	void przesunG();
	void przesunD();
	int getSelectedItem() { return selectedItem; }
	void draw(sf::RenderWindow& Okno);
};
void sprawdzKolizje(Ball& p1, Ball& p2, Ball& p3, Ball& p4, Ball& p5, Ball& p6, int
	px, int py) {
	p1.przesun(px, py);
	sf::FloatRect intersection;
	if (p1.ball.getGlobalBounds().intersects(p2.ball.getGlobalBounds(),
		intersection)) {
		p1.przesun(-px, -py);
	}
	else if (p1.ball.getGlobalBounds().intersects(p3.ball.getGlobalBounds(),
		intersection)) {
		p1.przesun(-px, -py);
	}
	else if (p1.ball.getGlobalBounds().intersects(p4.ball.getGlobalBounds(),
		intersection)) {
		p1.przesun(-px, -py);
	}
	else if (p1.ball.getGlobalBounds().intersects(p5.ball.getGlobalBounds(),
		intersection)) {
		p1.przesun(-px, -py);
	}
	else if (p1.ball.getGlobalBounds().intersects(p6.ball.getGlobalBounds(),
		intersection)) {
		p1.przesun(-px, -py);
	}
}
void Menu::draw(sf::RenderWindow& Okno) {
	for (int i = 0; i < Liczba_wierszy; i++)
	{
		Okno.draw(menu[i]);
	}
}
void Menu::przesunG() {
	if (selectedItem >= 0 && selectedItem < Liczba_wierszy)
	{
		menu[selectedItem].setFillColor(sf::Color::White);
		menu[selectedItem].setStyle(sf::Text::Regular);
		selectedItem--;
		if (selectedItem < 0)
			selectedItem = Liczba_wierszy - 1;
		menu[selectedItem].setFillColor(sf::Color::Red);
		menu[selectedItem].setStyle(sf::Text::Bold);
	}
}
void Menu::przesunD() {
	if (selectedItem >= 0 && selectedItem < Liczba_wierszy) {
		menu[selectedItem].setFillColor(sf::Color::White);
		menu[selectedItem].setStyle(sf::Text::Regular);
		selectedItem++;
		if (selectedItem >= Liczba_wierszy)
			selectedItem = 0;
		menu[selectedItem].setFillColor(sf::Color::Red);
		menu[selectedItem].setStyle(sf::Text::Bold);
	}
}
void myDelay(int opoznienie) {
	sf::Clock zegar;
	sf::Time czas;
	while (1)
	{
		czas = zegar.getElapsedTime();
		if (czas.asMilliseconds() > opoznienie)
		{
			zegar.restart();
			break;
		}
	}
}
class Menu2
{
private:
	sf::Font font;
	sf::Text menu[Liczba_wierszy];
	int selectedItem = 0;
public:
	Menu2(float width, float height);
	~Menu2() {};
	int getSelectedItem() { return selectedItem; }
	void draw(sf::RenderWindow& Okno);
};
Menu2::Menu2(float width, float height) {
	if (!font.loadFromFile("arial.ttf"))return;
	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::White);
	menu[0].setString("Poruszaj sie klawiszem Alt + W,A,S,D");
	menu[0].setPosition(sf::Vector2f(width / 4, height / (Liczba_wierszy + 1) *
		1));
	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Aby wyjsc wcisnij ESC");
	menu[1].setPosition(sf::Vector2f(width / 4, height / (Liczba_wierszy + 1) *
		2));
	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Aby powrocic wcisnij ENTER");
	menu[2].setPosition(sf::Vector2f(width / 4, height / (Liczba_wierszy + 1) *
		3));
}
//rysowanie menu w biezacym oknie
void Menu2::draw(sf::RenderWindow& Okno) {
	for (int i = 0; i < Liczba_wierszy; i++)
		Okno.draw(menu[i]);
}
int main() {
	int TypMenu = 0;
	int Wyjdz = 0;
	while (Wyjdz == 0) {
		if (TypMenu == 1) {
			int TablicaPilek[5][3];
			for (int i = 0; i < 5; i++) {
				std::random_device dev;
				std::mt19937 rng(dev());
				std::uniform_int_distribution<std::mt19937::result_type>
					dist6(0, 560);
				TablicaPilek[i][2] = dist6(rng);
				std::cout << "p" << i + 1 << " y: " << TablicaPilek[i][2]
					<< std::endl;
			}
			for (int i = 0; i < 5; i++)
				TablicaPilek[i][0] = i;
			for (int i = 0; i < 5; i++) {
				std::random_device dev;
				std::mt19937 rng(dev());
				std::uniform_int_distribution<std::mt19937::result_type>
					dist6(0, 760);
				TablicaPilek[i][1] = dist6(rng);
				std::cout << "p" << i + 1 << " x: " << TablicaPilek[i][1]
					<< std::endl;
			}
			sf::RenderWindow Okno(sf::VideoMode(800, 600), "MOJA GRA");
			Ball p1(400, 300);
			Ball p2(TablicaPilek[0][1], TablicaPilek[0][2]);
			Ball p3(TablicaPilek[1][1], TablicaPilek[1][2]);
			Ball p4(TablicaPilek[2][1], TablicaPilek[2][2]);
			Ball p5(TablicaPilek[3][1], TablicaPilek[3][2]);
			Ball p6(TablicaPilek[4][1], TablicaPilek[4][2]);
			int x = 0, y = 0;
			int px = 5, py = 5;
			sf::Clock zegar;
			while (Okno.isOpen() && Wyjdz == 0) {
				sf::Event event;
				while (Okno.pollEvent(event) && Wyjdz == 0)
				{
					if (event.type == sf::Event::KeyPressed) {
						if (event.key.code == sf::Keyboard::Escape)
						{
							std::cout << "Koniec" << std::endl;
							Wyjdz = 1;
							break;
						}
					}
				}
				while (Okno.pollEvent(event)) {
					if (event.type == sf::Event::Closed)
						Okno.close();
				}
				if (zegar.getElapsedTime().asMilliseconds() > 33.3f) {
					if (p1.getPos().x < 10)
						p1.przesun(px, 0);
					if (p1.getPos().x > Okno.getSize().x - 50)
						p1.przesun(-px, 0);
					if (p1.getPos().y < 10)
						p1.przesun(0, py);
					if (p1.getPos().y > Okno.getSize().y - 50)
						p1.przesun(0, -py);
					if (event.type == sf::Event::KeyPressed)
					{
						if (event.key.code == sf::Keyboard::W)
							sprawdzKolizje(p1, p2, p3, p4, p5, p6, 0, -py);
						if (event.key.code == sf::Keyboard::S)
							sprawdzKolizje(p1, p2, p3, p4, p5, p6, 0, py);
						if (event.key.code == sf::Keyboard::A)
							sprawdzKolizje(p1, p2, p3, p4, p5, p6, -px, 0);
						if (event.key.code == sf::Keyboard::D)
							sprawdzKolizje(p1, p2, p3, p4, p5, p6, px, 0);
					}
					zegar.restart();
				}
				Okno.clear(sf::Color::Black);
				Okno.draw(p1.getBall());
				Okno.draw(p2.getBall());
				Okno.draw(p3.getBall());
				Okno.draw(p4.getBall());
				Okno.draw(p5.getBall());
				Okno.draw(p6.getBall());
				Okno.display();
			}
		}
		if (TypMenu == 2) {
			int menu_selected_flag = 0;
			sf::RenderWindow Okno(sf::VideoMode(800, 600), "Pomoc!");
			Menu2 menu2(Okno.getSize().x, Okno.getSize().y);
			while (Okno.isOpen() && Wyjdz == 0) {
				sf::Event event;
				while (Okno.pollEvent(event) && Wyjdz == 0) {
					if (event.type == sf::Event::KeyPressed) {
						if (event.key.code == sf::Keyboard::Enter) {
							std::cout << "Uruchamiam" <<
								std::endl;
							menu_selected_flag = 1;
							TypMenu = 0;
							Okno.clear();
							std::cout << "Wracam do MENU" <<
								std::endl;
							Okno.close();
							break;
						}
						if (event.key.code == sf::Keyboard::Escape)
						{
							std::cout << "Koniec!!" << std::endl;
							menu_selected_flag = 1;
							Wyjdz = 1;
							break;
						}
					}
				}
				Okno.clear();
				if (menu_selected_flag == 0)
					menu2.draw(Okno);
				Okno.display();
			}
		}
		if (TypMenu == 0)
		{
			int menu_selected_flag = 0;
			sf::RenderWindow Okno(sf::VideoMode(800, 600), "demo");
			Menu menu(Okno.getSize().x, Okno.getSize().y);
			while (Okno.isOpen() && Wyjdz == 0) {
				sf::Event event;
				while (Okno.pollEvent(event) && Wyjdz == 0) {
					if (event.type == sf::Event::Closed)
						Okno.close();
					if (event.type == sf::Event::KeyPressed) {
						if (event.key.code == sf::Keyboard::Up) {
							myDelay(250);
							menu.przesunG();
						}
						if (event.key.code == sf::Keyboard::Down) {
							myDelay(250);
							menu.przesunD();
						}
						if (menu_selected_flag == 0) {
							if (event.key.code ==
								sf::Keyboard::Enter && menu.getSelectedItem() == 0) {
								std::cout << "Uruchamiam" <<
									std::endl;
								menu_selected_flag = 1;
								TypMenu = 1;
								Okno.clear();
								std::cout << "Uruchamiam" <<
									std::endl;
								Okno.close();
								break;
							}
							if (event.key.code ==
								sf::Keyboard::Enter && menu.getSelectedItem() == 1) {
								std::cout << "Pomoc" <<
									std::endl;
								menu_selected_flag = 1;
								TypMenu = 2;
								Okno.clear();
								std::cout << "Pomoc" <<
									std::endl;
								Okno.close();
								break;
							}
							if (event.key.code ==
								sf::Keyboard::Enter && menu.getSelectedItem() == 2) {
								std::cout << "Koniec" <<
									std::endl;
								menu_selected_flag = 1;
								Wyjdz = 1;
								break;
							}
							if (event.key.code ==
								sf::Keyboard::Escape) {
								std::cout << "Koniec" <<
									std::endl;
								menu_selected_flag = 1;
								Wyjdz = 1;
								break;
							}
						}
					}
				}
				Okno.clear();
				if (menu_selected_flag == 0)
					menu.draw(Okno);
				Okno.display();
			}
		}
	}
}
Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("arial.ttf")) return;
	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("Nowa gra");
	menu[0].setPosition(sf::Vector2f(width / 3, height / (Liczba_wierszy + 1) *
		1));
	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Pomoc");
	menu[1].setPosition(sf::Vector2f(width / 3, height / (Liczba_wierszy + 1) *
		2));
	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Wyjscie");
	menu[2].setPosition(sf::Vector2f(width / 3, height / (Liczba_wierszy + 1) *
		3));
}
Ball::Ball(float x_in, float y_in) {
	position.x = x_in;
	position.y = y_in;
	ball.setRadius(20);
	ball.setFillColor(sf::Color(200, 82, 66));
	ball.setOutlineThickness(6);
	ball.setOutlineColor(sf::Color(56, 44, 150));
	ball.setPosition(position);
}
void Ball::przesun(float x_in, float y_in) {
	sf::Vector2f pos;
	pos.x = x_in;
	pos.y = y_in;
	ball.move(pos);
}