package hello.core.singleton;

public class SingletonService {

    //Only one object is created in the static area
    private static final SingletonService instance = new SingletonService();

    //Open as public and allow object instances
    //to be retrieved only through this static method if necessary.
    public static SingletonService getInstance() {
        return instance;
    }

    //Declaring the constructor
    //as private to prevent external object creation using the new keyword

    public SingletonService() {
    }

    public void logic() {
        System.out.println("Singleton object logic call");
    }
}
