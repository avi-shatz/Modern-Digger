#include "Menu.h"
////////////////////////////

Menu::Menu() 
    : m_window(sf::VideoMode(1580, 1100), "Example")
{
    //++++ Font ++++
    m_Font.loadFromFile("C:/Windows/Fonts/georgiaz.ttf");  
    //++++ Sound ++++
    m_Buffer.loadFromFile("resources/musicloop.wav");
    m_sound.setBuffer(m_Buffer);

    //++++  image_background  ++++
    CreateBackground();
    //++++  image_digger ++++
    CreateDigger();
    //++++ Message ++++
    CreateMessage();
    //++++  butterfly  ++++
    CreateButterfly();
    //++++  Sign ++++
    CreateSign();
}


void Menu::Run()
{

    m_sound.play();

    while (m_window.isOpen())
    {
        draw();

        if (auto event = sf::Event{}; m_window.waitEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                m_window.close();
                break;

            case sf::Event::MouseButtonReleased:
            {
                auto position = m_window.mapPixelToCoords(
                    { event.mouseButton.x, event.mouseButton.y });


                if (m_SpriteClose.getGlobalBounds().contains(position))
                {
                    m_window.close();
                    return;
                }
                else if (m_SpriteStart.getGlobalBounds().contains(position))
                {
                    m_sound.pause();
                    Controller().run();
                    m_sound.play();
                }
                else if (m_SpriteStatistic.getGlobalBounds().contains(position))
                {
                        Statistic().showFileStatistic();
                }

            }
            break;
            }
        }
    }
}

void Menu::draw()
{
    m_window.clear();
    m_window.draw(m_SpriteBackground);
    m_window.draw(m_SpriteDigger);
    m_window.draw(m_SpriteStart);
    m_window.draw(m_SpriteClose);
    m_window.draw(m_SpriteStatistic);
    m_window.draw(m_SpriteButterfly);
    m_window.draw(m_Startmessage);
    m_window.draw(m_Closemessage);
    m_window.draw(m_Statisticmessage);
    m_window.display();
}



void Menu::CreateBackground()
{   
    if (!m_TextBackground.loadFromFile("ImageBackGround.png")) {
        std::cout << "error" << std::endl;
    }
    m_SpriteBackground.setTexture(m_TextBackground);
}


void Menu::CreateMessage()
{
    //++++  message Start ++++
    m_Startmessage = sf::Text(STRINGSTART, m_Font);
    m_Startmessage.setPosition(sf::Vector2f(130, 290));
    m_Startmessage.setFillColor(sf::Color::Black);
    //++++  message Close ++++
    m_Closemessage = sf::Text(STRINGCLOSE, m_Font);
    m_Closemessage.setPosition(sf::Vector2f(130, 440));
    m_Closemessage.setFillColor(sf::Color::Black);
    //++++  message Statistic ++++
    m_Statisticmessage = sf::Text(STRINGSTATISTIC, m_Font);
    m_Statisticmessage.setPosition(sf::Vector2f(130, 590));
    m_Statisticmessage.setFillColor(sf::Color::Black);
}

void Menu::CreateDigger()
{
    if (!m_TextDigger.loadFromFile("super.png")) {
        std::cout << "error" << std::endl;
    }
    m_SpriteDigger.setTexture(m_TextDigger);
    m_SpriteDigger.setPosition(sf::Vector2f(395, 665));
    m_SpriteDigger.scale(0.15f, 0.15f);
}

void Menu::CreateSign()
{
    //++++  Sign start ++++
    m_SpriteStart.setTexture(TextureSign(m_TextStart));
    m_SpriteStart.setPosition(sf::Vector2f(50, 250));
    m_SpriteStart.scale(0.26f, 0.26f);
    //++++  Sign close ++++
    m_SpriteClose.setTexture(TextureSign(m_TextClose));
    m_SpriteClose.setPosition(sf::Vector2f(50, 400));
    m_SpriteClose.scale(0.26f, 0.26f);
    //++++  Sign Statistic ++++
    m_SpriteStatistic.setTexture(TextureSign(m_TextStatistic));
    m_SpriteStatistic.setPosition(sf::Vector2f(50, 550));
    m_SpriteStatistic.scale(0.26f, 0.26f);
}

sf::Texture& Menu::TextureSign(sf::Texture& texture)
{
    if (!texture.loadFromFile("Sign.png")) {
        std::cout << "error" << std::endl;
    }
    return texture;
}

void Menu::CreateButterfly()
{
    if(!m_Textbutterfly.loadFromFile("butterfly_.png")) {
        std::cout << "error" << std::endl;
    }   
    m_SpriteButterfly.setTexture(m_Textbutterfly);
    m_SpriteButterfly.setPosition(sf::Vector2f(100, 100));
}

