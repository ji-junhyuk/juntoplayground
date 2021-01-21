package spring.YHBasic.domain;

import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.ToString;

@Getter
@AllArgsConstructor
@ToString
public class Order {

    private Long memberId;
    private String itemName;
    private int itemPrice;
    private int discountPrice;
}
