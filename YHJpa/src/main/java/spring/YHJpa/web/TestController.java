package spring.YHJpa.web;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RequestParam;

@Controller
public class TestController {

    @RequestMapping("/index")
    public String index(Model model) {
        model.addAttribute("msg", "input your id.");

        return "index";
    }

    @RequestMapping(value = "/index", method = RequestMethod.POST)
    public String send(@RequestParam("id1") String id, Model model) {
        model.addAttribute("msg", "Hi." + id + "!!");
        model.addAttribute("id2", id);
        return "index";
    }
}
