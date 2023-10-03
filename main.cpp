#pragma once
#include <iostream>
#include "webhook.h"

bool replace(std::string& str, const std::string& from, const std::string& to) {
    size_t start_pos = str.find(from);
    if (start_pos == std::string::npos)
        return false;
    str.replace(start_pos, from.length(), to);
    return true;
}

int main() {
  printf("made by ProB1#0100\n");
  DWHook webhook;
  std::string text = webhook.normal;
  replace(text, "username123", "New Username");
  replace(text, "text", "New Text");
  webhook.send(text);
  std::string text2 = webhook.description;
  replace(text2, "username123", "New Username 2");
  replace(text2, "descriptiontitle", "New Description Title");
  replace(text2, "descriptiontext", "New Description Text");
  webhook.send(text2);
  printf("if you got error about sending webhook its your text issue need to work well\n");
  return 0;
}
