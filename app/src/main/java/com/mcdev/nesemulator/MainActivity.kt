
package com.mcdev.nesemulator

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import com.mcdev.nesemulator.databinding.ActivityMainBinding
import androidx.activity.viewModels
import androidx.lifecycle.Observer

import com.mcdev.nesemulator.viewmodel.LogViewModel

public class MainActivity : AppCompatActivity() {
    private val logViewModel by viewModels<LogViewModel>()
    private var _binding: ActivityMainBinding? = null
    
    private val binding: ActivityMainBinding
      get() = checkNotNull(_binding) { "Activity has been destroyed" }
    
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        // Inflate and get instance of binding
        _binding = ActivityMainBinding.inflate(layoutInflater)

        // set content view to binding's root
        setContentView(binding.root)
        
        logViewModel.logs.observe(this, Observer { logs ->
            binding.tvLogs.text = logs
        })
    }
    
    override fun onDestroy() {
        super.onDestroy()
        _binding = null
    }
}
