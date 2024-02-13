cmake_minimum_required(VERSION 3.16)
project(mdiwithstacked VERSION 1.0 LANGUAGES C CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Gui Widgets)

qt_standard_project_setup()

qt_add_executable(mdiwithstacked WIN32 MACOSX_BUNDLE
    form1.cpp form1.h form1.ui
    form2.cpp form2.h form2.ui
    form3.cpp form3.h form3.ui
    form4.cpp form4.h form4.ui
    form5.cpp form5.h form5.ui
    main.cpp
    mainwindow.cpp mainwindow.h mainwindow.ui
    form6.h form6.cpp form6.ui
)

target_link_libraries(mdiwithstacked PRIVATE
    Qt::Core
    Qt::Gui
    Qt::Widgets
)

install(TARGETS mdiwithstacked
    BUNDLE DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

qt_generate_deploy_app_script(
    TARGET mdiwithstacked
    FILENAME_VARIABLE deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
