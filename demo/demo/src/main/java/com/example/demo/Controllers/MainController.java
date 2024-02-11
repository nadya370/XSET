package com.example.demo.Controllers;

import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.*;

@RestController
@RequestMapping()
public class MainController {

    @GetMapping("/")
    public String home() {
        String text = "Главная страница";
        return text;
    }

    @GetMapping("/hello")
    public int BaseResponse(@RequestParam int num, @RequestBody int num2) {
        int i = num * num2;
        return i;
    }
}
