#include <SFML/Graphics.hpp>
#include "Form.h"

int main()
{
    std::string pathFont = "/usr/share/fonts/truetype/ubuntu/Ubuntu-M.ttf";
    sf::RenderWindow window(sf::VideoMode(600, 500), "Autoreload");
    window.setFramerateLimit(30);

    // left block
    Text inputWell("Input wells:", pathFont);
    inputWell.setPosition(sf::Vector2f(30, 30));

    ListText list(170, 350, 10);
    list.setPosition(sf::Vector2f(30, 60));

    // rigth block
    CheckBox editPz;
    editPz.setPosition(sf::Vector2f(270, 30));
    Text editPzTitle("Reload PZ coefficients", pathFont);
    editPzTitle.setPosition(sf::Vector2f(300, 30));

    CheckBox editRigis;
    editRigis.setPosition(sf::Vector2f(270, 70));
    Text editRigisTitle("Reload RIGIS", pathFont);
    editRigisTitle.setPosition(sf::Vector2f(300, 70));

    CheckBox editIndex;
    editIndex.setPosition(sf::Vector2f(270, 110));
    Text editIndexTitle("Reload Indexes", pathFont);
    editIndexTitle.setPosition(sf::Vector2f(300, 110));

    CheckBox editPerf;
    editPerf.setPosition(sf::Vector2f(270, 150));
    Text editPerfTitle("Reload Perforations", pathFont);
    editPerfTitle.setPosition(sf::Vector2f(300, 150));

    Text perfStartTitle("Input start Perforation:", pathFont);
    perfStartTitle.setPosition(sf::Vector2f(300, 190));
    TextEdit perfStart(50, pathFont);
    perfStart.setPosition(sf::Vector2f(480, 190));

    CheckBox editTest;
    editTest.setPosition(sf::Vector2f(270, 230));
    Text editTestTitle("Reload Tests", pathFont);
    editTestTitle.setPosition(sf::Vector2f(300, 230));

    Text testStartTitle("Input start Tests:", pathFont);
    testStartTitle.setPosition(sf::Vector2f(300, 270));
    TextEdit testStart(50, pathFont);
    testStart.setPosition(sf::Vector2f(480, 270));

    Text editCurveTitle("Reload Curves", pathFont);
    editCurveTitle.setPosition(sf::Vector2f(270, 310));

    CheckBox editKS;
    editKS.setPosition(sf::Vector2f(300, 340));
    Text editKSTitle("KS", pathFont);
    editKSTitle.setPosition(sf::Vector2f(330, 340));

    CheckBox editPS;
    editPS.setPosition(sf::Vector2f(300, 370));
    Text editPSTitle("PS", pathFont);
    editPSTitle.setPosition(sf::Vector2f(330, 370));

    CheckBox editDS;
    editDS.setPosition(sf::Vector2f(300, 400));
    Text editDSTitle("DS", pathFont);
    editDSTitle.setPosition(sf::Vector2f(330, 400));

    CheckBox editGK;
    editGK.setPosition(sf::Vector2f(400, 340));
    Text editGKTitle("GK", pathFont);
    editGKTitle.setPosition(sf::Vector2f(430, 340));

    CheckBox editNGK;
    editNGK.setPosition(sf::Vector2f(400, 370));
    Text editNGKTitle("NGK", pathFont);
    editNGKTitle.setPosition(sf::Vector2f(430, 370));

    CheckBox editBK;
    editBK.setPosition(sf::Vector2f(500, 340));
    Text editBKTitle("BK", pathFont);
    editBKTitle.setPosition(sf::Vector2f(530, 340));

    CheckBox editIK;
    editIK.setPosition(sf::Vector2f(500, 370));
    Text editIKTitle("IK", pathFont);
    editIKTitle.setPosition(sf::Vector2f(530, 370));

    Button startProcess("Start", pathFont);
    startProcess.setPosition(sf::Vector2f(480, 450));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            list.process(event);
            editPz.process(event);
            editRigis.process(event);
            editIndex.process(event);
            editPerf.process(event);
            perfStart.process(event);
            editTest.process(event);
            testStart.process(event);

            editKS.process(event);
            editPS.process(event);
            editDS.process(event);

            editGK.process(event);
            editNGK.process(event);

            editBK.process(event);
            editIK.process(event);

            startProcess.process(event);
        }

        window.clear(sf::Color::White);

        inputWell.render(window);
        list.render(window);
        editPz.render(window);
        editPzTitle.render(window);
        editRigis.render(window);
        editRigisTitle.render(window);
        editIndex.render(window);
        editIndexTitle.render(window);
        editPerf.render(window);
        editPerfTitle.render(window);
        perfStart.render(window);
        perfStartTitle.render(window);
        editTest.render(window);
        editTestTitle.render(window);
        testStart.render(window);
        testStartTitle.render(window);
        editCurveTitle.render(window);

        editKS.render(window);
        editKSTitle.render(window);
        editPS.render(window);
        editPSTitle.render(window);
        editDS.render(window);
        editDSTitle.render(window);

        editGK.render(window);
        editGKTitle.render(window);
        editNGK.render(window);
        editNGKTitle.render(window);

        editIK.render(window);
        editIKTitle.render(window);
        editBK.render(window);
        editBKTitle.render(window);

        startProcess.render(window);

        window.display();
    }

    return 0;
}
