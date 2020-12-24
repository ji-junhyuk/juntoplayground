package spring.HH.controller;

import org.springframework.http.HttpStatus;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RequestMapping(value = "/api/group")
@RestController
public class GroupController {

    @GetMapping
    public List<Group> getAll() {
        return null;
    }

    @GetMapping("{id}")
    public Group getGroup(@PathVariable Long id) {
        return null;
    }

    @PostMapping
    @ResponseStatus(HttpStatus.CREATED)
    public void postGroup(@RequestBody Object groupDto) {
    }

    @PatchMapping("/{id}")
    public void modifyGroup(@PathVariable Long id, String description) {
    }

    @GetMapping("/{id}/people")
    public List<Person> getPeopleInGroup(@PathVariable Long id) {
        return null;
    }

    @PutMapping("/{id}/person/{personId}")
    public void putPersonInGroup(@PathVariable Long id, @PathVariable Long personId) {
    }
}
