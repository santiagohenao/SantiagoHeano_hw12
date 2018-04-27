sf::RenderWindow window(sf::VideoMode(400, 400), "Holololo");



sf::View view(sf::Vector2f(0, 0), sf::Vector2f(400, 400));

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
        view.move(10,0);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
        view.move(-10,0);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
    {
        view.move(0,-10);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
    {
        view.move(0,10);
    }

    //window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);
    window.clear();

    window.setView(view);

    // Calculation:

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
    {
        pause_status++;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
    {
        pause_status=0;
    }

    if(pause_status>0)
    {
        for(int i=1;i<(space.size()-1);i++)
        {
            space[i].y=-c*dt/dx*(-space[i-1].y+space[i].y)+space[i].y;
            space[i].update();
            tim+=dt;
        }
    }






    for(int i=0;i<space.size();i++)
    {
        window.draw(space[i]);
    }

    s=std::to_string(tim);
    atext.setString(s);

    window.draw(atext);

    window.display();

}
