package com.mcdev.nesemulator.viewmodel;

import androidx.lifecycle.MutableLiveData
import androidx.lifecycle.ViewModel
import androidx.lifecycle.LiveData
import androidx.lifecycle.LifecycleOwner
import android.content.Intent
import android.content.Context

class LogViewModel : ViewModel() {
    private var _logs = MutableLiveData<String>()
    val logs: LiveData<String>
        get() = _logs
        
    fun updateLogs(log: String) {
        var currentLogs = _logs.value ?: " "
        
        _logs.value = currentLogs + log
    }
}
