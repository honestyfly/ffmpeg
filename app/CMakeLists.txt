
cmake_minimum_required(VERSION 3.4.1)

include_directories(src/main/cpp/includes)

add_library( # Sets the name of the library.
        native-lib

        # Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
        src/main/cpp/native-lib.cpp
        #src/main/cpp/simplest_ffmpeg_helloworld.c
        )

add_library( avcodec-58 SHARED IMPORTED)
set_target_properties( avcodec-58
        PROPERTIES IMPORTED_LOCATION
        ${CMAKE_SOURCE_DIR}/src/main/jniLibs/${ANDROID_ABI}/libavcodec-58.so)


add_library( avfilter-7 SHARED IMPORTED)
set_target_properties( avfilter-7
        PROPERTIES IMPORTED_LOCATION
        ${CMAKE_SOURCE_DIR}/src/main/jniLibs/${ANDROID_ABI}/libavfilter-7.so)


add_library( avformat-58 SHARED IMPORTED)
set_target_properties( avformat-58
        PROPERTIES IMPORTED_LOCATION
        ${CMAKE_SOURCE_DIR}/src/main/jniLibs/${ANDROID_ABI}/libavformat-58.so)


add_library( avutil-56 SHARED IMPORTED)
set_target_properties( avutil-56
        PROPERTIES IMPORTED_LOCATION
        ${CMAKE_SOURCE_DIR}/src/main/jniLibs/${ANDROID_ABI}/libavutil-56.so)

add_library( swresample-3 SHARED IMPORTED)
set_target_properties( swresample-3
        PROPERTIES IMPORTED_LOCATION
        ${CMAKE_SOURCE_DIR}/src/main/jniLibs/${ANDROID_ABI}/libswresample-3.so)


add_library( swscale-5 SHARED IMPORTED)
set_target_properties( swscale-5
        PROPERTIES IMPORTED_LOCATION
        ${CMAKE_SOURCE_DIR}/src/main/jniLibs/${ANDROID_ABI}/libswscale-5.so)


target_link_libraries( # Specifies the target library.
        native-lib
        avcodec-58
        avformat-58
        avfilter-7
        avutil-56
        swresample-3
        swscale-5
        android
        log)