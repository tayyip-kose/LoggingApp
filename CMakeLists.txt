cmake_minimum_required(VERSION 3.16)

project(LogApp LANGUAGES CXX)

# Otomatik Qt entegrasyonu için ayarlar
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Qt5 veya Qt6 için Core bileşenini buluyoruz
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

# Projeyi derlemek için hedef dosyaları tanımlıyoruz
add_executable(LogApp
  main.cpp
  logging.h
  logging.cpp
)

# Projeyi Qt Core bileşeni ile bağlantılıyoruz
target_link_libraries(LogApp Qt${QT_VERSION_MAJOR}::Core)

# Kurulum talimatları (bu kısmı isteğe bağlı)
include(GNUInstallDirs)
install(TARGETS LogApp
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
