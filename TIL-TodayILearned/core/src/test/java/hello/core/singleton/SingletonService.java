package hello.core.singleton;

public class SingletonService {

    //1. Only one object is created in the static area.
    private static final SingletonService instance = new SingletonService();

    //2. If the object instance is needed by opening it as public, it is allowed to search only through this static method.
    public static SingletonService getInstance() {
        return instance;
    }

    //3. Declaring the constructor as private, preventing external object creation using the new keyword
    private SingletonService() {
    }

    public void logic() {
        System.out.println("Singleton object logic call");
    }
}
