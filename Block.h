class Block : public sf::Drawable
{
    public:
        double x,y;  // position in matrix

        //Constructors

        Block(double xx, double yy)
        {
            x=xx; y=yy;
            marker=sf::CircleShape(0.6);
            marker.setPosition(100*x,-100*y);
        }
        Block(){}

        // Methods
        void update(void)
        {
            marker.setPosition(100*x,-100*y);
        }

    private:
        sf::CircleShape marker;
    protected:
        void draw(sf::RenderTarget& target, sf::RenderStates state) const
        {
            target.draw(marker);
        }
};
