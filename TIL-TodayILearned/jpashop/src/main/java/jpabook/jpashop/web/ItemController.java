package jpabook.jpashop.web;

import jpabook.jpashop.domain.item.Book;
import jpabook.jpashop.domain.item.Item;
import jpabook.jpashop.service.ItemService1;
import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;

import java.util.List;

@Controller
@RequiredArgsConstructor
public class ItemController {

    private final ItemService1 itemService1;

    @GetMapping(value = "/items/new")
    public String createForm(Model model) {

        model.addAttribute("form", new BookForm1());
        return "items/createItemForm";
    }

    @PostMapping(value = "/items/new")
    public String create(BookForm1 form1) {

        Book book = new Book();
        book.setName(form1.getName());
        book.setPrice(form1.getPrice());
        book.setStockQuantity(form1.getStockQuantity());
        book.setAuthor(form1.getAuthor());
        book.setIsbn(form1.getIsbn());

        itemService1.saveItem(book);
        return "redirect:/items";
    }

    /*
    Product list
     */
    @GetMapping(value = "/items")
    public String list(Model model) {

        List<Item> items = itemService1.findItems();
        model.addAttribute("items", items);
        return "items/itemList";
    }

    /*
    Product modify form
     */
    @GetMapping(value = "/items/{itemId}/edit")
    public String updateItemForm(@PathVariable("itemId") Long itemId, Model model) {

        Book item = (Book) itemService1.findOne(itemId);

        BookForm1 form1 = new BookForm1();
        form1.setId(item.getId());
        form1.setName(item.getName());
        form1.setPrice(item.getPrice());
        form1.setStockQuantity(item.getStockQuantity());
        form1.setAuthor(item.getAuthor());
        form1.setIsbn(item.getIsbn());

        model.addAttribute("form1", form1);
        return "items/updateItemForm";
    }

    @PostMapping(value = "/items/{itemId}/edit")
    public String updateItem(@ModelAttribute("form1") BookForm1 form1) {
        itemService1.updateItem(form1.getId(), form1.getName(), form1.getPrice());
        return "redirect:/items";
    }

}
