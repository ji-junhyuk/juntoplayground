package hello.YHBasic.service;

import hello.YHBasic.domain.Order;

public interface OrderService {

    Order createOrder(Long memberId, String itemName, int itemPrice);
}
