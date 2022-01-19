#pragma once

#include "bclib/bstrlib.h"

typedef struct FileReaderInputCfg {
  bstring pattern;
  int read_size;
  int thread_sleep;
} FileReaderInputCfg;

typedef struct StretcherInputCfg {
  double stretch;
  int window_size;
  int thread_sleep;
} StretcherInputCfg;

typedef struct EncoderInputCfg {
  int samplerate;
  int thread_sleep;
  double quality;
} EncoderInputCfg;

typedef struct BroadcastInputCfg {
  bstring host;
  int port;
  bstring source;
  bstring password;
  bstring mount;
  bstring name;
  bstring description;
  bstring genre;
  bstring url;
} BroadcastInputCfg;

typedef struct RadioInputCfg {

  int channels;
  int stats_interval;

  FileReaderInputCfg filereader;
  EncoderInputCfg encoder;
  BroadcastInputCfg broadcast;

} RadioInputCfg;

RadioInputCfg *read_config(char *config_path);

void destroy_config(RadioInputCfg *cfg);