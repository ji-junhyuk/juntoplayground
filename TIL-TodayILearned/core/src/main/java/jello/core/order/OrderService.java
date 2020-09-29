package jello.core.order;

public interface OrderService {
    Order createOrder(Long memberId, String name, int itemPrice);
}
