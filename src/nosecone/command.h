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

#include <functional>
#include <map>
#include <vector>


namespace nosecone {


struct Command {
  std::string name;
  std::string description;
  std::string help_text;
  std::function<int(const std::vector<std::string>&)> entry_point;
};


struct Dispatch {
  std::map<std::string, Command> commands{};

  void register_command(const Command& command) {
    commands[command.name] = command;
  }

  int run(const std::string& command_name, const std::vector<std::string>& args) {
    const auto& command = commands[command_name];
    return command.entry_point(args);
  }
};


} // namespace nosecone
