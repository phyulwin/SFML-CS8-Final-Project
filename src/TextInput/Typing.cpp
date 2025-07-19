//
// Created by Kelly Lwin on 3/19/2023.
//

#include "Typing.h"

sf::Color Typing::getRandomColor() {
    srand((unsigned) time(NULL));
    int red = rand()%255, green = rand()%255, blue = rand()%255;
    sf::Color color(red, green, blue);
    return color;
}

Typing::Typing() {
    setupDefaultsVisuals();
    textedType.setString(textTypeStr);
}

bool Typing::empty() const {
    return text.empty();
}

int Typing::getCharSize() const {
    return text.getCharSize();
}

sf::Vector2f Typing::getPosition() const {
    return textedType.getPosition();
}

void Typing::changeFont() {
    Font::setRandomFont(font);
    textFont(font);
}

void Typing::changeTextColor() {
    textColor(getRandomColor());
}

void Typing::changeTextSize() {
    srand((unsigned) time(NULL));
    int randomCharSize = rand()%70;
    if(randomCharSize<20) {
        randomCharSize+=20;
    }
    textSize(randomCharSize);
}

void Typing::setCharSize(const int &size) {
    text.setCharSize(size);
}

void Typing::setPosition(const sf::Vector2f &pos) {
    text.setPosition(pos);
}

void Typing::setupDefaultsVisuals() {
    textColor(sf::Color::Black);
    textSize(charSize);
    font.loadFromFile("Fonts/monogram.ttf");
    textFont(font);
}

void Typing::textColor(const sf::Color &color) {
    this->textedType.setFillColor(color);
    this->text.setColor(color);
}

void Typing::textSize(const unsigned int &size) {
    this->textedType.setCharacterSize(size);
    this->text.setCharSize(size);
}

void Typing::textFont(const sf::Font &textFont) {
    this->textedType.setFont(font);
    this->text.setFont(font);
}

void Typing::update() {
    auto start = text.begin();
    auto end = text.begin();
    for (;end!= text.end();++ end)
    {
        if (end->getString() == ' ' || end->getString() == '.')
        {
            checkKeyword(start, end);
            start = end;
            ++start;
        }
    }
}

void Typing::changeColor(std::list<Letter>::iterator start, std::list<Letter>::iterator end, sf::Color color) {
    for(; start != end; ++start)
    {
        start->setFillColor(color);
    }
}

void Typing::checkKeyword(std::list<Letter>::iterator start, std::list<Letter>::iterator end) {
    auto start1 = start;
    auto end1 = end;
    std::string x ="";
    for(; start1 != end1; ++start1)
    {
        x += start1->getString();
        if(x == "float" || x == "int" || x == "char" || x =="string" || x == "double")
        {
            changeColor(start,end, sf::Color::Blue);
        }
        else if(isOperator(x[0]))
        {
            changeColor(start,end,sf::Color::Green);
        }
        else if(isNumber(x))
        {
            changeColor(start,end,sf::Color::Red);
        }
    }
}

bool Typing::isOperator(const char &element) {
    if((element >= 40 && element <= 47) || element == 94)
    {
        return true;
    }
    return false;
}

bool Typing::isNumber(const std::string &str) {
    for (int i = 0; i < str.size(); i++)
    {
        if(!isdigit(str[i]))
            return false;
        else
            return true;
    }
}

void Typing::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LControl) &&
            !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::RControl)) {
        //if the control keys are not pressed and text is entered
        if(event.type == sf::Event::TextEntered) {
            if (event.text.unicode)
            {
                text.addLetter(static_cast<char>(event.text.unicode));
                //cursor.setPosition({text.getPosition().x+text.getGlobalBounds().width, text.getPosition().y});
                getSnapshot();
            }

        }
    }
    //undo feature -> apply snap
    if (event.type == sf::Event::KeyPressed)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LControl) &&
            sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z)) {
            std::cout << "ctrl + z" << " ";
            applySnapshot();
        }
    }
    //backspace
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::BackSpace) && text.getSize() != 0) {
        text.backSpace();
    }
}


void Typing::applySnapshot() {
    text.letterList = snapshot.topHistory().list;
    snapshot.popHistory();
}

void Typing::getSnapshot() {
    //take a snap shot and push to stack
    TypingSnaps snap;
    snap.list = text.letterList;
    snapshot.pushHistory(snap);
}

void Typing::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    //window.draw(this->textedType);
    window.draw(this->text);
    //align window size and text size
}
