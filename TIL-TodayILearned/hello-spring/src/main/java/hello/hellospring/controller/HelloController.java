package hello.hellospring.controller;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.ResponseBody;

@Controller
public class HelloController {

    @GetMapping("hello-mvc")
    public String helloMVC(@RequestParam("name") String name, Model model) {
        model.addAttribute("name", name);
        return "hello-template";
    }

    @GetMapping
    public String hello(Model model) {
        model.addAttribute("data", "spring!!");
        return "hello";
    }

    static class Hello {
        @GetMapping("hello-api")
        @ResponseBody
        public Hello helloapi(@RequestParam("name") String name) {
            Hello hello = new Hello();
            hello.setName(name);
            return hello;
            System.out.println();
            System.out.println("hello = " + hello);
        }

        private String name;

        public String getName() {
            return name;
        }

        public void setName(String name) {
            this.name = name;
        }
    }

    @GetMapping("hello-string")
    @ResponseBody
    public String helloString(@RequestParam("name") String name) {
        return "hello " + name;
    }
}
