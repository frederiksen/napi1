#include <napi.h>
#include <iostream>
#include <fstream>

using namespace Napi;

std::ofstream myfile;

Napi::String Method(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  // Open a file, and don't close it
  myfile.open ("C:/Users/mfrederiksen/Desktop/example.txt");
  myfile << "Writing this to a file.\n";

  return Napi::String::New(env, "world");
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "Napi1"),
              Napi::Function::New(env, Method));
  return exports;
}

NODE_API_MODULE(addon, Init)
