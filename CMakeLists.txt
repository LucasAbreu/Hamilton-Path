cmake_minimum_required( VERSION 2.8 )
project( hamiltonPath )

#add_library( libAllSorts SHARED allSorts.c )

add_library( libHamiltonPath SHARED hamiltonPath.c )

add_executable( teste main.c )

target_link_libraries( teste libHamiltonPath )
