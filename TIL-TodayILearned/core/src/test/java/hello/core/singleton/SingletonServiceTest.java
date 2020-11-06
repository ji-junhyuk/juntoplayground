package hello.core.singleton;

import hello.core.AppConfig;
import org.assertj.core.api.Assertions;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;
import org.springframework.context.ApplicationContext;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;

import static org.junit.jupiter.api.Assertions.*;

class SingletonServiceTest {

    @Test
    @DisplayName("Using objects with singleton pattern applied")
    public void singletonServiceTest() {

//    I blocked the constructor as private. A compilation error occurs.
//    new SingletonService();

        //    One. Lookup: Returns the same object each time it is called
        SingletonService singletonService1 = SingletonService.getInstance();
        //    Two. Lookup: Returns the same object each time it is called
        SingletonService singletonService2 = SingletonService.getInstance();

        // Check if reference values are different
        System.out.println("singletonService1 =" + singletonService1);
        System.out.println("singletonService2 =" + singletonService2);

        Assertions.assertThat(singletonService1).isSameAs(singletonService2);
        singletonService1.logic();
    }
}

