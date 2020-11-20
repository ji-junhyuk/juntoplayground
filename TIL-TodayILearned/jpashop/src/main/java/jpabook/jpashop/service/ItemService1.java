package jpabook.jpashop.service;

import jpabook.jpashop.domain.item.Item;
import jpabook.jpashop.repository.ItemRepository1;
import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import java.util.List;

@Service
@Transactional(readOnly = true)
@RequiredArgsConstructor
public class ItemService1 {

    private final ItemRepository1 itemRepository1;

    @Transactional
    public void saveItem(Item item) {
        itemRepository1.save(item);
    }

    public List<Item> findItems() {
        return itemRepository1.findAll();
    }

    public Item findOne(Long itemId) {
        return itemRepository1.findOne(itemId);
    }
}
