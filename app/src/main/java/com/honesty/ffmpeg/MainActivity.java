package com.honesty.ffmpeg;

import android.Manifest;
import android.support.v4.app.ActivityCompat;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.Surface;
import android.view.SurfaceHolder;
import android.view.SurfaceView;
import android.view.View;
import android.widget.TextView;

import java.io.File;

public class MainActivity extends AppCompatActivity implements SurfaceHolder.Callback {
    TextView tv;
    SurfaceView surfaceView;

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("avcodec-58");
        System.loadLibrary("avfilter-7");
        System.loadLibrary("avformat-58");
        System.loadLibrary("avutil-56");
        System.loadLibrary("swresample-3");
        System.loadLibrary("swscale-5");
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        ActivityCompat.requestPermissions(MainActivity.this, new String[]{Manifest.permission.READ_EXTERNAL_STORAGE}, 1);

        surfaceView = findViewById(R.id.surfaceView);
        surfaceView.getHolder().addCallback(this);

        findViewById(R.id.btPlay).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String path = "/storage/emulated/0/video/12_运动.mp4";
                if (new File(path).exists()) {
                    play(surfaceView.getHolder().getSurface(), path);
                } else {
                    System.out.println("文件不存在");
                }
            }
        });

        System.out.println("========================================");
        System.out.println(stringFromJNI());
        System.out.println("========================================");
        System.out.println(urlprotocolinfo());
        System.out.println("========================================");
        System.out.println(avformatinfo());
        System.out.println("========================================");
        System.out.println(avfilterinfo());
        System.out.println("========================================");
    }

    public native String stringFromJNI();
    public native String urlprotocolinfo();
    public native String avformatinfo();
    public native String avfilterinfo();


    public native int play(Surface surfaceView, String url);
//    public native void decode(String input, String output);

    @Override
    public void surfaceCreated(SurfaceHolder holder) {
        System.out.println("surfaceCreated");
    }

    @Override
    public void surfaceChanged(SurfaceHolder holder, int format, int width, int height) {

    }

    @Override
    public void surfaceDestroyed(SurfaceHolder holder) {

    }
}
