cmake_minimum_required(VERSION 3.0)	# �������� ������ CMake.
									# ���� ������ ������������ ���������
									# ������ ��������, ��������� ��������� �����.
project(CollectionAndIteratonLibs)	# ��� �������

set(CMAKE_C_COMPILER "C:/Program Files (x86)/Microsoft Visual Studio 14.0/VC/vcvarsall.bat")	#��� �� �������
set(CMAKE_CXX_COMPILER "C:/Program Files (x86)/Microsoft Visual Studio 14.0/VC/vcvarsall.bat")	#� ���� ��������, ����� ������ ����

add_library(CycleList STATIC CycleList.h CycleList.cpp)

set(BOOST_ROOT D:/ProgramUtils/boost_1_62_0)	#������ ���������� ����������� ������ ������. 
												#������� - �� ������ ������� boost �� ���������� ������
set(Boost_USE_STATIC_LIBS ON)	#��� ����, ����� ���������� ���� ������������� ����������

find_package(Boost COMPONENTS chrono REQUIRED)	#������ ����������� ���������� ����� find

target_link_libraries(CycleList)	#������ ����������� ��������

add_executable(bridge bridge.cpp)	# ������� ����������� ���� � ������ main
									# �� ��������� main.cpp
