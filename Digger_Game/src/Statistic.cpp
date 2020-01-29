#include "Statistic.h"
#include <sstream>

Statistic::Statistic()
    :m_Window(sf::VideoMode(800, 600), "Statistic")
{ 
    m_Font.loadFromFile("C:/Windows/Fonts/constani.ttf");
    //+++++++  the title text  +++++ 
    m_textTitle = sf::Text(STRSTATISTIC, m_Font);
    m_textTitle.setPosition({ 240, 40 });
    m_textTitle.setFillColor(sf::Color::Black);
    //its read form a File the Statistic of the game
    readFileStatistic();
    buildsStringOfStatistics();
    //+++++++  the Back Image  +++++ 
    m_BackText.loadFromFile("goback.png");
    m_BackSprite.setTexture(m_BackText);
    m_BackSprite.setPosition({ 30, 500 });
    //+++++++  the Background Image  +++++ 
    m_BackgroundText.loadFromFile("background_statistic.png");
    m_BackgroundSprite.setTexture(m_BackgroundText);
    m_BackgroundSprite.setPosition({ 0, 0 });
}

Statistic::~Statistic()
{}

void Statistic::showFileStatistic()
{  
    while (m_Window.isOpen())
    {
        draw();

        if (auto event = sf::Event{}; m_Window.waitEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
            case sf::Event::LostFocus:
                m_Window.close();
                return;
            case sf::Event::MouseButtonPressed:
            {
                auto position = m_Window.mapPixelToCoords(
                    { event.mouseButton.x, event.mouseButton.y });

                if (m_BackSprite.getGlobalBounds().contains(position))
                {
                    m_Window.close();
                    return;
                }
            }
        }
    }
}
}

void Statistic::readFileStatistic()
{
    std::ifstream ifs;
    std::string line;

    ifs.open(FILE_STATISTIC);
    if (!ifs.is_open()) {
        std::cout << "error file is not opne!!";
    }

    while (ifs.good()) {
        std::getline(ifs, line);
        m_vecInitStatistic.push_back(line);
    }
    
    ifs.close();
}


void Statistic::buildsStringOfStatistics()
{
    std::string levelNum, scoreNum;
    std::istringstream istr;
    std::string strAll = { "" };

    for (int i = 0; i < m_vecInitStatistic.size(); i++)
    {
        istr = std::istringstream(m_vecInitStatistic[i]);
        istr >> levelNum >> scoreNum;

        if (levelNum.size() == 1)
            strAll = STRLEVEL + levelNum + SPACE + STRSCORS + scoreNum;
        else
            strAll = STRLEVEL + levelNum + STRSCORS + scoreNum;

        m_vecInitStatistic[i] = (strAll);
    }

    createsVecOfStatistics();
}

void Statistic::createsVecOfStatistics()
{
    sf::Text text;
    float yPosition;
    for (int i = 0; i < m_vecInitStatistic.size(); i++)
    {
        text = sf::Text(m_vecInitStatistic[i], m_Font);
        text.setFillColor(sf::Color::Black);
        yPosition = 170 + 40 * float(i);
        text.setPosition({ 260, yPosition });
        m_vecStatistic.push_back(text);
    }
}


void Statistic::draw()
{
    m_Window.clear(sf::Color::Cyan);
    
    m_Window.draw(m_BackgroundSprite);
    m_Window.draw(m_textTitle);
    m_Window.draw(m_BackSprite);
    for (auto& i : m_vecStatistic)
    {
        m_Window.draw(i);
    }

    m_Window.display();
}
