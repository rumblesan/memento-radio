
include_directories(include)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -std=c99 -D_POSIX_C_SOURCE=199309L")

set(SOURCE_HEADERS
  "include/api_process.h"
  "include/audio_buffer.h"
  "include/audio_synthesis_process.h"
  "include/broadcast_process.h"
  "include/config.h"
  "include/encoder_process.h"
  "include/file_utils.h"
  "include/filechunk.h"
  "include/logging.h"
  "include/messages.h"
  "include/ogg_encoder.h"
  "include/patch_chooser_process.h"
  "include/pipe_utils.h"
  )

set(SOURCES
  "src/api_process.c"
  "src/audio_buffer.c"
  "src/audio_synthesis_process.c"
  "src/broadcast_process.c"
  "src/config.c"
  "src/encoder_process.c"
  "src/file_utils.c"
  "src/filechunk.c"
  "src/messages.c"
  "src/ogg_encoder.c"
  "src/pipe_utils.c"
  "src/patch_chooser_process.c"
  )

add_library(libmemento ${SOURCES} ${SOURCE_HEADERS})

target_link_libraries(libmemento bclib)
target_link_libraries(libmemento ck)
target_link_libraries(libmemento shout m)
target_link_libraries(libmemento config)
target_link_libraries(libmemento vorbis vorbisfile ogg vorbisenc)
target_link_libraries(libmemento pthread)
target_link_libraries(libmemento pd)
target_link_libraries(libmemento lua5.4)
