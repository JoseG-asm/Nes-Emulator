package com.mcdev.nesemulator

import android.app.Application
import android.content.Context
import java.io.File


/** 
 * @author Jose G. 
 */
class NesApplication : Application() {
    init {
        instance = this
    }
    
    companion object {
        lateinit var instance: NesApplication
            private set
            
        var context: Context? = null
            get() = instance.applicationContext
    }

    override fun onCreate() {
    super.onCreate()
        instance = this
        System.loadLibrary("nes")
    }
}
