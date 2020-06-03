project(RAYTRACE)

set(VECTOR_SRC main.cpp)
set(VECTOR_HDR classes.h game_options.h gameplay.h global_header.h menu.h prints.h screen_func.h structs.h syst_opt.h vectors.h)

#add_executable(${PROJECT_NAME} ${SRC_LIST})
#add_library(vector STATIC ${VECTOR_SRC} ${VECTOR_HDR})
add_executable(${PROJECT_NAME} ${VECTOR_SRC} ${VECTOR_HDR})