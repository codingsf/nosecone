// Copyright 2015 Charles D. Aylward
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// A (possibly updated) copy of of this software is available at
// https://github.com/cdaylward/nosecone

#pragma once

#include "nosecone/command.h"


namespace nosecone {
namespace command {


int perform_run(const Arguments& args);


const Command run{
  "run",
  "Execute an app container. Fetches images as required.",
  "Usage: run [flags] <app name> [<label name>:<label value> ...]\n\n"
  "Flags:\n"
  "  -wait   - Wait for the container to terminate.\n"
  "  -stdout - Dump container's pseudo-terminal to STDOUT (implies -wait)\n\n"
  "Terminating nscn when waiting (Ctrl-C with -wait or -stdout) does not affect the container.\n"
  "version, os, and arch labels default to 1.0.0, linux, and amd64 respectively.",
  perform_run
};


} // namespace command
} // namespace nosecone
