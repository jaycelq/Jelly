# =======================jelly library====================
set(PROJECT_JELLY_SRC_DIR "${PROJECT_SOURCE_DIR}/jelly")

file(GLOB_RECURSE JELLY_SRC_LIST
    RELATIVE "${PROJECT_JELLY_SRC_DIR}"
    *.h *.hpp *.cpp)

add_library(jelly ${JELLY_SRC_LIST})
