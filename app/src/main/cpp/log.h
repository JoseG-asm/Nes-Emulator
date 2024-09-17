#pragma once 

#include <jni.h>
#include <string>

namespace Jvm {
    JavaVM* jvm;
    JNIEnv* env;
    
    extern "C"
    JNIEXPORT jint JNICALL
    JNI_OnLoad(JavaVM* vm, void* reserved) {
        jvm = vm;
        return JNI_VERSION_1_6;
    }
}

void despathLog(const std::string log);
