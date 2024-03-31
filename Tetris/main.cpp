//#include <SFML/Graphics.hpp>
#include "Game.h"

//using namespace sf;

int main()
{
    Game game;
    while (game.isOpenWindow()) 
    {
        game.update();
        game.show();
    }
    
    //Game game;
    //for (size_t i = 0; i < 3; i++) {
    //    game.update();
    //    game.show();
    //    game.moveFigureLeft();
    //    game.show();
    //}
    //for (size_t i = 0; i < 2; i++) {
    //    game.rotateFigure();
    //    game.show();
    //}


    //FigureGenerator generator;
    //PlayingField field;
    //Figure currentFigure({ {3, 0}, {4, 0}, {5, 0}, {6, 0} }, { 4, 0 });   //generator.getNewFigure();
    //Color color(0, 0, 0);
    //field.addNewFigureToTheField(currentFigure.getVectorCoordinates(), Color(0, 0, 0));
    //field.printField();
    //std::cout << "\n";
    //for (size_t i = 0; i < 3; i++) {
    //    std::vector<Coordinates> currentCoordinates = currentFigure.getVectorCoordinates();
    //    currentFigure.moveDown();
    //    std::vector<Coordinates> newCoordinates = currentFigure.getVectorCoordinates();
    //    field.updateFigureCoordinates(currentCoordinates, newCoordinates);
    //    field.printField();
    //    std::cout << "\n";
    //    currentCoordinates = currentFigure.getVectorCoordinates();
    //    currentFigure.moveLeft();
    //    newCoordinates = currentFigure.getVectorCoordinates();
    //    field.updateFigureCoordinates(currentCoordinates, newCoordinates);
    //    field.printField();
    //    std::cout << "\n";
    //}
    //for (size_t i = 0; i < 4; i++) {
    //    std::vector<Coordinates> currentCoordinates = currentFigure.getVectorCoordinates();
    //    currentFigure.rotate();
    //    std::vector<Coordinates> newCoordinates = currentFigure.getVectorCoordinates();
    //    field.updateFigureCoordinates(currentCoordinates, newCoordinates);
    //    field.printField();
    //    std::cout << "\n";
    //}
    
    
    //RenderWindow window(VideoMode(400, 400), L"Новый проект", Style::Default);
    //
    //window.setVerticalSyncEnabled(true);
    //
    //CircleShape shape(100.f, 3);
    //shape.setPosition(100, 100);
    //shape.setFillColor(Color::Magenta);
    
    //while (window.isOpen())
    //{
    //    Event event;
    //    while (window.pollEvent(event))
    //    {
    //        if (event.type == Event::Closed)
    //            window.close();
    //    }
    //
    //    window.clear(Color::Blue);
    //    window.draw(shape);
    //    window.display();
    //}
    return 0;
}