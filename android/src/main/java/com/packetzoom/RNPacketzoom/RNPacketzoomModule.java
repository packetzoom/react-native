package com.packetzoom.RNPacketzoom;

import android.support.annotation.Nullable;

import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.modules.network.OkHttpClientProvider;
import com.facebook.react.bridge.ReactMethod;

import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

import okhttp3.Interceptor;
import okhttp3.OkHttpClient;
import okhttp3.Request;
import okhttp3.Response;


import com.packetzoom.speed.PacketZoomClient;
import com.packetzoom.okhttp3.PacketZoomInterceptor;

/**
 * Created by bexp on 10/23/16.
 */

public class RNPacketzoomModule extends ReactContextBaseJavaModule {
    ReactApplicationContext reactContext;

    public RNPacketzoomModule(ReactApplicationContext reactContext) {
        super(reactContext);
        this.reactContext = reactContext;

        OkHttpClient client = OkHttpClientProvider.getOkHttpClient();
        OkHttpClient replacementClient = client
                .newBuilder()
                .addInterceptor(new PacketZoomInterceptor())
                .build();
        OkHttpClientProvider.replaceOkHttpClient(replacementClient);
    }

    @ReactMethod
    public void init(String appId, String apiKey) {
        PacketZoomClient.init(reactContext, appId, apiKey);
    }

    @Override
    public String getName() {
        return "RNPacketzoom";
    }

    @Override
    public @Nullable Map<String, Object> getConstants() {
        HashMap<String, Object> constants = new HashMap<String, Object>();

        constants.put("version", "1");

        return constants;
    }
}