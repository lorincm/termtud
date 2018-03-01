//TERMTUD PROJEKT - LÕRINC MIHÁLY

//this code == shit

#include <iostream>
#include <string>
#include <algorithm>

#include <SFML/Window.hpp>
#include <SFML\Graphics.hpp>
#include <SFML/OpenGL.hpp>

const int w = 800;
const int h = 600;

void init(std::string &DNS, std::string &DNS2, std::string &mRNS, std::string &Amino, unsigned int rando);

int main()
{
	sf::RenderWindow		window(sf::VideoMode(w, h), "DNS kódolás", sf::Style::Close);
	sf::RectangleShape		typeBox(sf::Vector2f(550.0f, 50.0f));
	sf::RectangleShape		typeBox1(sf::Vector2f(550.0f, 50.0f));
	sf::RectangleShape		typeBox2(sf::Vector2f(550.0f, 50.0f));
	sf::RectangleShape		typeBox3(sf::Vector2f(550.0f, 50.0f));
	sf::RectangleShape		apply(sf::Vector2f(150.0f, 75.0f));
	bool				isTypeBox1Clicked = false;
	bool				isTypeBox2Clicked = false;
	bool				isTypeBox3Clicked = false;
	bool				isCheckd = false;
	sf::Text			DNSText, DNS2Display, RNSDisplay, AminoDisplay;
	sf::Font			font;

	srand(time(NULL));
	std::string			DNS, DNS2, mRNS;
	std::string			Amino;
	std::string			DNS2Input, mRNSInput, AminoInput;

	unsigned int			rando = 0;

	init(DNS, DNS2, mRNS, Amino, rando);
	std::cout << DNS2 << std::endl;
	std::cout << mRNS << std::endl;
	std::cout << Amino << std::endl;


	font.loadFromFile("C:\\Windows\\Fonts\\Arial.ttf");
	DNSText.setFont(font);
	DNS2Display.setFont(font);
	RNSDisplay.setFont(font);
	AminoDisplay.setFont(font);

	DNSText.setString(DNS);
	DNSText.setFillColor(sf::Color::Black);
	DNS2Display.setFillColor(sf::Color::Black);
	RNSDisplay.setFillColor(sf::Color::Black);
	AminoDisplay.setFillColor(sf::Color::Black);

	sf::FloatRect			orig = DNSText.getGlobalBounds();
	DNSText.setOrigin(orig.width / 2, orig.height / 2);
	DNSText.setPosition(w / 2, h / 2 - 157.0f);

	DNS2Display.setString("A DNS 2. szála");
	orig = DNS2Display.getGlobalBounds();
	DNS2Display.setOrigin(orig.width / 2, orig.height / 2);
	DNS2Display.setPosition(w / 2, h / 2 - 82.0f);

	apply.setFillColor(sf::Color(5, 105, 225));

	typeBox.setOrigin(275.0f, 25.0f);
	typeBox1.setOrigin(275.0f, 25.0f);
	typeBox2.setOrigin(275.0f, 25.0f);
	typeBox3.setOrigin(275.0f, 25.0f);
	apply.setOrigin(75.0f, 35.0f);

	typeBox.setPosition(w / 2, h / 2 - 150.0f);
	typeBox1.setPosition(w / 2, h / 2 - 75.0f);
	typeBox2.setPosition(w / 2, h / 2);
	typeBox3.setPosition(w / 2, h / 2 + 75.0f);
	apply.setPosition(w / 2, h / 2 + 175.0f);

	ShowWindow(GetConsoleWindow(), SW_HIDE);

	while (window.isOpen())
	{

		std::transform(mRNSInput.begin(), mRNSInput.end(), mRNSInput.begin(), ::toupper);
		std::transform(DNS2Input.begin(), DNS2Input.end(), DNS2Input.begin(), ::toupper);
		std::transform(AminoInput.begin(), AminoInput.end(), AminoInput.begin(), ::toupper);

		orig = DNS2Display.getGlobalBounds();
		DNS2Display.setOrigin(orig.width / 2, orig.height / 2);
		DNS2Display.setPosition(w / 2, h / 2 - 82.0f);

		orig = RNSDisplay.getGlobalBounds();
		RNSDisplay.setOrigin(orig.width / 2, orig.height / 2);
		RNSDisplay.setPosition(w / 2, h / 2 - 6);

		orig = AminoDisplay.getGlobalBounds();
		AminoDisplay.setOrigin(orig.width / 2, orig.height / 2);
		AminoDisplay.setPosition(w / 2, h / 2 + 65);


		if (DNS2Input.length() == 0 && !isTypeBox1Clicked)
		{
			DNS2Display.setString("A DNS 2. szála");
		}
		else
		{
			DNS2Display.setString(DNS2Input);
		}

		if (mRNSInput.length() == 0 && !isTypeBox2Clicked)
		{
			RNSDisplay.setString("A messenger RNS");
		}
		else
		{
			RNSDisplay.setString(mRNSInput);
		}

		if (AminoInput.length() == 0 && !isTypeBox3Clicked)
		{
			AminoDisplay.setString("Aminosavak");
		}
		else
		{
			AminoDisplay.setString(AminoInput);
		}


		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					auto pos = sf::Mouse::getPosition(window);

					if (typeBox1.getGlobalBounds().contains(pos.x, pos.y) && !isCheckd)
					{
						typeBox1.setFillColor(sf::Color(169, 169, 169));
						isTypeBox1Clicked = true;
					}
					else if (!isCheckd)
					{
						typeBox1.setFillColor(sf::Color::White);
						isTypeBox1Clicked = false;
					}

					if (typeBox2.getGlobalBounds().contains(pos.x, pos.y) && !isCheckd)
					{
						typeBox2.setFillColor(sf::Color(169, 169, 169));
						isTypeBox2Clicked = true;
					}
					else if (!isCheckd)
					{
						typeBox2.setFillColor(sf::Color::White);
						isTypeBox2Clicked = false;
					}

					if (typeBox3.getGlobalBounds().contains(pos.x, pos.y) && !isCheckd)
					{
						typeBox3.setFillColor(sf::Color(169, 169, 169));
						isTypeBox3Clicked = true;
					}
					else if (!isCheckd)
					{
						typeBox3.setFillColor(sf::Color::White);
						isTypeBox3Clicked = false;
					}

					if (apply.getGlobalBounds().contains(pos.x, pos.y) && !isCheckd)
					{

						std::transform(mRNSInput.begin(), mRNSInput.end(), mRNSInput.begin(), ::toupper);
						std::transform(DNS2Input.begin(), DNS2Input.end(), DNS2Input.begin(), ::toupper);
						std::transform(AminoInput.begin(), AminoInput.end(), AminoInput.begin(), ::toupper);

						DNS2Input.push_back(char(32));
						mRNSInput.push_back(char(32));
						AminoInput.push_back(char(32));

						if (DNS2 != DNS2Input)
						{
							typeBox1.setFillColor(sf::Color::Red);
						}
						else if (DNS2 == DNS2Input)
						{
							typeBox1.setFillColor(sf::Color::Green);
						}

						if (mRNS != mRNSInput)
						{
							typeBox2.setFillColor(sf::Color::Red);
						}
						else if (mRNS == mRNSInput)
						{
							typeBox2.setFillColor(sf::Color::Green);
						}

						if (Amino != AminoInput)
						{
							typeBox3.setFillColor(sf::Color::Red);
						}
						else if (Amino == AminoInput)
						{
							typeBox3.setFillColor(sf::Color::Green);
						}

						isCheckd = true;

					}
					else if (apply.getGlobalBounds().contains(pos.x, pos.y) && isCheckd)
					{
						DNS = "";
						DNS2 = "";
						mRNS = "";
						Amino = "";

						DNS2Input = "";
						mRNSInput = "";
						AminoInput = "";

						DNS2Display.setString(DNS2);
						RNSDisplay.setString(mRNS);
						AminoDisplay.setString(AminoInput);

						typeBox1.setFillColor(sf::Color::White);
						typeBox2.setFillColor(sf::Color::White);
						typeBox3.setFillColor(sf::Color::White);

						init(DNS, DNS2, mRNS, Amino, rando);
						isCheckd = false;
					}
				}
			}

			if (event.type == sf::Event::MouseMoved)
			{
				auto posi = sf::Mouse::getPosition(window);
				if (apply.getGlobalBounds().contains(posi.x, posi.y))
				{
					apply.setFillColor(sf::Color(30, 144, 255));
				}
				else
				{
					apply.setFillColor(sf::Color(5, 105, 225));
				}
			}

			if (event.type == sf::Event::TextEntered)
			{
				if (event.text.unicode<128 && isTypeBox1Clicked)
				{
					if (event.text.unicode == '\b' && DNS2Input.length() != 0)
					{
						DNS2Input.pop_back();
						DNS2Display.setString(DNS2Input);
						break;
					}
					if (DNS2Input.length()<23)
					{
						DNS2Input.push_back(event.text.unicode);
						DNS2Display.setString(DNS2Input);
					}
					std::cout << DNS2Input << std::endl;
				}
				else if (event.text.unicode < 128 && isTypeBox2Clicked)
				{
					if (event.text.unicode == '\b' && mRNSInput.length() != 0)
					{
						mRNSInput.pop_back();
						RNSDisplay.setString(mRNSInput);
						break;
					}
					if (mRNSInput.length() < 23)
					{
						mRNSInput.push_back(event.text.unicode);
						RNSDisplay.setString(mRNSInput);
					}
					std::cout << mRNSInput << std::endl;
				}
				else if (event.text.unicode<128 && isTypeBox3Clicked)
				{
					if (event.text.unicode == '\b' && AminoInput.length() != 0)
					{
						AminoInput.pop_back();
						AminoDisplay.setString(AminoInput);
						break;
					}
					if (AminoInput.length()<23)
					{
						AminoInput.push_back(event.text.unicode);
						AminoDisplay.setString(AminoInput);
					}
					std::cout << AminoInput << std::endl;
				}
			}

			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		DNSText.setString(DNS);

		window.clear(sf::Color::Black);

		window.draw(typeBox);
		window.draw(typeBox1);
		window.draw(typeBox2);
		window.draw(typeBox3);
		window.draw(apply);
		window.draw(DNSText);
		window.draw(DNS2Display);
		window.draw(RNSDisplay);
		window.draw(AminoDisplay);

		window.display();
	}
}

