cmake_minimum_required(VERSION 3.0)	# ѕроверка версии CMake.
									# ≈сли верси€ установленой программы
									# старее указаной, произайдЄт аварийный выход.
project(CollectionAndIteratonLibs)	# »м€ проекта

set(CMAKE_C_COMPILER "C:/Program Files (x86)/Microsoft Visual Studio 14.0/VC/vcvarsall.bat")	#ибо не находит
set(CMAKE_CXX_COMPILER "C:/Program Files (x86)/Microsoft Visual Studio 14.0/VC/vcvarsall.bat")	#у теб€ возможно, будет другой путь

add_library(CycleList STATIC CycleList.h CycleList.cpp)

set(BOOST_ROOT D:/ProgramUtils/boost_1_62_0)	#обычно достаточно установаить только корень. 
												#√лавное - не забыть собрать boost на конкретной машине
set(Boost_USE_STATIC_LIBS ON)	#дл€ того, чтобы библиотеки были прилинкованны статически

find_package(Boost COMPONENTS chrono REQUIRED)	#пример подключени€ библиотеки через find

target_link_libraries(CycleList)	#пример подключени€ напр€мую

add_executable(bridge bridge.cpp)	# —оздает исполн€емый файл с именем main
									# из исходника main.cpp
