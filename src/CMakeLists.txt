cmake_minimum_required(VERSION 3.7)
set(PROJECT_NAME SFML_template)

project(${PROJECT_NAME})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -static")

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp Wallpaper.h Background.cpp Background.h Icon.h FileTree/File.cpp FileTree/File.h FileTree/Folder.cpp FileTree/Folder.h
        TextInput/circle.h TextInput/Cursor.cpp TextInput/Cursor.h TextInput/History.cpp TextInput/History.h
        TextInput/Keyboard_Shortcut.cpp TextInput/Keyboard_Shortcut.h TextInput/Letter.h TextInput/MultiText.cpp
        TextInput/MultiText.h TextInput/TextBox.cpp TextInput/TextBox.h TextInput/TextInput.cpp TextInput/TextInput.h
        TextInput/Typing.cpp TextInput/Typing.h TextInput/TypingSnapshot.h
        States.h States.cpp Apps.h Notepad/Notepad.cpp Notepad/Notepad.h App_Window.cpp App_Window.h Font.h Apps.cpp
        Interface.cpp Interface.h HelperClass.h MenuBar/Dropdown_Menu.cpp MenuBar/Dropdown_Menu.h
        MenuBar/Font.h MenuBar/InputBox.cpp MenuBar/InputBox.h MenuBar/Item.cpp MenuBar/Item.h
        MenuBar/ItemList.cpp MenuBar/ItemList.h MenuBar/Menu.cpp MenuBar/Menu.h MenuBar/MenuBar.cpp MenuBar/MenuBar.h Notepad/NotepadInterface.cpp Notepad/NotepadInterface.h Computer/ComputerInterface.cpp Computer/ComputerInterface.h
        RecycleBin/RecycleBinInterface.cpp RecycleBin/RecycleBinInterface.h FileTree/FileIcons.h Computer/Computer.cpp Computer/Computer.h)

if (CMAKE_BUILD_TYPE STREQUAL "Release")
    add_executable(${PROJECT_NAME} WIN32 ${SOURCE_FILES} Wallpaper.h Background.cpp Background.h Icon.h FileTree/File.cpp FileTree/File.h FileTree/Folder.cpp FileTree/Folder.h
            TextInput/circle.h
            GUI_Component.cpp GUI_Component.h MouseEvents.cpp MouseEvents.h Snapshot.cpp Snapshot.h States.cpp States.h
            TextInput/Cursor.cpp TextInput/Cursor.h TextInput/History.cpp TextInput/History.h
            TextInput/Keyboard_Shortcut.cpp TextInput/Keyboard_Shortcut.h TextInput/Letter.h TextInput/MultiText.cpp TextInput/MultiText.h
            TextInput/TextBox.cpp TextInput/TextBox.h TextInput/TextInput.cpp TextInput/TextInput.h TextInput/Typing.cpp
            TextInput/Typing.h TextInput/TypingSnapshot.h Apps.h Notepad/Notepad.cpp Notepad/Notepad.h App_Window.cpp App_Window.h Font.h
            Apps.cpp Interface.cpp Interface.h HelperClass.h MenuBar/Dropdown_Menu.cpp MenuBar/Dropdown_Menu.h
            MenuBar/Font.h MenuBar/InputBox.cpp MenuBar/InputBox.h MenuBar/Item.cpp MenuBar/Item.h MenuBar/ItemList.cpp MenuBar/ItemList.h MenuBar/Menu.cpp MenuBar/Menu.h MenuBar/MenuBar.cpp MenuBar/MenuBar.h Notepad/NotepadInterface.cpp Notepad/NotepadInterface.h Computer/ComputerInterface.cpp Computer/ComputerInterface.h RecycleBin/RecycleBinInterface.cpp RecycleBin/RecycleBinInterface.h FileTree/FileIcons.h Computer/Computer.cpp Computer/Computer.h)
else ()
    add_executable(${PROJECT_NAME} ${SOURCE_FILES} Wallpaper.h Background.cpp Background.h Icon.h FileTree/File.cpp FileTree/File.h
            FileTree/Folder.cpp FileTree/Folder.h
            TextInput/circle.h TextInput/Cursor.cpp TextInput/Cursor.h TextInput/History.cpp TextInput/History.h
            TextInput/Keyboard_Shortcut.cpp TextInput/Keyboard_Shortcut.h TextInput/Letter.h TextInput/MultiText.cpp
            TextInput/MultiText.h TextInput/TextBox.cpp TextInput/TextBox.h TextInput/TextInput.cpp TextInput/TextInput.h
            TextInput/Typing.cpp TextInput/Typing.h TextInput/TypingSnapshot.h Apps.h Notepad/Notepad.cpp Notepad/Notepad.h
            App_Window.cpp App_Window.h Font.h Apps.cpp Interface.cpp Interface.h HelperClass.h MenuBar/Dropdown_Menu.cpp MenuBar/Dropdown_Menu.h MenuBar/Font.h MenuBar/InputBox.cpp MenuBar/InputBox.h MenuBar/Item.cpp MenuBar/Item.h MenuBar/ItemList.cpp MenuBar/ItemList.h MenuBar/Menu.cpp MenuBar/Menu.h MenuBar/MenuBar.cpp MenuBar/MenuBar.h Notepad/NotepadInterface.cpp Notepad/NotepadInterface.h Computer/ComputerInterface.cpp Computer/ComputerInterface.h RecycleBin/RecycleBinInterface.cpp RecycleBin/RecycleBinInterface.h FileTree/FileIcons.h Computer/Computer.cpp Computer/Computer.h)
endif ()

set(SFML_ROOT "C:/SFML-2.5.1")
set(SFML_STATIC_LIBRARIES TRUE)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
#set(SFML_DIR C:/SFML/SFML-2.5.1/lib/cmake/SFML)
find_package(SFML  REQUIRED COMPONENTS audio graphics window system)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif ()