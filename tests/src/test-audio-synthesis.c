#include "audio_synthesis_process.h"
#include "messages.h"
#include "minunit.h"
#include "pipe_utils.h"

#include <bclib/bstrlib.h>
#include <bclib/dbg.h>
#include <bclib/ringbuffer.h>

char *test_audio_synthesis_config_create() {
  bstring patch_directory = bfromcstr("/some/dir/here");
  bstring patch_file = bfromcstr("my_test_patch.pd");
  int samplerate = 44100;
  int channels = 2;
  int queue_size = 1024;
  int max_push_msgs = 10;
  int audio_synth_status;

  ck_ring_t *pipe_out = NULL;
  ck_ring_buffer_t *pipe_out_buffer = NULL;

  create_pipe(&pipe_out, &pipe_out_buffer, queue_size);

  AudioSynthesisProcessConfig *cfg = audio_synthesis_config_create(
      patch_directory, patch_file, samplerate, channels, max_push_msgs,
      &audio_synth_status, pipe_out, pipe_out_buffer);

  mu_assert(cfg != NULL, "Could not create audio synthesis process config");

  audio_synthesis_config_destroy(cfg);

  cleanup_pipe(pipe_out, pipe_out_buffer, "pipeout");
  return NULL;
}

char *all_tests() {
  mu_suite_start();

  mu_run_test(test_audio_synthesis_config_create);

  return NULL;
}

RUN_TESTS(all_tests);