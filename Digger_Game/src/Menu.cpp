#include "Menu.h"
////////////////////////////

const int MENU_WIDTH = int(sf::VideoMode::getDesktopMode().width * 0.80);
const int MENU_HEIGHT = int(sf::VideoMode::getDesktopMode().height);

Menu::Menu() 
    : m_window(sf::VideoMode(MENU_WIDTH, MENU_HEIGHT), "Example") , m_bigButton(nullptr)
{
    //++++ Font ++++
    m_Font.loadFromFile("C:/Windows/Fonts/georgiaz.ttf");  
    //++++ Sound ++++
    m_Buffer.loadFromFile("resources/musicloop.wav");
    m_sound.setBuffer(m_Buffer);

    //++++  image_background  ++++
    m_SpriteBackground.setTexture(Resources::instance().getMenuBackground()); 

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

            case sf::Event::KeyReleased:
                switch (event.key.code)
                {
                case sf::Keyboard::Escape:
                    m_window.close();
                    return;
                }
            case sf::Event::MouseMoved:
            { //scope made for local variable (position)
                auto position = m_window.mapPixelToCoords(
                    { event.mouseMove.x, event.mouseMove.y });
                updateBigButton(position);
                  
            }
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


void Menu::CreateMessage()
{
    //++++  message Start ++++
    m_Startmessage = sf::Text(STRINGSTART, m_Font);
    m_Startmessage.setPosition(sf::Vector2f(130, 290));
    m_Startmessage.setFillColor(sf::Color::Black);
    m_Startmessage.setCharacterSize(38);

    //++++  message Close ++++
    m_Closemessage = sf::Text(STRINGCLOSE, m_Font);
    m_Closemessage.setPosition(sf::Vector2f(130, 440));
    m_Closemessage.setFillColor(sf::Color::Black);
    m_Closemessage.setCharacterSize(38);

    //++++  message Statistic ++++
    m_Statisticmessage = sf::Text(STRINGSTATISTIC, m_Font);
    m_Statisticmessage.setPosition(sf::Vector2f(122, 590));
    m_Statisticmessage.setFillColor(sf::Color::Black);
    m_Statisticmessage.setCharacterSize(38);

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
    m_SpriteStart.setTexture(Resources::instance().getMenuButton());
    m_SpriteStart.setPosition(sf::Vector2f(50, 250));
    m_SpriteStart.setScale(0.26f, 0.26f);

    //++++  Sign close ++++
    m_SpriteClose.setTexture(Resources::instance().getMenuButton());
    m_SpriteClose.setPosition(sf::Vector2f(50, 400));
    m_SpriteClose.setScale(0.26f, 0.26f);

    //++++  Sign Statistic ++++
    m_SpriteStatistic.setTexture(Resources::instance().getMenuButton());
    m_SpriteStatistic.setPosition(sf::Vector2f(50, 550));
    m_SpriteStatistic.setScale(0.26f, 0.26f);
}


void Menu::CreateButterfly()
{
    if(!m_Textbutterfly.loadFromFile("butterfly_.png")) {
        std::cout << "error" << std::endl;
    }   
    m_SpriteButterfly.setTexture(m_Textbutterfly);
    m_SpriteButterfly.setPosition(sf::Vector2f(100, 100));
}

void Menu::updateBigButton(sf::Vector2f position)
{

    if (m_SpriteClose.getGlobalBounds().contains(position))
        updateButton(&m_SpriteClose);

    else if (m_SpriteStart.getGlobalBounds().contains(position))
        updateButton(&m_SpriteStart);

    else if (m_SpriteStatistic.getGlobalBounds().contains(position))
        updateButton(&m_SpriteStatistic);

    else if (m_bigButton) // If the mouse is not on one of the buttons
    {
        m_bigButton->setScale(0.26f, 0.26f);
         m_bigButton->move(7, 7);
        m_bigButton = nullptr;
    }
}

void Menu::updateButton(sf::Sprite* button)
{
   
    if (m_bigButton != button)
    {
        if (m_bigButton)
        {
            m_bigButton->setScale(0.26f, 0.26f);
            m_bigButton->move(7, 7);
        }

      
        m_bigButton = button;
        m_bigButton->setScale(0.285f, 0.285f);
        m_bigButton->move(-7, -7);
    }
}

