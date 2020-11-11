package _11_11.java8;

public class Foo {

    public static void main(String[] args) {

        RunSomething runSomething = new RunSomething() {

            int baseNumber = 10;

            @Override
            public int doit(int number) {
                return number + baseNumber;
            }
        };
//        If necessary, functional programming is done within the allowable grammar. It may be okay to use it for convenience.
//        Lambda cannot be used when changing the state value. However, lambdas can be used when only referencing values that are outside
//        There is no side effect. (It does not change the value outside the function.)
//        There is no state. (Do not use values outside the function.)

/*
     RunSomething runSomething = (number) -> number + 10;

        RunSomething runSomething = (number) -> {
            return number + 10;
        };




        System.out.println(runSomething.doit(1));
        System.out.println(runSomething.doit(1));
        System.out.println(runSomething.doit(1));

        System.out.println(runSomething.doit(2));
        System.out.println(runSomething.doit(2));
        System.out.println(runSomething.doit(2));
*/

        /*
        If the value is not constant or is likely to change
        => Difficult to see as functional programming

        11 11 11 12 12 12
         */
    }
}



        //Prior to Java 8, anonymous inner class
/*
        RunSomething runSomething = () -> System.out.println("Hello");
        runSomething.doIt();
*/

    /*
        RunSomething runSomething = new RunSomething() {
            @Override
            public void doIt() {
                System.out.println("Hello");
            }
        };
    */

