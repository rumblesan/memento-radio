#include "audio_buffer.h"
#include "broadcast_process.h"
#include "minunit.h"
#include "pipe_utils.h"

#include <bclib/bstrlib.h>
#include <bclib/dbg.h>
#include <ck_ring.h>

char *test_broadcast_config_create() {
  bstring host = bfromcstr("host");
  int port = 8080;
  bstring user = bfromcstr("user");
  bstring pass = bfromcstr("pass");
  bstring mount = bfromcstr("mount");
  bstring name = bfromcstr("name");
  bstring description = bfromcstr("description");
  bstring genre = bfromcstr("genre");
  bstring url = bfromcstr("url");
  int protocol = 1337;
  int format = 1;

  int queue_size = 1024;
  int broadcast_status;

  ck_ring_t *pipe_in = NULL;
  ck_ring_buffer_t *pipe_in_buffer = NULL;

  create_pipe(&pipe_in, &pipe_in_buffer, queue_size);

  BroadcastProcessConfig *cfg = broadcast_config_create(
      host, port, user, pass, mount, name, description, genre, url, protocol,
      format, &broadcast_status, pipe_in, pipe_in_buffer);

  mu_assert(cfg != NULL, "Could not create broadcast process config");

  broadcast_config_destroy(cfg);
  cleanup_pipe(pipe_in, pipe_in_buffer, "PipeIn");
  return NULL;
}

char *all_tests() {
  mu_suite_start();

  mu_run_test(test_broadcast_config_create);

  return NULL;
}

RUN_TESTS(all_tests);