void init(std::string &DNS, std::string &DNS2, std::string &mRNS, std::string &Amino, unsigned int rando)
{
	int egy, ketto, harom;
	std::string::iterator it;
	std::string debug ="";
	std::string aminosavak[4][4][16];
	aminosavak[0][0][0] = "PHE";  aminosavak[0][1][0] = "SER"; aminosavak[0][2][0] = "TYR"; aminosavak[0][3][0] = "CYS";
	aminosavak[0][0][1] = "PHE";  aminosavak[0][1][1] = "SER"; aminosavak[0][2][1] = "TYR"; aminosavak[0][3][1] = "CYS";
	aminosavak[0][0][2] = "LEU";  aminosavak[0][1][2] = "SER"; aminosavak[0][2][2] = "STOP"; aminosavak[0][3][2] = "STOP";
	aminosavak[0][0][3] = "LEU";  aminosavak[0][1][3] = "SER"; aminosavak[0][2][3] = "STOP"; aminosavak[0][3][3] = "TRY";

	aminosavak[1][0][0] = "LEU";  aminosavak[1][1][0] = "PRO"; aminosavak[1][2][0] = "HIS"; aminosavak[1][3][0] = "ARG";
	aminosavak[1][0][1] = "LEU";  aminosavak[1][1][1] = "PRO"; aminosavak[1][2][1] = "HIS"; aminosavak[1][3][1] = "ARG";
	aminosavak[1][0][2] = "LEU";  aminosavak[1][1][2] = "PRO"; aminosavak[1][2][2] = "GLN"; aminosavak[1][3][2] = "ARG";
	aminosavak[1][0][3] = "LEU";  aminosavak[1][1][3] = "PRO"; aminosavak[1][2][3] = "GLN"; aminosavak[1][3][3] = "ARG";

	aminosavak[2][0][0] = "ILE";  aminosavak[2][1][0] = "THR"; aminosavak[2][2][0] = "ASN"; aminosavak[2][3][0] = "SER";
	aminosavak[2][0][1] = "ILE";  aminosavak[2][1][1] = "THR"; aminosavak[2][2][1] = "ASN"; aminosavak[2][3][1] = "SER";
	aminosavak[2][0][2] = "ILE";  aminosavak[2][1][2] = "THR"; aminosavak[2][2][2] = "LYS"; aminosavak[2][3][2] = "ARG";
	aminosavak[2][0][3] = "MET";  aminosavak[2][1][3] = "THR"; aminosavak[2][2][3] = "LYS"; aminosavak[2][3][3] = "ARG";

	aminosavak[3][0][0] = "VAL";  aminosavak[3][1][0] = "ALA"; aminosavak[3][2][0] = "ASP"; aminosavak[3][3][0] = "GLY";
	aminosavak[3][0][1] = "VAL";  aminosavak[3][1][1] = "ALA"; aminosavak[3][2][1] = "ASP"; aminosavak[3][3][1] = "GLY";
	aminosavak[3][0][2] = "VAL";  aminosavak[3][1][2] = "ALA"; aminosavak[3][2][2] = "GLU"; aminosavak[3][3][2] = "GLY";
	aminosavak[3][0][3] = "VAL";  aminosavak[3][1][3] = "ALA"; aminosavak[3][2][3] = "GLU"; aminosavak[3][3][3] = "GLY";

	for (int i = 0; i<6; i++)
	{
		for (int c = 0; c<3; c++)
		{
			rando = rand() % 4;
			switch (rando)
			{
			case 0:
				DNS.push_back('A');
				DNS2.push_back('T');
				mRNS.push_back('A'); 
				if (c == 0) 
				{
					egy = 2;
				}
				else if (c == 1) 
				{
					ketto = 2;
				}
				else if (c == 2)
				{
					harom = 2;
				}
				break;
			case 1:
				DNS.push_back('T');
				DNS2.push_back('A');
				mRNS.push_back('U');
				if (c == 0)
				{
					egy = 0;
				}
				else if (c == 1)
				{
					ketto = 0;
				}
				else if (c == 2)
				{
					harom = 0;
				}
				break;
			case 2:
				DNS.push_back('G');
				DNS2.push_back('C');
				mRNS.push_back('G');
				if (c == 0)
				{
					egy = 3;
				}
				else if (c == 1)
				{
					ketto = 3;
				}
				else if (c == 2)
				{
					harom = 3;
				}
				break;
			case 3:
				DNS.push_back('C');
				DNS2.push_back('G');
				mRNS.push_back('C');
				if (c == 0)
				{
					egy = 1;
				}
				else if (c == 1)
				{
					ketto = 1;
				}
				else if (c == 2)
				{
					harom = 1;
				}
				break;
			}
		}
		
		debug = aminosavak[egy][ketto][harom];

		for (it = debug.begin(); it != debug.end(); it++)
		{
			Amino.push_back(*it);
		}

		DNS.push_back(char(32));
		DNS2.push_back(char(32));
		mRNS.push_back(char(32));
		Amino.push_back(char(32));
	}
}
