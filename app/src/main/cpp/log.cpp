
#include "log.h"

void despathLog(const std::string log) {
    
    Jvm::jvm->AttachCurrentThread(&Jvm::env, nullptr);

    jclass clazz = Jvm::env->FindClass("com/mcdev/nesemulator/viewmodel/LogViewModel"); // Mude para o nome do seu pacote

    if (clazz == nullptr) {
        return;
    }

    jmethodID methodId = Jvm::env->GetStaticMethodID(clazz, "updateLogs", "(Ljava/lang/String;)V");
 
    if (methodId == nullptr) {
        return;
    }

    jstring jMessage =  Jvm::env->NewStringUTF(log.c_str());

    Jvm::env->CallStaticVoidMethod(clazz, methodId, jMessage);

    Jvm::env->DeleteLocalRef(jMessage);

    Jvm::jvm->DetachCurrentThread();
}
