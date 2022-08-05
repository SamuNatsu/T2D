#include "T2D.hpp"

sf::RenderWindow win;
sf::Event e;

t2d::GameObject box;

class TR: public t2d::TriggerBox {
public:
    virtual void onEnter(t2d::GameObject& _o) {
        printf("UUID: %llu entered\n", _o.UUID);
    }
    virtual void onTrigger(t2d::GameObject& _o) {
        printf("UUID: %llu triggered\n", _o.UUID);
    }
    virtual void onExit(t2d::GameObject& _o) {
        printf("UUID: %llu exited\n", _o.UUID);
    }

} tri;

int main() {
    box.rigid.setSize(100, 100);
    box.rigid.setPosition(100, 100);

    tri.setSize(200, 200);
    tri.setPosition(500, 500);

    win.create(sf::VideoMode(800, 600), "test");
    win.setFramerateLimit(60);

    std::shared_ptr<t2d::GameObject> pbox;
    pbox.reset(&box);

    while (win.isOpen()) {
        while (win.pollEvent(e)) {
            if (e.type == e.Closed) {
                win.close();
                break;
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            box.rigid.translateXY(0.0, -1.0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            box.rigid.translateXY(1.0, 0.0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            box.rigid.translateXY(0.0, 1.0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            box.rigid.translateXY(-1.0, 0.0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            box.rigid.translateA(0.05);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
            box.rigid.translateA(-0.05);

        tri.test(pbox);
        tri.update();

        win.clear();
        box.rigid.debugDraw(win);
        tri.debugDraw(win);
        win.display();
    }

    return 0;
}
