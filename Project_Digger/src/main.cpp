#include <thread>
#include <Controller.h>

int main()
{
    Controller().run();
}

//    using namespace std::chrono_literals;
//    std::this_thread::sleep_for(30s); // 30 seconds

/* // Create the window of the application
    sf::RenderWindow window(sf::VideoMode(500, 500), "SFML Pong");

    int speed = 100;
    const sf::Time AITime = sf::seconds(0.1f);
    sf::Clock clock;
    sf::Clock clock1;
    clock.restart();

    Resources res{};
    //create digger & monster

    sf::Sprite digger_sprite(res.get_digger_texture());
    digger_sprite.setPosition(0, 100);
    digger_sprite.scale(0.07, 0.07);


    sf::Sprite monster_sprite(res.get_monster_texture());
    monster_sprite.setPosition(0, 300);
    monster_sprite.scale(0.1, 0.1);

    clock.restart();
    while (window.isOpen())
    {
        window.clear();
        window.draw(digger_sprite);
        window.draw(monster_sprite);
        window.display();



        //digger_sprite.move();
        // Handle events
        sf::Event event;
        if(window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;

            case sf::Event::KeyPressed:
                switch (event.key.code)
                {

                case sf::Keyboard::Escape:
                    window.close();
                    break;

                case sf::Keyboard::Up:
                    digger_sprite.move(0, -speed * t);
                    break;

                case sf::Keyboard::Down:
                    digger_sprite.move(0, speed * t);
                    break;

                case sf::Keyboard::Right:
                    digger_sprite.move(speed * t, 0);
                    break;

                case sf::Keyboard::Left:
                    digger_sprite.move(-speed * t, 0);
                    break;


                }


            }

        }

        float t = clock.restart().asSeconds();
        monster_sprite.move(speed * t, 0);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            digger_sprite.move(0, -speed * t);
        }
        else
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            digger_sprite.move(0, speed * t);
        }
        else
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            digger_sprite.move(speed * t, 0);
        }
        else
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            digger_sprite.move(-speed * t, 0);
        }
    }*/