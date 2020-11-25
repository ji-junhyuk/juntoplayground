package hellospring.foundation.service;

import hellospring.foundation.domain.Order;

public interface OrderServiceInterface {
    Order createOrder(Long id, String itemName, int itemPrice);
}
