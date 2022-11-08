
include_directories(include)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -std=c99 -D_POSIX_C_SOURCE=199309L")

set(SOURCES
  "src/audio_buffer.c"
  "src/audio_synthesis_process.c"
  "src/broadcast_process.c"
  "src/config.c"
  "src/encoder_process.c"
  "src/filechunk.c"
  "src/messages.c"
  "src/ogg_encoder.c"
  "src/pipe_utils.c"
  "src/file_utils.c"
  "src/patch_chooser_process.c"
  )

add_library(libmemento ${SOURCES})

target_link_libraries(libmemento bclib)
target_link_libraries(libmemento ck)
target_link_libraries(libmemento shout m)
target_link_libraries(libmemento config)
target_link_libraries(libmemento vorbis vorbisfile ogg vorbisenc)
target_link_libraries(libmemento pthread)
target_link_libraries(libmemento pd)
