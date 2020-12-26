package spring.YHBasic.service;

import spring.YHBasic.domain.Order;

public interface OrderService {

    Order createOrder(Long memberId, String itemName, int itemPrice);
}
