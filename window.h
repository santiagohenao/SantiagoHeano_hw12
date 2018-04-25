sf::RenderWindow window(sf::VideoMode(400, 400), "Holololo");

sf::View view(sf::FloatRect(-2,2,4,-4));

while (window.isOpen())
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {
        view.move(0.1,0);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
        view.move(-0.1,0);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
    {
        view.move(0,0.1);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
    {
        view.move(0,-0.1);
    }

    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);
    window.clear();

    window.setView(view);

    // Calculation:

    for(int i=1;i<(space.size()-1);i++)
    {
        space[i].y=-c*dt/dx*(-space[i-1].y+space[i].y)+space[i].y;
        space[i].update();
    }


    for(int i=0;i<space.size();i++)
    {
        window.draw(space[i]);
    }



    window.display();

}
