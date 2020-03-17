cmake_minimum_required(VERSION 3.5)

project(qml-l10n-idbased-example LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Core Quick LinguistTools REQUIRED)

# Target for generation *.ts files
set(TS_FILES_GEN "l10n/${PROJECT_NAME}_en_GB.ts" "l10n/${PROJECT_NAME}_fr_FR.ts")
qt5_create_translation(null ${CMAKE_SOURCE_DIR} ${TS_FILES_GEN})

# Target to compile *.ts files into *.qm files with idbased strings
set(TS_FILES "l10n/${PROJECT_NAME}_en_GB.ts" "l10n/${PROJECT_NAME}_fr_FR.ts")
set_source_files_properties(${TS_FILES} PROPERTIES OUTPUT_LOCATION "l10n")
qt5_add_translation(QM_FILES ${TS_FILES} OPTIONS -idbased)

add_executable(${PROJECT_NAME}
  main.cpp
  qml.qrc
  ${QM_FILES}
)

target_compile_definitions(${PROJECT_NAME} PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Core Qt5::Quick)
