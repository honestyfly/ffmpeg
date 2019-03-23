//
// Created by 37127 on 2019/3/14.
//

#include <stdio.h>


#include "../../../libs/include/libavformat/avformat.h"
#include "../../../libs/include/libavfilter/avfilter.h"

//Log
#ifdef ANDROID
#include <jni.h>
#include <android/log.h>
#define LOGE(format, ...)  __android_log_print(ANDROID_LOG_ERROR, "(>_<)", format, ##__VA_ARGS__)
#else
#define LOGE(format, ...)  printf("(>_<) " format "\n", ##__VA_ARGS__)
#endif

//FIX
struct URLProtocol;
/**
 * com.leixiaohua1020.sffmpegandroidhelloworld.MainActivity.urlprotocolinfo()
 * Protocol Support Information
 */
JNIEXPORT jstring Java_com_cdrc_helloffmpeg_MainActivity_urlprotocolinfo(JNIEnv *env, jobject obj){

    char info[40000]={0};
    av_register_all();

    struct URLProtocol *pup = NULL;
    //Input
    struct URLProtocol **p_temp = &pup;
    avio_enum_protocols((void **)p_temp, 0);
    while ((*p_temp) != NULL){
        sprintf(info, "%s[In ][%10s]\n", info, avio_enum_protocols((void **)p_temp, 0));
    }
    pup = NULL;
    //Output
    avio_enum_protocols((void **)p_temp, 1);
    while ((*p_temp) != NULL){
        sprintf(info, "%s[Out][%10s]\n", info, avio_enum_protocols((void **)p_temp, 1));
    }

    //LOGE("%s", info);
    return (*env)->NewStringUTF(env, info);
}

/**
 * com.leixiaohua1020.sffmpegandroidhelloworld.MainActivity.avformatinfo()
 * AVFormat Support Information
 */
JNIEXPORT jstring Java_com_cdrc_helloffmpeg_MainActivity_avformatinfo(JNIEnv *env, jobject obj){

    char info[40000] = { 0 };

    av_register_all();

    AVInputFormat *if_temp = av_iformat_next(NULL);
    AVOutputFormat *of_temp = av_oformat_next(NULL);
    //Input
    while(if_temp!=NULL){
        sprintf(info, "%s[In ][%10s]\n", info, if_temp->name);
        if_temp=if_temp->next;
    }
    //Output
    while (of_temp != NULL){
        sprintf(info, "%s[Out][%10s]\n", info, of_temp->name);
        of_temp = of_temp->next;
    }
    //LOGE("%s", info);
    return (*env)->NewStringUTF(env, info);
}