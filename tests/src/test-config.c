#include "minunit.h"

#include "config.h"

char *test_config_read() {

  RadioInputCfg *cfg = NULL;
  cfg = read_config("../../cfg/radio.cfg.example");
  mu_assert(cfg != NULL, "Could not read config");

  mu_assert(list_count(cfg->puredata.search_paths) == 1,
            "did not get search paths list");

  destroy_config(cfg);
  return NULL;
}

char *all_tests() {
  mu_suite_start();

  mu_run_test(test_config_read);

  return NULL;
}

RUN_TESTS(all_tests);
