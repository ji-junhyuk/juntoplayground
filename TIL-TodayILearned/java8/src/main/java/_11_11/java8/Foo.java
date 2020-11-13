package _11_11.java8;

import java.util.function.Function;

public class Foo {

    public static void main(String[] args) {
        Function<Integer, Integer> plus10 = (i) -> i + 10;
        Function<Integer, Integer> multiply2 = (i) -> i * 2;

        Function<Integer, Integer> multiply2AndPlus10 = plus10.compose(multiply2);
        plus10.andThen(multiply2);
    }
}
/*
        Plus10 plus10 = new Plus10();
        System.out.println(plus10.apply(10));
*/