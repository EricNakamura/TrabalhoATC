# CMakeList.txt: projeto de CMake para TrabalhoPacMan, incluir origem e definir
# lógica específica a um projeto aqui.
#
cmake_minimum_required (VERSION 3.8)
project (TrabalhoPacMan)

# Habilite a Recarga Dinâmica para compiladores MSVC, se houver suporte.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()


# Adicione a origem ao executável deste projeto.
add_subdirectory(src)
add_subdirectory("include")
add_subdirectory("include/lib")

add_executable(TrabalhoPacMan "src/TrabalhoPacMan.cpp" "src/TrabalhoPacMan.h")

set(LIBRARY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(LIBRARY_BINARY_DIR ${CMAKE_SOURCE_DIR}/include/lib)

include_directories(${LIBRARY_INCLUDE_DIR})

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET TrabalhoPacMan PROPERTY CXX_STANDARD 20)
endif()


target_include_directories(TrabalhoPacMan PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(TrabalhoPacMan PUBLIC ${LIBRARY_BINARY_DIR}/pdcurses.lib)

# TODO: Adicione testes e instale destinos, se necessário.
