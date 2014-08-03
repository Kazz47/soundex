set(SOURCES
    soundex
)

include_directories(${INCLUDE_DIRS})

# add_library(soundex OBJECT ${SOURCES})
# add_library(soundex_static STATIC $<TARGET_OBJECTS:soundex>)
# add_library(soundex_shared SHARED $<TARGET_OBJECTS:soundex>)

add_library(soundex_static STATIC ${SOURCES})
add_library(soundex_shared SHARED ${SOURCES})