package hellospring.foundation.domain;

import lombok.Getter;
import lombok.Setter;

@Getter @Setter
public class Order {

    private Long id;
    private String itemName;
    private int itemPrice;
    private int discountPrice;

    public Order(Long id, String itemName, int itemPrice, int discountPrice) {
        this.id = id;
        this.itemName = itemName;
        this.itemPrice = itemPrice;
        this.discountPrice = discountPrice;
    }

    public int calculatePrice() {
        return itemPrice - discountPrice;
    }

    @Override
    public String toString() {
        return "Order{" +
                "id=" + id +
                ", itemName='" + itemName + '\'' +
                ", itemPrice=" + itemPrice +
                ", discountPrice=" + discountPrice +
                '}';
    }
}
