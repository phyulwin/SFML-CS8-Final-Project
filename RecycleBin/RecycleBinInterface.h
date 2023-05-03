//
// Created by Kelly Lwin on 4/28/2023.
//

#ifndef SFML_TEMPLATE_RECYCLEBININTERFACE_H
#define SFML_TEMPLATE_RECYCLEBININTERFACE_H
#include <map>

#include "../Apps.h"
#include "../App_Window.h"
//#include "../Notepad/Notepad.h"

#include "../MouseEvents.h"
#include "../HelperClass.h"
#include "../HelperClass.h"

#include "../FileTree/Folder.h"

class RecycleBinInterface: public sf::Drawable, public States {
private:
    void createApp();
    void setupButton();
    void reposition();
public:
    Apps recyclebin;
    Folder deletedFiles;
    Button recoverButton;

    Folder* recoverFile();
    void addDeletedFile(const File& file);

    RecycleBinInterface();
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //SFML_TEMPLATE_RECYCLEBININTERFACE_H
